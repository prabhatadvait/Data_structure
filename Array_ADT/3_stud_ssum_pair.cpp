#include<iostream>
using namespace std;

int main(){
  int n=10;
  int k=10;
  int A[] = {1,3,4,5,6,8,9,10,12,14};
  int i=0;
 int j = n-1;
  while(i<j){
    if(A[i]+A[j]==k){
      printf("%d + %d = %d\n",A[i],A[j],k);
      i++;
      j--;
    }
    else if((A[i]+A[j])<k){
      i++;
    }
    else{
      j--;
    }
  }
  return 0;
}
