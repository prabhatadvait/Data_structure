#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char A[]="finding";
  for(int i=0;A[i]!='\0';i++){
  int count = 1;
      for(int j=i+1;A[j]!='\0';j++){
        if(A[i]==A[j]){
          count++;
          A[j]=i+1;
        }
      }
    if(count>1){
      printf("%c %d\n",A[i],count);
    }
  }
  return 0;
}
