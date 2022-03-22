#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>

const int nonDisplayedZeros = 4; 


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& m);

	TPolinom& operator=(TPolinom& m);

	void AddMonom(TMonom newMonom);
	TPolinom MultMonom(TMonom monom);

	TPolinom operator+(TPolinom& m);
	TPolinom add(TPolinom& m);
	TPolinom operator*(double coef);
	TPolinom operator* (TPolinom& m);
	bool operator==(TPolinom& m);

	friend istream& operator>>(istream& in, TPolinom& p) {
		TMonom m;
		in >> m;
		while (m.coef != 0) {
			p.AddMonom(m);
			in >> m;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, TPolinom& p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			if (p.pCurr->val.coef < 0 || p.pCurr == p.pFirst)
				out << p.pCurr->val;
			else
				out << " + " << p.pCurr->val;
		}
		return out;
	}
};

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{
	TMonom m;

	m.coef = 1;

	m.x = m.y = 0, m.z = -1;
	pHead->val = m;
}

TPolinom::TPolinom(TPolinom& m)
{
	TMonom mon(1, 0, 0, -1);
	pHead->val = mon;
	for (m.Reset(); !m.IsEnd(); m.GoNext())
	{
		InsLast(m.GetCurr());
	}
}


TPolinom& TPolinom::operator=(TPolinom& m)
{
	while (pFirst != pStop)
	{
		TNode<TMonom>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	pFirst = pLast = pPrev = pCurr = pStop = pHead;
	length = 0;

	for (m.Reset(); !m.IsEnd(); m.GoNext())
	{
		AddMonom(m.GetCurr());
	}
	return *this;
}

void TPolinom::AddMonom(TMonom m)
{
	Reset();
	while (m < pCurr->val)
	{
		GoNext();
	}
	if (pCurr->val == m)
	{
		pCurr->val.coef += m.coef;
		if (pCurr->val.coef == 0)
		{
			DelCurr();
		}
	}
	else
	{
		InsCurr(m);
	}
}

 TPolinom TPolinom::MultMonom(TMonom monom)
{
	TPolinom result;
	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom resultMonom = GetCurr();
		resultMonom.coef *= monom.coef;
		resultMonom.x += monom.x;
		resultMonom.y += monom.y;
		resultMonom.z += monom.z;
		result.AddMonom(resultMonom);
	}
	return result;
}
 
TPolinom TPolinom::operator+(TPolinom& m)
{
	TPolinom result(m);
	Reset(); result.Reset();

	while (!IsEnd())
	{
		if (result.pCurr->val > pCurr->val)
		{
			result.GoNext();
		}
		else if (result.pCurr->val < pCurr->val)
		{
			result.InsCurr(pCurr->val);
			GoNext();
		}
		else
		{
			result.pCurr->val.coef += pCurr->val.coef;
			if (result.pCurr->val.coef == 0)
			{
				result.DelCurr();
				GoNext();
			}
			else
			{
				result.GoNext();
				GoNext();
			}
		}
	}
	return result;
}

 /*TPolinom TPolinom::operator+(TPolinom& m)
 {
	 TPolinom res(*this);
	 TMonom vcurrres, vcurrpol;
	 res.Reset();
	 m.Reset();
	 while (!m.IsEnd())
	 {
		 vcurrres = res.pCurr->val;
		 vcurrpol = m.pCurr->val;
		 if (vcurrres > vcurrpol)
		 {
			 res.GoNext();
		 }
		 else if (vcurrres < vcurrpol)
		 {
			 InsCurr(vcurrpol);
			 m.GoNext();
		 }
		 else
		 {
			 res.pCurr->val.coef += m.pCurr->val.coef;
			 if (res.pCurr->val.coef != 0)
			 {
				 res.GoNext();
				 m.GoNext();

			 }
			 else
			 {
				 res.DelCurr();
				 m.GoNext();
			 }

		 }

	 }
	 return res;
 }*/



 TPolinom TPolinom::operator*(double coef)
{
	TPolinom result(*this);
	for (Reset(), result.Reset(); !IsEnd(); GoNext(), result.GoNext())
	{
		TMonom currentMonom = GetCurr();
		currentMonom.coef *= coef;
		result.SetCurr(currentMonom);
	}
	return result;
}

TPolinom TPolinom::operator*(TPolinom& m)
{
	TPolinom result;
	for (m.Reset(); !m.IsEnd(); m.GoNext())
		result = result.add(MultMonom(m.GetCurr()));
	return result;
}

 bool TPolinom::operator==(TPolinom& m)
{
	if (GetLength() != m.GetLength()) return false;
	for (Reset(), m.Reset(); !IsEnd(); GoNext(), m.GoNext())
		if (!GetCurr().EqualCoef(m.GetCurr())) return false;
	return true;
}










TPolinom TPolinom::add(TPolinom& m)
 {
	 TPolinom result(m);
	 for (Reset(); !IsEnd(); GoNext())
		 result.AddMonom(GetCurr());
	 return result;
 }


