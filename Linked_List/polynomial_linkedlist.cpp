#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
  int coef;
  int exp;
  struct Node *next;
}*poly=NULL;

void create()
{
  int n;
  struct Node *t,*last=NULL;
  printf("Enter the no. of term: ");
  scanf("%d",&n);
  poly=new Node;
  printf("Enter the coefficient: ");
  scanf("%d",&poly->coef);
  printf("Enter the exponent: ");
  scanf("%d",&poly->exp);
  poly->next=NULL;
  last = poly;
  printf("Enter the coeff and exp: ");
  for(int i=1;i<n;i++)
  {
    t=new Node;
    scanf("%d%d",&t->coef,&t->exp);
    t->next=NULL;
    last->next=t;
    last=t;
  }
}

void display(struct Node *p)
{
  while(p)
  {
    printf("%dX%d+",p->coef,p->exp);
    p=p->next;
  }
}

long Eval(struct Node *p,int x)
{
  long sum=0;
  struct Node *q=p;
  while(q!=NULL)
  {
    sum +=q->coef*pow(x,q->exp);
    q=q->next;
  }
  return sum;
}
int main()
{
  create();
  display(poly);
  printf("\n%ld\n",Eval(poly,3));
  return 0;
}
