#ifndef SL_H
#define S_H

#include <iostream>
#include <cstring>
using namespace std;

//   Creating a NODE Structure
template <class T>
struct node
{
    int data;
    struct node *next;
};

// Creating a class STACK
template <class T>
class Stack
{
private:
    struct node *top;
public:
    template <class T>
	Stack(int n = 10);
	bool push (T data);
	bool pop(T &data);
	bool isFull();
	bool isEmpty();
	~Stack();
};

#endif
