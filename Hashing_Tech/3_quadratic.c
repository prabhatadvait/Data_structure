#include<stdio.h>
#define SIZE 10

int hash(int key)
{
  return (key%SIZE);
}

int probe(int H[],int key)
{
  int i=0;
  int index = hash(key);
  while(H[(index+i*i)%SIZE]!=0)
    i++;
  return (index+i*i)%SIZE;
}

void Insert(int H[],int key)
{
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

  while(H[(index+i*i)%SIZE]!=key){
    i++;
    count = count+1;
    if(count>=10)
      return -1;
  }
  if(H[(index+i*i)%SIZE]==key)
    return (index+i*i)%SIZE;
}

int main()
{
  int HT[10]={0};

  Insert(HT,23);
  Insert(HT,43);
  Insert(HT,13);
  Insert(HT,27);

  printf("key found at %d ",search(HT,13));

  return 0;
}
