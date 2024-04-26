#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
  struct Node *t,*last;
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data=A[0];
  head->next=head;
  last =head;
  for(int i=1;i<n;i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=last->next;
    last->next =t;
    last=t;
  }
}

void display(struct Node *p)
{
  do{
      printf("%d ",p->data);
      p=p->next;
    }while(p!=head);
  printf("\n");

}

void Rdisplay(struct Node *p)
{
  static int flag=0;
  if(p!=head || flag==0)
  {
    flag=1;
    printf("%d ",p->data);
    Rdisplay(p->next);
  }
  flag=0;
}

int length(struct Node *p)
{
  int c=0;
  p=head;
  do  {
    c=c+1;
    p=p->next;
  }while(p!=head);

  return c;
}


void insert(struct Node *p,int index,int x)
{  
  if(index<0 || index>length(head))
  {
    return;
  }
  struct Node *t;
  if(index==0)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(head==NULL)
    {
      head=t;
      head->next=head;
    }
    else
    {
      p=head;
      while(p->next!=head)
      {
        p=p->next;
      }
      p->next=t;
      t->next=head;
      head=t;
    }
  }
  else
  {
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=x;
    t=head;
    for(int i=0;i<index-1;i++)
    {
      t=t->next;
    }
    p->next=t->next;
    t->next=p;
  }
}

int Delete(struct Node *p,int pos)
{
  struct Node *q=NULL;
  int x;
  if(pos<1 && pos>length(head))
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
      head=NULL;
    }
    else
    {
      p->next=head->next;
      delete head;
      head=p->next;
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
    x=q->data;
    delete q;
  }
  return x;
}
int main()
{
  int A[]={1,2,3,4,5};
  create(A,6);
  // Rdisplay(head);
  // insert(head,5,9);
  Delete(head,2);
  display(head);
  return 0;
}
