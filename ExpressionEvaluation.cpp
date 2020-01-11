/*Question 2:  (Expression Evaluation)  
Develop a C++ program to evaluate constant expressions. The program works in following steps:
1) Take expression of variable size as input from user, use ‘#’ as unary (‘-‘) operator. 
2) Convert this expression into post-fix notation using a stack. 
3) Save the post-fix expression in a string and Print onto the screen 
4) Compute or evaluate the post-fix expression using a stack 
5) Print the final answer  
You have to implement your own stack using Link-List structure and you must use this stack for Expression Evaluation.  */ 

#include <iostream>									// for I/O
#include <cstring>									// to handle C-strings

#include "linkyStack.h"
#include "linkyStack.cpp"

using namespace std;

//local functions
int convertChartoInt(char);							// convert char expression to integer expression
int precedence(char);								// check precedence of operators
bool rpn(char *,float &);							// evaluate postfix expression
void postfix(char *,char *,Stack<char> &);			// convert infix to postfix expression
bool checkOperator(char);							// check whether required operator comes or not 
void printPostfixExp(char *);						// print postfix expression

int main()
{
	
	Stack<char> input;
	char *infixExp = new char [30];						// take expression as input from user
	cout<<"***********_________________EXPRESSION EVALUATION________________*************"<<endl<<endl;
	cout << "Enter a constant infix expression: ";
	cin >> infixExp;
	char *postFix = new char [30];						// using postFix for postfix expression
	float result = 0;
	int i = 0;
	bool flag = true;
	postfix(infixExp,postFix,input);					// function calling	// converting infix to postfix using stack
	cout << "PostFix Expression : "; 
	printPostfixExp(postFix);							// printing post fix expression
	flag = rpn(postFix,result);							// evaluating post fix expression
	if(flag)
	{
		cout << endl;
		cout << "Answer: " << result << endl;
	}
	else
	{
		cout << endl;
		cout << "Your entered an Invalid Expression :( What a big sin :O "<<endl;
		cout << endl;
	}
	cout<<endl;
	cout<<"Check out the perfection and accuracy & do admire the programmer !!! "<<endl;
	system("pause");
	return 0;											// ANSI C requires main to return int. 
} 

int convertChartoInt(char num)
{
	switch(num)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	}
}
int precedence(char op)
{
	switch(op)
	{
	case '|':
		return 0;
		break;
	case '^':
		return 1;
		break;
	case'=':
		return 2;
		break;
	case '>':
		return 3;
		break;
	case '<':
		return 4;
		break;
	case '-':
		return 5;
		break;
	case '+':
		return 6;
		break;
	case '*':
		return 7;
		break;
	case '/':
		return 8;
		break;
	case '%':
		return 9;
		break;
	case '!':
		return 10;
		break;
	case '#':
		return 11;
		break;
	}
	return 0;
}

void postfix(char *infixExp, char *postFix, Stack<char> &a)			// convert infix to postfix
{
	char ch;
	int len = strlen(infixExp);
	int j = 0;
	
	for(int i=0 ; i<len ; i++)
	{
		if(infixExp[i]>=48 && infixExp[i]<=57)
		{
			postFix[j]=infixExp[i];
			j++;
		}

		else if(a.isEmpty() && checkOperator(infixExp[i]) )
		{
			a.push(infixExp[i]);								
			
		}

		else if(!a.isEmpty() && checkOperator(infixExp[i]))
		{
			a.pop(ch);
			a.push(ch);
			if(infixExp[i]=='(')
			{
				a.push(infixExp[i]);
			}
			else if(precedence(infixExp[i])<=precedence(ch))
			{
				a.pop(postFix[j]);
				a.push(infixExp[i]);
				j++;
			}
			else if(precedence(infixExp[i])>precedence(ch))
			{
				a.push(infixExp[i]);
			}
		}

		else if(infixExp[i]==')')
		{
			a.pop(ch);
			postFix[j]=ch;
			j++;
			while(ch!='(')
			{
				a.pop(ch);
				if(ch!='(')
				{
					postFix[j]=ch;
					j++;
				}
			}
		}
	}

	if(!a.isEmpty())
	{
		while(!a.isEmpty())
		{
			a.pop(ch);
			postFix[j]=ch;
			j++;
		}
	}
	postFix[j]='\0';
}


