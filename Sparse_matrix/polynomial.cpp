#include<iostream>
#include<cmath>
using namespace std;
struct Term
{
  int coeff;
  int exp;
};

struct Poly
{
  int n;
  struct Term *t;
};

int main()
{
struct Poly p;
printf("NO. of non-zero terms: ");
scanf("%d",&p.n);
p.t=new Term[p.n];
printf("Enter polynomial ");
for(int i=0;i<p.n;i++)
{
  printf("Term no. %d",i+1);
  scanf("%d%d",&p.t[i].coeff,&p.t[i].exp);
}
int x,sum=0;
printf("Enter the value of x: ");
scanf("%d",&x);
for(int i=0;i<p.n;i++)
{
  sum+=p.t[i].coeff * pow(x,p.t[i].exp);
}
printf("%d ",sum);
return 0;
}
