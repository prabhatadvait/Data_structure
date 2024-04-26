#include<iostream>
using namespace std;

int power(int m,int n){
  if(n==0){
    return 1;
  }
  else{
    return m*power(m,n-1);
  }
}
int pow(int m,int n){
  if(n==0){
    return 1;
  }
  if(n%2==0){
    return pow(m*m,n/2);
  }
  else{
    return m*pow(m*m,(n-1)/2);
  }
}
int main(){
  int m = 2,n=9;
  int p = pow(m,n);
  cout<<p<<endl;
  return 0;
}
