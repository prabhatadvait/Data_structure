#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*first=NULL,*second=NULL,*third = NULL;

void create(int A[],int n)
{
  struct Node *t,*last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;
  for(int i=1;i<n;i++)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next=NULL;
    last->next=t;
    last = t;
  }
}
void create2(int A[],int n)
{
  struct Node *t,*last;
  second= (struct Node *)malloc(sizeof(struct Node));
  second->data = A[0];
  second->next = NULL;
  last = second;
  for(int i=1;i<n;i++)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next=NULL;
    last->next=t;
    last = t;
  }
}

void display(struct Node *p)
{
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}

void concatenating(struct Node *p,struct Node *q)
{
  third  = p;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next = q;
  q= NULL;
}

void Merge(struct Node *p,struct Node *q)
{
  struct Node *last;
  if(p->data<q->data)
  {
    third = last = p;
    p = p->next;
    last->next=NULL;
  }else
  {
    third = last =q;
    q = q->next;
    last->next = NULL;
  }
  while(p!=NULL && q!=NULL)
  {
    if(p->data<q->data)
    {
      last->next=p;
      last = p;
      p=p->next;
      last->next = NULL;
    }
    else
    {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
   
  }
    if(p!=NULL)
    {
      last->next = p;
    }
    else
    {
      last->next = q;
    }
}

int main(){
  int A[] = {10,20,30,40,50};
  int B[] = {5,15,25,35,45};
  create(A,5);
  create2(B,5);
  // concatenating(first,second);
  Merge(first,second);
  display(third);
  printf("\n");
  return 0;
}
