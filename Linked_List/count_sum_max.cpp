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

int add(struct Node *p)
{
  int sum = 0;
  while(p)
  {
    sum =sum+p->data;
    p = p->next;
  }
  return sum;
}

int max(Node *p)
{
  int m = INT_MIN;
  while(p)
  {
    if(p->data>m)
    {
      m = p->data;
    }
    p = p->next;
  }
  return m;
}


int min(struct Node *p)
{
  int m = INT_MAX;
  while(p)
  {
    if(p->data<m)
    {
      m = p->data;
    }
    p = p->next;
  }
  return m;
}

struct Node * Lsearch(Node * p,int key)
{
  while(p!=NULL)
  {
    if(key==p->data)
      return p;
    p = p->next;
  }
  return NULL;
}

struct Node* RLsearch(Node *p,int key)
{
  if(p==NULL)
  {
    return NULL;
  }
  if(key==p->data)
  {
    return p;
  }
  return RLsearch(p->next,key);
}

struct Node * IMproLsearch(Node *p,int key)
{
  Node *q = NULL;
  while(p!=NULL)
  {
    if(key==p->data)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
  
}


int main(){
  struct Node *temp,*temp1;
  int A[] = {2,3,4,5,6};
  create(A,5);

  display(first);

  int k = count(first);
  printf("\n%d ",k);
  
  int s = add(first);
  printf("\n%d ",s);

  int m = max(first);
  printf("\n%d ",m);

  int mn = min(first);
  printf("\n%d ",mn);

  // temp = Lsearch(first,7);
  temp = IMproLsearch(first,4);
  if(temp)
  {
    printf("\nkey is found %d ",temp->data);
  }
  else{
    printf("\nKey is not found\n");
  }
  
  temp1 = RLsearch(first,6);
  if(temp1)
  {
    printf("\nkey is found \n");
  }
  else {
    printf("\nkey is not found\n");
  }
  display(first);

  return 0;
}
