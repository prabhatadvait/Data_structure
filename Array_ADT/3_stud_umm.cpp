#include<iostream>
using namespace std;

int main(){

  int a[] ={3,7,4,9,12,6,1,11,2,10};
  int l =1;
  int h = 12;
  int n = 10;
  int H[13] = {0};
  for(int i=0;i<n;i++){
    H[a[i]]++;
  }
  for(int i=l;i<=h;i++){
    if(H[i]==0){
      printf("%d\n",i);
    }
  }

}
