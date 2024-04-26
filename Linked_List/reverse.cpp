#include<iostream>
#include<climits>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*first=NULL;

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
void display(struct Node *p)
{
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}
int count(struct Node *p)
{
  int c=0;
  while(p!=0)
  {
    c = c+1;
    p = p->next;
  }
  return c;
}
void reverse(struct Node *p)
{
    int *A,i=0;
  struct Node *q = p;
  A = (int *)malloc(sizeof(int)*count(p));
  while(q!=NULL)
  {
    A[i]=q->data;
    q = q->next;
    i++;
  }
  q=p;
  i--;
  while(q!=NULL)
  {
    q->data=A[i];
    q =q->next;
    i--;
  }

}

void reverse2(struct Node *p)
{
  struct Node *q=NULL,*r =NULL;
  while(p!=NULL)
  {
    r=q;
    q=p;
    p=p->next;
    q->next =r;
  }
  first = q;
}

void reverse3(struct Node *q,struct Node *p)
{
  if(p){
    reverse3(p,p->next);
    p->next = q;
  }
  else{
    first = q;
  }
}
int main()
{
  int a[] = {10,20,30,40,50};
  create(a,5);
  // reverse3(NULL,first);
  reverse2(first);

  display(first);
}
