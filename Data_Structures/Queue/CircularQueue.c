//Circular queue
#include<stdio.h>
#include<stdlib.h>
int CQ[50],FRONT=-1,REAR=-1,N;
void enqueue()
{
  int item,next=0;
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  if(REAR==-1)
  {
    FRONT=0;
    REAR=0;
    CQ[REAR]=item;
  }
  else
  {
    next=(REAR+1)%N;
    if(FRONT==next)
    {
      printf("\nQueue is full\n");
    }
    else
    {
      REAR=(REAR+1)%N;
      CQ[REAR]=item;
    }
  }
}
void dequeue()
{
  int item;
  if(FRONT==-1)
  {
    printf("\nQueue is empty\n");
  }
  else
  {
    item=CQ[FRONT];
    printf("Deleted element : %d\n",item);
    if(FRONT==REAR)
    {
      FRONT=-1;
      REAR=-1;
    }
    else
    {
      FRONT=(FRONT+1)%N;
    }
  }
}
void display()
{
  int i;
  printf("\nCurrent status of the queue :");
  if(FRONT==-1)
  {
    printf("\nQueue is empty\n");
  }
  else
  {
    i=FRONT;
    while(i!=REAR)
    {
      printf(" %d ",CQ[i]);
      i=(i+1)%N;
    }
    printf(" %d ",CQ[i]);
    printf("\n");
  }
}
int main()
{
  int ch;
  printf("Enter the queue size :");
  scanf("%d",&N);
  do
  {
  printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
  printf("\nEnter the choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1 : enqueue();
             break;
    case 2 : dequeue();
             break;
    case 3 : display();
             break;
    case 4 : exit(0);
    default : printf("\nInvalid input\n");
  }
  }while(1);
  printf("\n");
  return 0;
}
