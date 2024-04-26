#include<iostream>
using namespace std;

int sum(int n){
  if (n==0){
    return 0;
  }
  return sum(n-1)+n;
}
int Isum(int n){
  int s=0;
  for(int i=1;i<=n;i++){
    s= s+i;
  }
  return s;
}
int main(){
  int p;
  p=sum(5);
  cout<<p<<endl;

  int k = Isum(5);
  cout<<k<<endl;
}
