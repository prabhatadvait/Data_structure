#include<iostream>
using namespace std;

void merge(int A[],int l,int mid,int h)
{
  int i,j,k;
  int B[h+1];
  i=l,j=mid+1,k=l;
  while(i<=mid && j<=h)
  {
    if(A[i]<A[j])
      B[k++]=A[i++];
    else
      B[k++]=A[j++];
  }
  for(;i<=mid;i++)
    B[k++]=A[i];
  for(;j<=h;j++)
    B[k++]=A[j];

  for(i=l;i<=h;i++)
    A[i]=B[i];
}

void ImergeSort(int A[],int n)
{
  int p,i,l,mid,h;
  for(p=2;p<=n;p=p*2)
  {
    for(i=0;i+p-1<n;i=i+p)
    {
      l=i;
      h=i+p-1;
      mid = (l+h)/2;
      merge(A,l,mid,h);
    }
  }
  if(p/2<n)
    merge(A,0,p/2-1,n-1);
}

void RmergeSort(int A[],int l,int h)
{
  int mid;
  if(l<h)
  {
    mid = (l+h)/2;
    RmergeSort(A,l,mid);
    RmergeSort(A,mid+1,h);
    merge(A,l,mid,h);
  }
}

int main()
{
  int A[]={11,13,7,10,16,8,24,5,18,2},n=10,i;

  RmergeSort(A,0,n-1);

  for(int i=0;i<n;i++)
    printf("%d ",A[i]);
  printf("\n");
      
  return 0;
}