bool rpn(char *postFix, float &temp)						// evaluate postfix
{
	Stack<float> a;
	float c1;
	float c2;
	int len = strlen(postFix);
	for(int i=0;i<len;i++)
	{
		if(postFix[i]>=48 && postFix[i]<=57)
		{
			temp = convertChartoInt(postFix[i]);
			a.push(temp);
		}
	
		if(postFix[i]=='+')
		{
			a.pop(c1);
			a.pop(c2);
			temp=c1+c2;
			a.push(temp);
		}

		if(postFix[i]=='-')
		{
			a.pop(c1);
			a.pop(c2);
			temp=c2-c1;
			a.push(temp);
		}

		if(postFix[i]=='*')
		{
			a.pop(c1);
			a.pop(c2);
			temp=c1*c2;
			a.push(temp);
		}

		if(postFix[i]=='/')
		{
			a.pop(c1);
			a.pop(c2);
			temp=c2/c1;
			a.push(temp);
		}

		if(postFix[i]=='>')
		{
			a.pop(c1);
			a.pop(c2);
			temp=(c2>c1);
			a.push(temp);
		}

		if(postFix[i]=='<')
		{
			a.pop(c1);
			a.pop(c2);
			temp=c2<c1;
			a.push(temp);
		}

		if(postFix[i]=='=')
		{
			a.pop(c1);
			a.pop(c2);
			if(c1==c2)
			{
				a.push(1);
			}
			else
			{
				a.push(0);
			}
		}

		if(postFix[i]=='|')
		{
			a.pop(c1);
			a.pop(c2);
			if((c1==0||c1==1) && (c2==0||c2==1))
			{
				if(c1==0 && c2==0)
				{
					a.push(0);
				}
				else
				{
					a.push(1);
				}
			}
			else
			{
				return false;
				break;
			}
		}

		if(postFix[i] == '^')
		{
			a.pop(c1);
			a.pop(c2);
			if((c1==0||c1==1) && (c2==0||c2==1))
			{
				if(c1==1 && c2==1)
				{
					a.push(1);
				}
				else
				{
					a.push(0);
				}
			}
			else
			{
				return false;
				break;
			}
		}

		if(postFix[i] == '%')
		{
			int t1=0;
			int t2=0;
			int mod=0;
			a.pop(c1);
			a.pop(c2);
			t1=c1;
			t2=c2;
			mod=t2%t1;
			temp=mod;
			a.push(temp);
		}

		if(postFix[i] == '!')
		{
			a.pop(c1);
			if(c1==0 || c1==1)
			{
				if(c1==1)
				{
					a.push(0);
				}
				else if(c1==0)
				{
					a.push(1);
				}
			}
			else 
			{
				return false;
				break;
			}
		}

		if(postFix[i] == '#')
		{
			a.pop(c1);
			int value=c1;
			int t=0;
			t=~value+1;
			a.push(t);
		}
	}
	a.pop(temp);
	return true;
}

bool checkOperator(char Operator)
{
	if (Operator == '(' || Operator == '*' || Operator == '/' || Operator == '+' || 
		Operator == '-' || Operator == '^' || Operator == '|' || Operator == '>' || 
		Operator == '<' || Operator == '=' || Operator == '%' || Operator == '#' || 
		Operator == '!')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printPostfixExp(char *postFix)
{
	for(int j=0; postFix[j] != '\0'; j++)
	{
		if(postFix[j] != '(')
		{
			cout << postFix[j];
		}
	}
}