#include<iostream>
using namespace std;

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q)
{
  printf("Enter the size of queue\n");
  scanf("%d",&q->size);
  q->front = q->rear = 0;
  q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
  if((q->rear+1)%q->size == q->front)
  {
    printf("Queue is full\n");
  }
  else
  {
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q)
{
  int x=-1;
  if(q->rear==q->front)
  {
    printf("Queue is empty\n");
  }
  else
  {
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
  }
  return x;
}

void display(struct Queue q)
{
  int i=q.front+1;
  do
  {
    printf("%d ",q.Q[i]);
    i=(i+1)%q.size;
  }while(i!=(q.rear+1)%q.size);
  printf("\n");
}


int main()
{
  struct Queue q;
  create(&q);

  enqueue(&q,1);
  enqueue(&q,2);
  enqueue(&q,3);

 printf("%d",dequeue(&q));
  printf("\n");
  display(q);
  
  return 0;
}
