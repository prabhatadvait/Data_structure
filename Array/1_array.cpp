#include<iostream>
using namespace std;


int main(){

  // int a[5];
  // for(int i=0;i<5;i++){
  //   printf("%u\n",&a[i]);
  // }
  // int p[5]={2,4,6,7,8};
  // int b[5]={2,4};
  // int c[5] = {0};
  // int d[] = {2,4,5,6,7};
int a[5];
int *p;
  p = (int *)malloc(5*sizeof(int));
  p[0] = 3;
  p[1] = 4;
  p[2] = 5;
  p[3] = 6;
  p[4] = 7;

  for(int i=0;i<5;i++){
    cout<<p[i]<<endl;
  }
  delete []p;
  return 0;

}
