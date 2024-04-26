#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
  struct Node *t,*last;
  first=new Node;
  first->data=A[0];
  first->next=NULL;
  last=first;
  for(int i=1;i<n;i++)
  {
    t=new Node;
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}
int Middle(struct Node *p)
{
  struct Node *q,*t;
  q=t=first;
  while(q)
  {
    q=q->next;
    if(q)
    {
      q=q->next;
    }
    if(q)
    {
      p=p->next;
    }
  }
 return p->data;
}

int main()
{
  int A[]={1,2,3,4,5};
  create(A,5);
  printf("middle element is %d ",Middle(first));

}
