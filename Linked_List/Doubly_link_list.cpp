#include<iostream>
using namespace std;

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
  struct Node *t,*last;
  first=(struct Node *)malloc(sizeof(struct Node));
  first->data=A[0];
  first->next=first->prev=NULL;
  last=first;
  for(int i=1;i<n;i++)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next = last->next;
    t->prev = last;
    last->next=t;
    last=t;

  }
}

void display(struct Node *p)
{
  while(p)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}

int length(struct Node *p)
{
  int c=0;
  while(p)
  {
    c=c+1;
    p=p->next;
  }
  return c;
}

void insert(struct Node *p,int index,int x)
{
  struct Node *t;
  if(index<0 || index>length(first))
  {
    return;
  }
  if(index==0)
  {
    t=new Node;
    t->data=x;
    t->next=first;
    t->prev=NULL;
    first->prev=t;
    first=t;
  }
  else
  {
    t=new Node;
    t->data=x;
    for(int i=0;i<index-1;i++)
    {
      p=p->next;
    }
    t->next=p->next;
    t->prev=p;
    p->next=t;
    if(p->next)
    {
      p->next->prev=t;
    }
  }
}

int Delete(struct Node *p,int pos)
{
  int x;
  if(pos<1 || pos>length(p)){
    return -1;
  }
  if(pos==1)
  {
    p=first;
    first=first->next;
    x=p->data;
    delete p;
    if(first)
    {
      first->prev=NULL;
    }

  }
  else
  {
    
    for(int i=0;i<pos-1;i++)
    {
      p=p->next;
    }
    p->prev->next=p->next;
    if(p->next)
    {
      p->next->prev=p->prev;
    }
    x=p->data;
    delete p;
    
  }
  return x;
}

void Reverse(struct Node *p)
{
  struct Node *temp;
  while(p)
  {
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;
    if(p!=NULL && p->next==NULL)
    {
      first=p;
    }
  }
}

int main()
{
  int A[]={1,2,3,4,5};
  create(A,5);
  // insert(first,1,9);
  // Delete(first,1);
  Reverse(first);
  display(first);
  printf("\nThe length of linkedlist is %d",length(first));
  return 0;
}
