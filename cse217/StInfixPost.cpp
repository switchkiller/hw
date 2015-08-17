#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ncurses.h>
#include<string.h>
struct Stack
{
	int top;
	unsigned capacity;
	int* arr;
};

struct Stack* createStack( unsigned capacity)
{
	struct Stack* stack = ( struct Stack*) malloc(sizeof(struct Stack));
	if (!stack)
		return NULL;
	stack->top=-1;
	stack->capacity = capacity;
	stack->arr = (int*) malloc(stack->capacity*sizeof(int));
        if (!stack->array)
		return NULL;
	return Stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

char peek(struct Stack* stack)
{
	return stack->arr[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->arr[stack->top--]
	return '$';
}

void push(struct Stack* stack,char item)
{
	stack->arr[++stack->top]==item;
}

int isOperand(char item)
{
	return (item >= 'a' && item <= 'z') || (item >= 'A' || item <= 'Z'); 
}

int Precedence(char item)
{
	switch (item)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i,k;
	struct Stack* stack = createStack(strlen(exp));
	if (!stack)
		return -1;
	for ( i=0, k=-1; exp[i]; ++i)
	{
		if(isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i]== '(')
			push(stack,exp[i]);
		else if (exp[i]== ')')
		{
			while (!isEmpty(stack) && peek(stack)!='(' )
				exp[++k]=pop(stack);

		}
	}
}




