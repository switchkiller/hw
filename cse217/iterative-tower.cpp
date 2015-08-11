#include<iostream>
#include<math.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Stack
{
  unsigned capacity;
  int top;
  int *arr;
};
struct Stack* createStack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack -> capacity =capacity;
  stack -> top =-1;
  stack -> arr = (int*) malloc(stack -> capacity * sizeof(int));
  return stack;
}
int isFull(struct Stack* stack)
{
  return (stack->top == stack->capacity -1);
}
int isEmpty(struct Stack* stack)
{
  return (stack->top==-1);
}
void push(struct Stack* stack, int item)
{
  if (isFull(stack))
    return;
  stack->arr[++stack->top] = item;
}
int pop(struct Stack *stack)
{
  if (isEmpty(stack))
    return INT_MIN;
  return stack->arr[stack->top--];
}
void moveDisk(char from, char to, int disk)
{
  cout<<disk<<" from "<<from<<"-->"<<to<<endl;
}
void moveDiskBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d)
{
  int pole1TopDisk = pop(src);
  int pole2TopDisk = pop(dest);
  if (pole1TopDisk == INT_MIN)
  {
    push(src, pole2TopDisk);
    moveDisk(d,s,pole2TopDisk);
  }
  else if (pole2TopDisk == INT_MIN)
  {
    push(dest,pole1TopDisk);
    moveDisk(s,d,pole1TopDisk);
  }
  else if (pole1TopDisk > pole2TopDisk)
  {
    push(src,pole1TopDisk);
    push(src,pole2TopDisk);
    moveDisk(d,s,pole2TopDisk);
  }
  else
  {
    push(dest,pole2TopDisk);
    push(dest, pole1TopDisk);
    moveDisk(s,d,pole1TopDisk);
  }
}
void iterative(int num_of_disks, struct Stack *src, struct Stack *aux, struct Stack *dest)
{
  int i, tot;
  char s = 'S', d='D', a='A';
  if (num_of_disks%2==0)
  {
    char temp=d;
    d=a;
    a=temp;
  }
  tot=pow(2,num_of_disks)-1;
  for (i=num_of_disks; i>=1;i--)
    push (src,i);
  for (i=1; i<= tot; i++)
  {
    if (i % 3 == 1)
      moveDiskBetweenTwoPoles(src, dest, s, d);
    else if (i % 3 == 2)
      moveDiskBetweenTwoPoles(src, aux, s, a);
    else if (i % 3 == 0)
      moveDiskBetweenTwoPoles(aux, dest, a, d);
  }
}
int main()
{
  unsigned num_of_disks = 4;
  struct Stack *src, *dest, *aux;
  src = createStack(num_of_disks);
  aux = createStack(num_of_disks);
  dest = createStack(num_of_disks);
  iterative(num_of_disks,src,aux,dest);
  return 0;
}
