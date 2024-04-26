#include<iostream>
using namespace std;

void shellshort(int A[],int n)
{
  int gap,i,j;
  
  for(gap=n/2;gap>=1;gap/=2)
  {
    for(i=gap;i<n;i++)
    {
      int temp = A[i];
      j=i-gap;
      while(j>=0 && A[j]>temp)
      {
        A[j+gap]=A[j];
        j=j-gap;
      }
      A[j+gap]=temp;
    }
  }
}


int main()
{
  int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

  shellshort(A,n);

  for(i=0;i<n;i++)
  {
    printf("%d ",A[i]);
  }
  printf("\n");
}
