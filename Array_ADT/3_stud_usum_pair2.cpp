#include<iostream>
using namespace std;

int main(){
  int A[] = {6,3,8,10,16,7,5,2,9,14};
  int H[17] = {0};
  int n = 10;
  int k=10;
  for(int i=0;i<n;i++){
    if(H[k-A[i]]!=0){
      printf("%d + %d = %d\n",A[i],k-A[i],k);
    }
    H[A[i]]++;
  }
  return 0;
}
