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


int Delete(struct Node *p,int index)
{
  struct Node *q = NULL;
  int x= -1;
  if(index<1 || index>count(p))
  {
    return x;
  }
  if(index==1){
    q=first;
    x=first->data;
    first = first->next;
    delete q;
    return x;
  }
  else{
    for(int i=0;i<index-1 && p;i++)
    {
      q=p;
      p = p->next;
    }
    q->next=p->next;
    x=p->data;
    delete p;
    return x;
  }
}
int main(){
  int A[] = {2,3,4,5,6};
  create(A,5);
  printf("\n%d \n",Delete(first,3));
  display(first);
  return 0;
}
