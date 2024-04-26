#include<stdio.h>

struct Node
{
  int data;
  struct Node *next;
}*front = NULL,*rear = NULL;

void enqueue(int x)
{
  struct Node *t;
  t=(struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
    printf("Queue is Full\n");
  else {
    t->data=x;
    t->next = NULL;
    if(front==NULL)
      front=rear=t;
    else {
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue()
{
  struct Node *t;
  int x=-1;
  if(front==NULL)
    printf("Queue is Empty\n");
  else {
    t=front;
    x=front->data;
    front = front->next;
    free(t);
  }
  return x;
}

int isEmpty()
{
  return front==NULL;
}


