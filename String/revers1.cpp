#include<iostream>
using namespace std;


int main(){
  char a[]= "python";
  char b[7];
  int i,j;
  for(i=0;a[i]!='\0';i++){
  }
  i=i-1;
  for(j=0;i>=0;i--,j++){
    b[j]=a[i];
  }
  b[j]='\0';
  printf("%s",b);

  return 0;
}
