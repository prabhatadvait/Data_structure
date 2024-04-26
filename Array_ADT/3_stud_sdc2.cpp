#include<iostream>
using namespace std;

int main(){
  int a[]={3,6,8,8,10,12,15,15,15,20};
  int h[21] = {0};
  int max = 20;
  int n = 10;
  for(int i=0;i<n;i++){
    h[a[i]]++;
  }
  for(int i=0;i<=max;i++){
    if(h[i]>1){
      printf("%d elements %d times\n",i,h[i]);
    }
  }

  return 0;
}
