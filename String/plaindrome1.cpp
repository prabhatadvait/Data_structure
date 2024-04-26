#include<iostream>
using namespace std;

int main(){
  char a[] = "mam";
  char b[7];
  int i,j,flag=0;
  for(i = 0;a[i]!='\0';i++){

  }
  i=i-1;
  for(j=0;i>=0;i--,j++){
    b[j] = a[i];
  }
  b[j] = '\0';
  i=j=0;
  printf("%s\n",b);
  for(i=0;a[i]!='\0';i++){
    if(a[i]!=b[i]){

      flag=0;
      break;
    }
    else{
      flag = 1;
    }
  }
  if(flag){
    printf("it's a plaindrome");
  }
  else{
    printf("not a plaindrome");
  }
    return 0;
}
