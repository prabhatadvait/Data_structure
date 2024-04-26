#include<iostream>
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

void create(struct Poly *p){
  printf("Enter the no.of elements: ");
  scanf("%d",&p->n);
  p->t= new Term[p->n];
  printf("Enter terms\n");
for(int i=0;i<p->n;i++)
{
  scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
}
}

void display(struct Poly p)
{
  for(int i=0;i<p.n;i++){
    printf("%dx%d+",p.t[i].coeff,p.t[i].exp);
  }
  printf("\n");
}

struct Poly *add(struct Poly *p1,struct Poly *p2)
{
  int i,j,k;
  struct Poly *sum;
  sum =(struct Poly*)malloc(sizeof(struct Poly));
  sum->t=(struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term));
  i=j=k=0;
  while(i<p1->n && j<p2->n)
  {
    if(p1->t[i].exp>p2->t[i].exp)
      sum->t[k++] = p1->t[i++];
    else if(p1->t[i].exp<p2->t[j].exp)
        sum->t[k++] = p2->t[i];
    else {
      sum->t[k].exp = p1->t[i].exp;
      sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
    }
  }
  for(;i<p1->n;i++){
    sum->t[k++] = p1->t[i];
  }
  for(;j<p2->n;j++){
    sum->t[k++] = p2->t[j];
  }
  sum->n = k;
  return sum;
}

int main()
{
  struct Poly p1,p2,*p3;
 create(&p1);
 create(&p2);
  display(p1);
  display(p2);
  p3 = add(&p1,&p2);
  display(*p3);
  return 0;
}
