#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*top=NULL;

void push(int x)
{
  struct Node *t;
  t=(struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
  {
    printf("Stack is overflow/n");
  }
  else
  {
    t->data=x;
    t->next = top;
    top=t;
  }
}

int pop()
{
  struct Node *t;
  int x=-1;
  if(top==NULL)
  {
    printf("stack is empty ");
  }
  else
  {
    t=top;
    x=t->data;
    top=top->next;
    delete t;
  }
  return x;
}

void display(struct Node *p)
{
  p=top;
  if(top==NULL)
  {
    printf("Stack is empty");
  }
  else
  {
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
    printf("\n");
  }
}

int main()
{
  push(10);
  push(20);
  push(30);

  display(top);
  printf("\n%d ",pop());

  return 0;
}
