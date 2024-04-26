#include<iostream>
using namespace std;

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
  struct Node *t,*last;
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data=A[0];
  head->next=head->prev=head;
  last =head;
  for(int i=1;i<n;i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=last->next;
    t->prev=last;
    last->prev=t;
    last->next =t;
    last=t;
  }
}

int Length(struct Node *p)
{
  int c=0;
  do
  {
    c=c+1;
    p=p->next;
  }while(p!=head);
  return c;
}

void insert(struct Node *p,int index,int x)
{
  struct Node *t;
  if(index<0 || index>Length(head))
  {
    return;
  }
  if(index==0)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=head;
    t->prev=head->prev;
    head->prev=t;
    head=t;
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
    p->next->prev=t;
    p->next=t;
    t->prev=p;
  }
}

int Delete(struct Node *p,int pos)
{
  int x;
  struct Node *q;
  if(pos<1 || pos>Length(head))
  {
    return -1;
  }
  if(pos==1)
  {
    while(p->next!=head)
    {
      p=p->next;
    }
    x=head->data;
    if(p==head)
    {
      delete head;
      head = NULL;
    }
    else
    {
      p->next=head->next;
      head->next->prev=p;
      delete head;
      head = p->next;
    }
  }
  else
  {
    for(int i=0;i<pos-2;i++)
    {
      p=p->next;
    }
    q=p->next;
    p->next=q->next;
    q->next->prev=p;
    x=q->data;
    delete q;
  }
  return x;
}

void display(struct Node *p)
{
  do
  {
    printf("%d ",p->data);
    p=p->next;
  }while(p!=head);
}

int main()
{
  int A[]={1,2,3,4,5};
  create(A,5);
  // insert(head,2,9);
  Delete(head,2);
  display(head);
  return 0;
}
