#include<iostream>
using namespace std;

int main(){
  int A[] = {6,3,8,10,16,7,5,2,9,14};
  int n=10;
  int k=10;
  for(int i=0;i<n-1;i++){
    for(int j= i+1;j<n;j++){
      if(A[i]+A[j] == k){
        printf("%d+%d = %d\n",A[i],A[j],k);
      }
    }
}

  return 0;
}
