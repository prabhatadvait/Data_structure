#include<iostream>
using namespace std;

int main(){

  int A[] = {6,7,8,9,11,12,15,16,17,18,19};
  int l  = 6;
  int  h = 19;
  int n = 11;
  int diff = l-0;
  for(int i=0;i<n;i++){
    if(A[i]-i !=diff){
      while(diff<A[i]-i){
        printf("%d\n",i+diff);
        diff++;
      }
    }
  }
  return 0;
}
