#include<iostream>
using namespace std;

int  main(){
  char a[] = "finding";
  int h=0,x=0;
  int i;
  for(i=0;a[i]!='\0';i++){
    x=1;
    x=x<<(a[i]-97);
    if((x&h)>0){
      printf("%c is duplicate\n",a[i]);
    }
    else{
      h=x|h;
    }
  }
  return 0;
}
