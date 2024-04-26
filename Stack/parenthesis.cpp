#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*top=NULL;

void push(char x)
{
  struct Node *t;
  t=(struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
  {
    printf("Stack is overflow/n");
  }
  else
  {
    t->data=x;
    t->next = top;
    top=t;
  }
}

char pop()
{
  struct Node *t;
  char x=-1;
  if(top==NULL)
  {
    printf("stack is empty ");
  }
  else
  {
    t=top;
    x=t->data;
    top=top->next;
    delete t;
  }
  return x;
}

void display(struct Node *p)
{
  p=top;
  if(top==NULL)
  {
    printf("Stack is empty");
  }
  else
  {
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
    printf("\n");
  }
}

int isBalanced(char *exp)
{
  int i;
  for(int i=0;exp[i]!='\0';i++){
    if(exp[i]=='('){
      push(exp[i]);
    }
    else if(exp[i]==')'){
      if(top==NULL)
      {
        return 0;
      }
      pop();
    }
  }
  if(top==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

int main()
{
  char *exp ="((a+b)*(c-d)))";
  cout<<isBalanced(exp)<<endl;

  return 0;
}
