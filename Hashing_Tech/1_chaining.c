#include<stdio.h>
#include"chains.h"

int hash(int key)
{
  return key%10;
}

void Inserted(struct Node *H[],int key)
{
  int index = hash(key);
  SortedInsert(&H[index],key);

}


int main()
{
  struct Node *HT[10];
  int i;
  struct Node *temp;

  for(i=0;i<10;i++)
    HT[i]=NULL;

  Inserted(HT,12);
  Inserted(HT,22);
  Inserted(HT,42);

  temp = search(HT[hash(22)],22);
  printf("%d ",temp->data);

  return 0;

