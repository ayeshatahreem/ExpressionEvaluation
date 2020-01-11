#ifndef S_H
#define S_H

#include <iostream>
#include <cstring>

using namespace std;


// stack class of type template 
template <class T>
class Stack
{
private:
	int top;
	int max;
	T *arr;
public:
	Stack(int n = 10);
	bool push (T data);
	bool pop(T &data);
	bool isFull();
	bool isEmpty();
	~Stack();
};
#endif
/*
//definition of the node
template <class T>
struct node 
{
	T data;
	node<T> *link;
};
template <class T>
class Stack
{
private:
	node<T> *top;
	int max;
	//node<T> *arr;
public:
	Stack(int n = 10);
	bool push (T data);
	bool pop(T &data);
	bool isFull();
	bool isEmpty();
	~Stack();
};


/*
#include<iostream>
using namespace std;

class StackLink {

private: 

struct node { 
node* next;       // handle to next list element 
char data;
};

node* top;

public: 

StackLink( )
{
top=NULL;
}

void push (char item) // add an element to the stack 
{
node* p= new node;
p->data= item;
p->next= top;
top=p;
}

char pop( ) // remove an element from stack 
{
if(isEmpty())
return NULL;
else
{
node* temp= top;
top= temp->next;
return temp->data;
}


}
void display()
{

node* current=top;
if(current==NULL)
cout<<"Stack is empty!";
while(current!=NULL)
{
cout<<current->data<<" ";
current=current->next;
}

}

bool isEmpty() // check if the stack is empty
{
return(top==NULL);
}

// ~Stack() { } // destructor 

};

int main()
{
StackLink s1;
s1.push('D');
char temp= s1.pop();
s1.display();
system("pause");
}*/