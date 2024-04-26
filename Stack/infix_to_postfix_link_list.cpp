#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
  char data;
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

char * InftoPost(char *infix)
{
  int i=0,j=0;
  char *postfix;
  int len = strlen(infix);
  postfix = (char *)malloc((len+2)*sizeof(char)); // len+2 b/c also pushing #

  push('#');// intially it is empty so avoid error in inftoPost function
  
  while(infix[i]!='\0')
  {
    if(isOperand(infix[i]))
      postfix[j++]=infix[i++];
    else{
      if(pre(infix[i])>pre(top->data))
        push(infix[i++]);
      else{
        postfix[j++] = pop();
      }
    }
  }
  while(top!=NULL && top->data != '#')
  {
    postfix[j++]=pop();
  }
  postfix[j]='\0';
  return postfix;
}

int main()
{
  char *infix = "a+b*c";
  
  char *postfix = InftoPost(infix);
  printf("%s",postfix);

  return 0;
}
