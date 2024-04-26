#include<iostream>
using namespace std;

struct Stack
{
  int size;
  int top;
  int *S;
};

void create(struct Stack *st)
{
  st->top=-1;
  printf("Enter the size of Stack ");
  scanf("%d",&st->size);
  st->S=(int *)malloc(st->size*sizeof(int));

}

void push(struct Stack *st,int x)
{
  if(st->top==st->size-1)
  {
    printf("Stack overflow ");
  }
  else
  {
    st->top++;
    st->S[st->top]=x;
  }
}

int pop(struct Stack *st)
{
  int x=-1;
  if(st->top==-1)
  {
    printf("Stack underflow ");
  }
  else
  {
    x=st->S[st->top--];
  }
  return x;
}

int peek(struct Stack st,int pos)
{
  int x=-1;
  if(st.top-pos+1<0)
  {
    printf("Invalid position ");
  }
  else
  {
    x=st.S[st.top-pos+1];
  }
  return x;
}

int isEmpty(struct Stack st)
{
  if(st.top==-1)
    return 1;
  return 0;
}

int isFull(struct Stack st)
{
  return st.top==st.size-1;
}

int stackTop(struct Stack st)
{
  if(!isEmpty(st))
  {
    return st.S[st.top];
  }
  return -1;
}
void display(struct Stack st)
{
  if(st.top==-1)
  {
    printf("Stack is empty ");
  }
  else
  {
    for(int i=st.top;i>=0;i--)
    {
      printf("%d ",st.S[i]);
    }
    printf("\n");
  }
}


int main()
{
  struct Stack st;
  create(&st);

  push(&st,10);
  push(&st,20);
  push(&st,30);
  push(&st,40);

  printf("%d\n",stackTop(st));
  
  display(st);
  printf("\n%d ",isFull(st));
  
  return 0;
}
