#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*first = NULL;

void create(int A[],int n)
{
  int i;
  struct Node *t,*last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data= A[0];
  first->next=NULL;
  last = first;
  for(i=1;i<n;i++)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next = NULL;
    last->next = t;
    last =t;
  }
}
void Rdisplay(struct Node *p)
{
  if(p!=NULL)
  {
    printf("%d ",p->data);
    Rdisplay(p->next);
  }
}

int main(){
  struct Node p;
  int A[]={1,2,3,4,5,6};
  create(A,6);
  Rdisplay(first);
  return 0;
}
