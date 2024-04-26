#include<iostream>
using namespace std;

int fact(int n){
  if(n==0 || n==1){
    return 1;
  }
  else{
    return fact(n-1)*n;
  }
}
int s_ncr(int n, int r){
  int f1,f2,f3;
  f1=fact(n);
  f2 = fact(r);
  f3 = fact(n-r);
  return f1/(f2*f3);
}

int r_ncr(int n,int r){
 if(r==0 || n==r){
    return 1;
  } 
  else{
    return r_ncr(n-1,r-1)+ r_ncr(n-1,r);
  }
}

int main(){
  int a = s_ncr(5,1);
  cout<<a<<endl;
int b = r_ncr(5,1);
  cout<<b<<endl;

  return 0;
}
