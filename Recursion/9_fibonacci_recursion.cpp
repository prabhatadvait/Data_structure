#include<iostream>
using namespace std;

int fib(int n){
  if(n<=1){
    return n;
  }
  else{
    return fib(n-2) + fib(n-1);
  }
}

int F[10];
int mfib(int n){
    if(n<=1){
    F[n]=n;
    return n;
  }
  else{
    if(F[n-2]==-1){
      F[n-2]=mfib(n-2);
    }
    if(F[n-1]==-1){
      F[n-1]=mfib(n-1);
    }
    F[n]=F[n-1]+F[n-2];
    return F[n-1]+F[n-2];
  }
}

int I_fib(int n){
  int t0 = 0,t1 = 1,s;
  if(n<=1){
    return n;
  }
  for(int i=2;i<=n;i++){
    s = t0+t1;
    t0 = t1;
    t1 = s;
  }
  return s;
}
int main(){
  for(int i;i<10;i++){
    F[i]=-1;
  }
  
  int p = fib(6);
  cout<<p<<endl;

  int k = mfib(6);
  cout<<k<<endl;

  int m = I_fib(6);
  cout<<m<<endl;

  return 0;
}
