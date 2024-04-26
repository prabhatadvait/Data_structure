#include<iostream>
using namespace std;

class Matrix{
private:
  int *A;
  int n;
public:
  Matrix(){
    n=2;
    A=new int[2*(2+1)/2];
  }
  Matrix(int n){
    this->n=n;
    A=new int[n*(n+1)/2];
  }
  ~Matrix(){
    delete []A;
  }
  void set(int i,int j,int x);
  int get(int i,int j);
  void display();
};

void Matrix :: set(int i,int j,int x){
  if(i>=j){
    A[i*(i-1)/2+j-1]=x;  // ROW WISE
    // A[n*(j-1)-((j-2)*(j-1))/2+(i-j)]=x;
  }
}

int Matrix :: get(int i,int j){
  if(i>=j){
    return A[i*(i-1)/2+j-1]; // Row WISE
    // return A[n*(j-1)-((j-2)*(j-1))/2+(i-j)];

  }
  else
    return 0;
}
void Matrix :: display(){
  int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(i>=j){
        // printf("%d ",A[n*(j-1)-((j-2)*(j-1))/2+(i-j)]);
       printf("%d ",A[i*(i-1)/2+j-1]); // Row wise
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}

int main(){
  int d;
  printf("Enter the dimension: ");
  scanf("%d",&d);
  Matrix m(d);
  int i,j,x;
  printf("Enter the element to be inserted ");
  for(i=1;i<=d;i++){
    for(j=1;j<=d;j++){
      scanf("%d",&x);
      m.set(i,j,x);
    }
  }
  printf("\n");
  m.display();
}
