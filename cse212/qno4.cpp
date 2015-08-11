#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
using namespace std;
struct Stack
{
	int top;
	unsigned capacity;
	int* arr;
};

struct Stack* CreateStack(unsigned capacity)
{
	Stack* stack=new Stack;
	stack->capacity=capacity;
	stack->top=-1;
	stack->arr=(int*) malloc(stack->capacity*sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->arr[++stack->top]=item;
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return 0;
	return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->arr[stack->top];
}

int main()
{
	struct Stack* stack=CreateStack(100);
  int i=0,q=0;
  int str[]={1,2,3,4,-1,1,2,3,4,5,6,7,8,9,10,-2,11,12,-3,1,2,3,4,5};
  int len=24;
  int val=0;
  while (len--){
    if (str[q]>=0){
      push(stack,str[q]);
    }
    else{
    if ((stack->top-5)<0)
      cout<<"Error.";
    else{
      i=0;
      while(i<5)
      {cout<<"\n"<<pop(stack);
        i++;
      }
  }
} q++;
}
  while(stack->top!=-1){
    cout<<"\t"<<pop(stack);
  }
	return 0;
}
