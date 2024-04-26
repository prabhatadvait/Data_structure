#include<iostream>
using namespace std;
template <class T>
class Array
{
  private:
    T *A;
    int size;
    int length;
  public:
    Array(){
      size = 10;
      A  = new T[10];
      length  = 0;
    }
    Array(int sz){
      size = sz;
      A = new T[size];
      length = 0;
    }
    ~Array(){
      delete []A;
    }
    void Display();
    void Insert(int index,T x);
    T Delete(int index);
};
template <class T>
void Array<T>:: Display(){
  for(int i=0;i<length;i++){
    cout<<A[i]<<endl;
  }
}

template <class T>
void Array<T> :: Insert(int index,T x){
  if(index>=0 && index<=length){
    for(int i=length;i>=index;i--){
      A[i] = A[i-1];
    }
    A[index] = x;
    length++;
  }
}
template<class T>
T Array<T> :: Delete(int index){

  if(index>=0 && index<length){
   int x = A[index];
    for(int i=index;i<length;i++){
      A[i] = A[i+1];
    }
    length--;
    return x;
  }
  return -1;
}
int main(){
  Array<int> arr(10);
  for(int i=0;i<5;i++){
    arr.Insert(i,i+1);
  }
  arr.Display();

  printf("%d\n",arr.Delete(1));
  arr.Display();

  return 0;
}

