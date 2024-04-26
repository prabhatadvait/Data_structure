#include<iostream>
// #include "head.h"
#include "head_stack.h"
using namespace std;

struct Node *root = NULL;

void Treecreate()
{
  struct Node *p,*t;
  int x;
  struct Queue q;
  create(&q);

  printf("Enter the root value: ");
  scanf("%d",&x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q,root);

  while(!isEmpty(q))
  {
    p=dequeue(&q);
    printf("Enter the leftchild %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q,t);
    }

    printf("Enter the right child %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(&q,t);
    }
  }
}

void preorder(struct Node * p)
{
  if(p){
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void inorder(struct Node * p)
{
  if(p){
    inorder(p->lchild);
    printf("%d ",p->data);
    inorder(p->rchild);
  }
}

void postorder(struct Node *p)
{
  if(p)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ",p->data);
  }
}

void Itpreorder(struct Node *p)
{
  struct stack st;
  createstack(&st,100);
  while(p || !isempty(st)){
    if(p){
      printf("%d ",p->data);
      push(&st,p);
      p = p->lchild;
    }
    else {
      p = pop(&st);
      p = p->rchild;
    }
  }
}

void Itinorder(struct Node *p)
{
  struct stack st;
  createstack(&st,100);
  while(p || !isempty(st)){
    if(p){
      push(&st,p);
      p = p->lchild;
    }
    else {
      p = pop(&st);
      printf("%d ",p->data);
      p = p->rchild;
    }
  }
}


void Itpostorder (struct Node *p)
{
  struct stack st;
  long int temp;
  createstack(&st,100);
  while(p || !isempty(st)){
    if(p){
      push(&st,p);
      p = p->lchild;
    }
    else {
      temp = pop(&st);
      if(temp>0){
        push(&st,-temp);
        p=((Node *)temp)->rchild;
      }
      else{
        printf("%d ",((Node *)temp)->data);
        p=NULL;
      }
    }
  }
}*/

void levelorder(struct Node *p)
{
  struct Queue q;
  create(&q);
  printf("%d ",p->data);
  enqueue(&q,p);
  while(!isEmpty(q)){
    p = dequeue(&q);
    if(p->lchild){
      printf("%d ",p->lchild->data);
      enqueue(&q,p->lchild);
    }
    if(p->rchild){
      printf("%d ",p->rchild->data);
      enqueue(&q,p->rchild);
    }
  }
}

int count(struct Node *p)
{
  if(p){
   int x= count(p->lchild);
   int y = count(p->rchild);
    return x+y+1;
  }
  return 0;
}

int height(struct Node *p)
{
  int x=0,y=0;
  if(p==0){
    return 0;
  }
  x=height(p->lchild);
  y=height(p->rchild);
  if(x>y){
    return x+1;
  }
  else{
    return y+1;
  }
}

int main()
{
  Treecreate();
  printf("%d ",count(root));
  printf("%d ",height(root));
  return 0;
}
