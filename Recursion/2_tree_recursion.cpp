#include<iostream>
using namespace std;

void fun(int n){

  if(n>0){
    printf("%d ",n);
    fun(n-1);
    fun(n-1);
  }
}
int main(){
  int a;
  cout<<"Enter the value of a"<<endl;
  cin>>a;
  fun(3);


  return 0;
}
