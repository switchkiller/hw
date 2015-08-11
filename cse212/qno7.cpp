#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Stack
{
	int top1,top2;
	unsigned capacity;
	int* arr;
};

struct Stack* CreateStack(unsigned capacity)
{
	Stack* stack=new Stack;
	stack->capacity=capacity-50;
	stack->top1=-1;
  stack->top2=49;
	stack->arr=(int*) malloc(stack->capacity*sizeof(int));
	return stack;
}

int isFull(struct Stack* stack, int val)
{
  if (val==1)
	 return stack->top1==stack->capacity-1;
  if (val==2)
    return stack->top2==stack->capacity+50;
}

int isEmpty(struct Stack* stack,int val)
{ if (val==1)
	 return stack->top1==-1;
  if (val==2)
    return stack->top2==49;
}

void push(struct Stack* stack, int item,int val)
{ if (val==1)
	{if (isFull(stack,val))
		return;
	stack->arr[++stack->top1]=item;}
  if (val==2){
    if (isFull(stack,val))
      return;
    stack->arr[++stack->top2]=item;
  }
}

int pop(struct Stack* stack,int val)
{ if (val==1){
  	if(isEmpty(stack, int val))
  		return 0;
  	return stack->arr[stack->top1--];
  }
  if (val==2){
    if(isEmpty(stack, int val))
      return 0;
    return stack->arr[stack->top2--];
  }

int peek(struct Stack* stack)
{ if (val==1){
  	if(isEmpty(stack, int val))
  		return 0;
  	return stack->arr[stack->top1];
  }
  if (val==2){
    if(isEmpty(stack, int val))
      return 0;
    return stack->arr[stack->top2];
  }

int main()
{
	struct Stack* stack=CreateStack(100);

}
