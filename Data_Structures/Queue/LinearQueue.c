//Linear queue
#include<stdio.h>
#include<stdlib.h>
int Q[50],FRONT=-1,REAR=-1,N;
void enqueue()
{
  int item;
  if(REAR==N-1)
  {
    printf("\nQueue is full\n");
  }
  else
  {
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&item);
    if(FRONT==-1 && REAR==-1)
    {
      FRONT=0;
    }
    REAR++;
    Q[REAR]=item;
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
    item=Q[FRONT];
    printf("Deleted element : %d\n",item);
    if(FRONT==REAR)
    {
      FRONT=-1;
      REAR=-1;
    }
    else
    {
      FRONT++;
    }
  }
}
void display()
{
  int i;
  printf("\nCurrent status of the queue :");
  for(i=FRONT;i<=REAR;i++)
  {
    printf(" %d ",Q[i]);
  }
  printf("\n");
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
