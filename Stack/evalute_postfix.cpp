#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*top=NULL;

void push(int x)
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

int pop()
{
  struct Node *t;
  int x=-1;
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


int pre(char x)
{
  if(x=='+' || x== '-')
  {
    return 1;
  }
  else if(x== '*' || x== '/')
  {
    return 2;
  }
  else {
    return 0;
  }
}

int isOperand(char x)
{
  if(x=='+' || x=='-' || x=='*' || x=='/')
    return 0;
  else
    return 1;
}


int Evaluate(char *postfix)
{
  int i=0;
  int x1,x2,r;
  for(i=0;postfix[i]!='\0';i++)
  {
    if(isOperand(postfix[i]))
    {
      push(postfix[i]-'0');
    }
    else
    {
      x2=pop();
      x1=pop();
      switch(postfix[i])
      {
        case '+': r=x1+x2; break;
        case '-': r=x1-x2; break;
        case '*':r=x1*x2; break;
        case '/':r=x1/x2; break;
      }
      push(r);
    }
  
  }
  return top->data;
}
int main()
{
 char *postfix = "234*+82/-";
 printf("The result is %d\n",Evaluate(postfix));

  return 0;
}
