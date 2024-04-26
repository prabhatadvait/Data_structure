#include<iostream>
using namespace std;

int main(){
  int a[] = {8,3,6,4,6,5,6,8,2,7};
  int h[9] = {0};
  int l=2;
  int hi = 8;
  int n = 10;
  for(int i=0;i<n;i++){
    h[a[i]]++;
  }
  for(int i = l;i<=hi;i++){
    if(h[i]>1){
      printf("%d, %d times\n",i,h[i]);
    }
  }
}
