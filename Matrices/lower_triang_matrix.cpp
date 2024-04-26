#include<iostream>
using namespace std;

struct Matrix{
  int *A;
  int n;
};

void set(struct Matrix *m,int i,int j,int x){
  if(i>=j){
// m->A[i*(i-1)/2+j-1]=x;  ROW WISE
   m->A[m->n*(j-1)-((j-2)*(j-1))/2+(i-j)]=x;
  }
}

int get(struct Matrix m,int i,int j){
  if(i>=j){
    // return m.A[i*(i-1)/2+j-1];
    return m.A[m.n*(j-1)-((j-2)*(j-1))/2+(i-j)];

  }
  else
    return 0;
}
void display(struct Matrix m){
  int i,j;
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      if(i>=j){
        printf("%d ",m.A[m.n*(j-1)-((j-2)*(j-1))/2+(i-j)]);
     }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}

int main(){
  struct Matrix m;
  printf("Enter the dimension ");
  scanf("%d",&m.n);
 m.A= new int[(m.n*m.n-1)/2];
  int i,j,x;
  printf("Enter the element to be inserted ");
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      scanf("%d",&x);
      set(&m,i,j,x);
    }
  }
  printf("\n");
  display(m);
  
}
