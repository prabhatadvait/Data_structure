#include<iostream>
using namespace std;

int main(){
  int *p,*q;
  p = (int *)malloc(4*sizeof(int));
  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;

  q = (int *)malloc(5*sizeof(int));
  for(int i=0;i<4;i++){
    q[i] = p[i];
  }
  free(p);
  p=q;

  q = NULL;


  for(int i=0;i<=4;i++){
    cout<<p[i]<<endl;
  }

  return 0;
}
