#pragma once
#include <iostream>
#include"LineListItem.h"
template <class T> class LineListElem
{
private:
    T data;
    LineListElem* next;
public:
    LineListElem(const T& adata, LineListElem* anext);
    LineListElem();
    const T& getData() const;
    LineListElem* getNext();
    LineListElem<T>& operator=(const LineListElem<T>& other);
    template <class T> friend class LineList;
};

template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
{
    //
    data = adata;
    next = anext;

}

template<class T>LineListElem<T>::LineListElem()
{

}

template<class T> const T& LineListElem<T>::getData() const
{
    return data;
}

template <class T> LineListElem<T>* LineListElem<T>::getNext()
{
    return next;
}
