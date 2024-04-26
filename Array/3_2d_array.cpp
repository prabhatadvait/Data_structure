#include<iostream>
using namespace std;


int main(){
  int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};
  
  int *B[3];
  B[0] = (int *)malloc(4*sizeof(int));
  B[1] = (int *)malloc(4*sizeof(int));
  B[2] = (int *)malloc(4*sizeof(int));


  int **c;
  c = new int*[3];
  c[0] = new int[4];
  c[1] = new int[4];
  c[2] = new int[4];

  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      cout<<c[i][j]<<endl;
    }
  }
  return 0;
}
