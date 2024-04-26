#include<iostream>
#include "headc++.h"
using namespace std;

class Tree
{
  public:
    Node *root;
    Tree(){root=NULL;}
    void createTree();
    //if root is private
    //preorder(){preorder(root);}
    void preorder(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    void Levelorder(Node *root);
    int Height(Node *root);
};

void Tree :: createTree()
{ 
  Node *p,*t;
  int x;
  Queue q(100);

  printf("Enter the root value: ");
  scanf("%d",&x);
  root = new Node;
  root->data = x;
  root->lchild = root->rchild = NULL;
  q.enqueue(root);

  while(!q.isEmpty())
  {
    p=q.dequeue();
    printf("Enter the leftchild %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.enqueue(t);
    }

    printf("Enter the right child %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    { 
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.enqueue(t);
    }
  }
}
void Tree ::  preorder(Node * p)
{
  if(p){
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void Tree :: inorder(Node * p)
{
  if(p){
    inorder(p->lchild);
    printf("%d ",p->data);
    inorder(p->rchild);
  }
}

void Tree ::postorder(Node *p)
{
  if(p)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ",p->data);
  }
}

void Tree :: Levelorder(Node *root)
{
  Queue q(100);
  cout<<root->data<<" "<<endl;
  q.enqueue(root);

  while(!q.isEmpty())
  {
    root = q.dequeue();
    if(root->lchild)
    {
      cout<<root->lchild->data<<" ";
      q.enqueue(root->lchild);
    }
    if(root->rchild)
    {
      cout<<root->rchild->data<<" ";
      q.enqueue(root->rchild);
    }
  }
}

int Tree :: Height(Node *root)
{
  int x=0,y=0;
  if(root==0){
    return 0;
  }
  x=Height(root->lchild);
  y=Height(root->rchild);
  if(x>y){
    return x+1;
  }
  else {
    return y+1;
  }
}

int main(){
  Tree t;
  t.createTree();
  t.preorder(t.root);

}
