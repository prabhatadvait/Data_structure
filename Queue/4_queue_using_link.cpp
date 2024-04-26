#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*front = NULL,*rear=NULL;

void enqueue(int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
  {
    printf("Queue is full\n");
  }
  else
  {
    t->data=x;
    t->next = NULL;
    if(front==NULL)
    {
      front = rear = t; 
    }
    else
    {
      rear->next = t;
      rear =t;
    }
  }
}

int dequeue()
{
  struct Node *t;
  int x=-1;
  if(front==NULL)
  {
    printf("queue is empty\n");
  }
  else
  {
    t=front;
    front  = front->next;
    x=t->data;
    free(t);

  }
  return x;
}

void display()
{
  struct Node *p;
  p=front;
  while(p)
  {
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  enqueue(1);
  enqueue(2);
  enqueue(3);

  display();
  
  return 0;
}
