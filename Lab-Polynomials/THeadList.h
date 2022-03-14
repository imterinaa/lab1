#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList();
	~THeadList();
	void InsFirst(T item);
	void DelFirst();
};

template<class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	pFirst = pLast = pPrev = pCurr = pStop = pHead;
	length = 0;
}

template<class T>
THeadList<T>::~THeadList()
{
	TList<T>::~TList();
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(T item)
{
	TList<T>::InsFirst(item);
	pHead->pNext = pFirst;
}

template <class T>
void THeadList<T>::DelFirst()
{
	TList<T>::DelFirst();
	pHead->pNext = pFirst;
}