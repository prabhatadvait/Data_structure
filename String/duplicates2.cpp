#include<iostream>
using namespace std;

int main(){
  char A[] = "finding";
  int i, H[26]={0};
  for(i=0;A[i]!='\0';i++){
    H[A[i]-97]+=1; 
  }
  for(i=0;i<26;i++){
    if(H[i]>1){
      printf("%c ",i+97);
      printf("%d\n",H[i]);
    }
  }
  return 0;
}
