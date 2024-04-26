#include<iostream>
using namespace std;

double e(int x, int n){
  static double p=1,f=1;
  double r;
  if(n==0){
    return 1;
  }
  else{
    r = e(x,n-1);
    p = p*x;
    f = f*n;
    return r+p/f;
  }
}

double r_exp(int x,int n){
  static double s;
  if(n==0){
    return s;
  }
  s = 1+x*s/n;
  return r_exp(x,n-1);
}

double I_exp(int x, int n){
  double den=1,num=1;
  double k=1;
  for(int i=1;i<n;i++){
    num *=x;
    den *=i;
    k+=num/den;
  }
  return k;
}

int main(){
  double p= e(1,10);
  cout<<p<<endl;
  double q = r_exp(1,10);
  cout<<q<<endl;
  double I = I_exp(1,10);
  cout<<I<<endl;
  return 0;
}
