#include<iostream>
using namespace std;

int main(){
  char a[15];
  int i,j,flag =0; 
  printf("Enter the string: ");
  scanf("%s",a);
  for(i=0;a[i]!='\0';i++){
  }
  i=i-1;
  j=0;
  while(a[j]!='\0'){
    if(a[i]!=a[j]){
      flag = 1;
      break;
    }
    i--;
    j++;
  }
  if(flag==1){
    printf("It's not a plaindrome\n");
  }
  else{
    printf("It's a plaindrome \n");
  }
  return 0;
}
