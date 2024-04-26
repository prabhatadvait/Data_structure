#include<iostream>
using namespace std;

class Node{
public:
  Node *rchild;
  int data;
  Node *lchild;
};

class Queue{
private:
  int front;
  int rear;
  int size;
  Node **Q;
  public:
  Queue(int size){front = rear=-1;size = 10;this->size = size;Q=new Node*[this->size];}
  void enqueue(Node * x);
  Node * dequeue();
  int isEmpty();
};

void Queue :: enqueue(Node * x)
{
  if(rear == size-1)
  {
    printf("Queue is full\n");
  }
  else {
    rear++;
    Q[rear] = x;
  }
}

Node * Queue:: dequeue()
{
  Node *x = NULL;
  if(rear == front)
  {
    cout<<"Queue is empty"<<endl;
  }
  else
  {
  x = Q[front+1];
  front++;
  }
  return x;
}

int Queue:: isEmpty()
{
  return rear==front;
}

