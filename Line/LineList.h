#pragma once
#include <iostream>
using namespace std;
#include"LineList.h"
#include"LineListItem.h"
class LineListException {};
template <class T> class LineList {
	bool isCircular;
	LineListElem<T>* start;
	LineList(const LineList& list);
	LineList& operator =(const LineList& list);

public:
	LineList();
	~LineList();
	LineListElem<T>* getStart();

	void deleteFirst();
	void deleteAfter(LineListElem<T>* ptr);
	void insertFirst(const T& data);
	void insertAfter(LineListElem<T>* ptr, const T& data);
	void makeAnswer();
	template <class T> friend ostream& operator <<(ostream& out, LineList& list);
};

template <class T> void LineList<T>::deleteFirst()
{
	if (start)
	{
		LineListElem<T>* temp = start->next;
		delete start;
		start = temp;
	}
	else throw LineListException();
}


template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr) {
	if (ptr && ptr->next) {
		if (ptr->next == start)
		{
			LineListElem<T>* temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
			start = ptr->next;
		}
		else
		{
			LineListElem<T>* temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
		}
	}
	//
	else throw LineListException();
}
template <class T> LineList<T>::LineList()
{

	start = 0;
	isCircular = false;

}

template <class T> LineList<T>::~LineList()
{
	if (isCircular) {
		LineListElem<T>* current = start;
		while (current->next != start) {
			current = current->next;
		}
		current->next = nullptr;
	}
	while (start)
		deleteFirst();
}

template<class T> LineListElem<T>* LineList<T>::getStart()
{
	return start;
}


template <class T> void LineList<T>::insertFirst(const T& data)
{
	LineListElem<T>* second = start;
	start = new LineListElem<T>(data, second);
}

template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data) {
	if (ptr) {
		LineListElem<T>* temp = ptr->next;
		ptr->next = new LineListElem<T>(data, temp);
	}
}


template <class T> ostream& operator <<(ostream& out, LineList<T>& list)
{
	LineListElem<T>* ptr = list.getStart();
	if (!ptr)
		out << "EMPTY ";
	else do
	{
		out << ptr->getData() << ' ';
		ptr = ptr->getNext();
	} while (ptr && ptr != list.getStart());
	return out;
}
template <class T>void LineList<T>::makeAnswer() {
	if (start == nullptr) {
		return; // Если список пуст, то нет смысла делать его циклическим
	}

	LineListElem<T>* current = start;
	while (current->next != nullptr) {
		current = current->next;
	}

	current->next = start;
	isCircular = true;
}