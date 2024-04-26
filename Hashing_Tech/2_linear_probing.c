#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int hash(int key)
{
  return key%SIZE;
}

int probe(int H[],int key)
{
  int index = hash(key);
  int i=0;
  while(H[(index+i)%SIZE]!=0)
    i++;
  return (index+i)%SIZE;
}

void Insert(int H[],int key)
{
  int i=0;
  int index = hash(key);
  if(H[index]!=0)
    index = probe(H,key);
  H[index]=key;
}

int search(int H[],int key)
{
  int index = hash(key);
  int i=0;
  int count = 0;


  while(H[(index+i)%SIZE]!=key){
    i++;
    count = count+1;
    if(count>=10)
      return -1;
  }
  if(H[(index+i)%SIZE]==key)
    return (index+i)%SIZE;
}

int main()
{
  int HT[10]={0};
  int n;

  for(int i=0;i<5;i++)
  {
    printf("Enter the number: ");
    scanf("%d",&n);
    Insert(HT,n);
  }
  
  printf("\nkey found at %d\n",search(HT,42));

  return 0;
}
