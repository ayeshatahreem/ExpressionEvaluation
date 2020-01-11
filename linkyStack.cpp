#include <iostream>
#include "linkyStack.h"
#include <cstring>

using namespace std;

//stack functions 

template <class T>
Stack<T>::Stack(int n)
{
top = -1;
max = n;
arr= new T[max];
}

template <class T>
bool Stack<T>::push (T data)
{
if(!isFull())
{
arr[++top] = data;
return true;
}
else
return false;
}

template <class T>
bool Stack<T>::pop(T &data)
{
if(!isEmpty())
{
data = arr[top--];
return true;
}
else
return false;
}

template <class T>
bool Stack<T>::isFull()
{
if(top == max-1)
return true;
else
return false;
}

template <class T>
bool Stack<T>::isEmpty()
{
if(top==-1)
return true;
else
return false;
}

template <class T>
Stack<T>:: ~Stack()
{
delete [] arr;
}
/*

template <class T>
Stack<T>::Stack(int n)
{
	top = -1;
	max = n;
	//arr= new T[max];
}

template <class T>
bool Stack<T>::push (T value)
{
	if(!isFull())
	{
		node<T> *newNode = new node<T>;		//pointer to create the node
		newNode->data = value;				//store new element in the node
		newNode->link = top;				//insert newNode before top
		return true;
	}
	else
		return false;
}

template <class T>
bool Stack<T>::pop(T &value)
{
	node<T> *temp;
	if(!isEmpty())
	{
		value = top->data;
		temp = top;
		top = top->link;
		delete temp;
		return true;
	}
	else
		return false;
}

template <class T>
bool Stack<T>::isFull()
{
	if(top == max-1)
		return true;
	else
		return false;
}

template <class T>
bool Stack<T>::isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}

template <class T>
Stack<T>:: ~Stack()
{
	node<T> *temp;
	while (top != -1)		//while there are elements in the stack
	{
		temp = top;			//set temp to point to the next node
		top = top ->link;   //advance stackTop to the next node
		delete temp;		//deallocate memory occupied by temp
	}
}*/