#include<iostream>
using namespace std;

class Diagonal{
private:
  int n;
  int *A;
public:
  Diagonal(int n){
    this->n=n;
    A=new int[n];
  }
  void set(int i,int j,int x);
  int get(int i,int j);
  void display();
  ~Diagonal(){
    delete []A;
  }
};

void Diagonal :: set(int i,int j,int x){
  if(i==j){
    A[i-1]=x;
  }
}
int Diagonal :: get(int i,int j){
  if(i==j){
    return A[i-1];
  }
  else{
    return 0;
  }  
}
void Diagonal :: display(){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j){
        printf("%d ",A[i]);
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
int main(){
  Diagonal d(4);
  d.set(1,1,2);
  d.set(2,2,9);
  d.set(3,3,15);
  d.set(4,4,19);
  d.display();
}
