#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst, * pCurr, * pPrev, * pLast, * pStop;
	int length;
public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty();
	void InsFirst(T item);
	void InsCurr(T item);
	void InsLast(T item);
	void DelFirst();
	void DelCurr();

	void GoNext();
	void Reset();
	bool IsEnd();
	T GetCurr();
	void SetCurr(T item) { pCurr->val = item; }


};
template <class T>
TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pLast = pPrev = pCurr = pStop;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
	while (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template <class T>
bool TList<T>::IsEmpty()
{
	return pFirst == pStop;
}

template <class T>
void TList<T>::InsFirst(T item)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->val = item;
	newNode->pNext = pFirst;
	pFirst = newNode;
	length++;
	if (length == 1)
		pLast = pFirst;
}

template <class T>
void TList<T>::InsLast(T item)
{
	if (length > 0)
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->val = item;
		newNode->pNext = pStop;

		pLast->pNext = newNode;
		pLast = newNode;
		length++;
	}
	else
	{
		InsFirst(item);
	}
}

template <class T>
void TList<T>::InsCurr(T item)
{
	if (pCurr == pFirst)
		InsFirst(item);
	else if (pPrev == pLast)
		InsLast(item);
	else
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->val = item;

		newNode->pNext = pCurr;
		pPrev->pNext = newNode;
		pCurr = newNode;
		length++;
	}
}

template <class T>
void TList<T>::DelFirst()
{
	if (pFirst == pStop)
		throw "Can't delete element from empty list";

	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	length--;
}

template <class T>
void TList<T>::DelCurr()
{
	if (pCurr == pStop)
		throw "Can't delete element from empty list";

	if (pFirst == pCurr)
	{
		DelFirst();
	}
	else
	{
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPrev->pNext = pCurr;
		delete tmp;
		length--;
	}
}

template <class T>
T TList<T>::GetCurr()
{
	if (pCurr == pStop)
		throw "List is end";
	return pCurr->val;
}

template <class T>
void TList<T>::Reset()
{
	pPrev = pStop;
	pCurr = pFirst;
}

template <class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurr == pStop;
}





