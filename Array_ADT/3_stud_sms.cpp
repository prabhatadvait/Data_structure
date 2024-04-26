#include<iostream>
using namespace std;

int main(){
  int A[] = {1,2,3,4,5,6,8,9,10,11,12};
  int m = 12;
  int n = 11;
  int k = (m*(m+1))/2;
  int sum = 0;
  for(int i=0;i<n;i++){
    sum =sum+A[i];
  }
  int missing = k-sum;
  printf("%d\n",missing);

  return 0;
}
