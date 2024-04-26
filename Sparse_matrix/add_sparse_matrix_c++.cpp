#include<iostream>
using namespace std;

class Element{
public:
  int i;
  int j;
  int x;
};
class Sparse{
private:
  int m;
  int n;
  int non;
  Element *ele;
public:
  Sparse(int m,int n,int non){
    this->m = m;
    this->n =n;
    this->non = non;
    ele = new Element[this->non];
  }
  ~Sparse(){
    delete [] ele;
  }
  void read(){
    for(int i=0;i<non;i++){
      cin>>ele[i].i>>ele[i].j>>ele[i].x;
    }
  }
  void display(){
    int k=0;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(ele[k].i == i && ele[k].j == j){
          cout<<ele[k++].x<<" ";
        }
        else{
          cout<<"0 ";
        }
      }
      cout<<endl;
    }
  }

};

int main(){
  Sparse s1(5,5,5);
  s1.read();
  s1.display();

  return 0;
}
