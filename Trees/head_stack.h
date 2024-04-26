#include<iostream>
using namespace std;
#include "head.h"

struct stack
{
  int size;
  int top;
  struct Node **s;
};

void createstack(struct stack *st,int size)
{
  st->size = size;
  st->top=-1;
  st->s = (struct Node **)malloc(st->size*sizeof(Node *));
}

void push(struct stack *st,Node * x)
{
  if(st->top==st->size-1)
  {
    printf("stack overflow ");
  }
  else {
    st->top++;
    st->s[st->top] = x;
  }
}

Node * pop(struct stack *st)
{
  struct Node * x = NULL;
  if(st->top==-1)
  {
    printf("stack is empty ");
  }
  else{
    x=st->s[st->top--];
  }
  return x;
}

int isempty(struct stack st)
{
  if(st.top== -1)
    return 1;
  else
    return 0;
}

