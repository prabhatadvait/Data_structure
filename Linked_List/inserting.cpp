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

void Insert(struct Node *p,int index,int ele)
{
  struct Node *t;
  if(index<0 || index>count(p))
    return;
  t = (struct Node *)malloc(sizeof(struct Node ));
  t->data = ele;
  if(index==0)
  {
    t->next = first;
    first = t;
  }
  else{
    for(int i=0;i<index-1;i++)
      p  = p->next;
    t->next = p->next;
    p->next = t;
  } 
}

int main()
{
  // int A[] = {3,5,7,8};
  // create(A,4);
  // display(first);

  Insert(first,0,9);
  Insert(first,1,2);

  Insert(first,2,3);
  printf("\n");
  display(first);

 return 0; 
}
