#pragma once
#include <List.h>
#include <Exception.h>

template <class T>
class Stack_on_list : public List<T>
{
protected:
	int length;

public:
	Stack_on_list(int new_length = 10);
	Stack_on_list(Stack_on_list& stlst);
	T Pop();
	int GetSize();
	int GetLength();
	void Push(T elem);
	bool IsEmpty();
	bool IsFull();
	void Print();
};

template <class T>
Stack_on_list<T>::Stack_on_list(int new_length) : List<T>()
{
	if (new_length <= 0)
		throw Exception("Error length");
	length = new_length;
}

template <class T>
Stack_on_list<T>::Stack_on_list(Stack_on_list<T>& stlst) : List<T>(stlst)
{
	List<T>::count = stlst.count;
}

template <class T>
T Stack_on_list<T>::Pop()
{
	if (this->IsEmpty())
		throw Exception("Stack is empty");
	return List<T>::GetBegin();
}

template <class T>
int Stack_on_list<T>::GetSize()
{
	return length;
}

template<class T>
inline int Stack_on_list<T>::GetLength()
{
	return List<T>::count;
}

template <class T>
void Stack_on_list<T>::Push(T elem)
{
	if (this->IsFull())
		throw Exception("Stack is full");
	List<T>::PushBegin(elem);
}

template <class T>
bool Stack_on_list<T>::IsEmpty()
{
	if (List<T>::count == 0)
		return true;
	else
		return false;
}

template<class T>
bool Stack_on_list<T>::IsFull()
{
	if (List<T>::count == length)
		return true;
	else
		return false;
}

template<class T>
void Stack_on_list<T>::Print()
{
	if (this->IsEmpty())
		throw Exception("Stack is empty");
	List<T>::Print();
}
