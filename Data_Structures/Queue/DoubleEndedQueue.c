//Double Ended Queue
#include<stdio.h>
#include<stdlib.h>
int DQ[50],FRONT=-1,REAR=-1,N;
void Inject()
{
  int item,next;
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  if(FRONT==-1)
  {
    FRONT=0;
    REAR=0;
    DQ[REAR]=item;
  }
  else
  {
    next=(REAR+1)%N;
    if(next==FRONT)
    {
      printf("\nDQ is full");
    }
    else
    {
      REAR=(REAR+1)%N;
      DQ[REAR]=item;
    }
  }
}
void Eject()
{
  int item;
  if(FRONT==-1)
  {
    printf("\nDQ is empty");
  }
  else
  {
    item=DQ[REAR];
    printf("\nDeleted element : %d ",item);
    if(FRONT==REAR)
    {
      FRONT=-1;
      REAR=-1;
    }
    else
    {
      if(REAR==0)
      {
        REAR=N-1;
      }
      else
      {
        REAR=REAR-1;
      }
    }
  }
}
void PushDQ()
{
  int item,temp;
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  if(FRONT==-1)
  {
    FRONT=0;
    REAR=0;
    DQ[FRONT]=item;
  }
  else
  {
    if(FRONT==0)
    {
      temp=N-1;
    }
    else
    {
      temp=FRONT-1;
    }
    if(temp==REAR)
    {
      printf("\nDQ is full");
    }
    else
    {
      FRONT=temp;
      DQ[FRONT]=item;
    }
  }
}
void PopDQ()
{
  int item;
  if(FRONT==-1)
  {
    printf("\nDQ is empty");
  }
  else
  {
    item=DQ[FRONT];
    printf("\nDeleted element : %d",item);
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
void Display()
{
  int i;
  if(FRONT==-1)
  {
    printf("\nDQ is empty");
  }
  else
  {
    i=FRONT;
    printf("\nCurrent status of the queue : ");
    while(i!=REAR)
    {
      printf("%d ",DQ[i]);
      i=(i+1)%N;
    }
    printf("%d",DQ[i]);
    printf("\n");
  }
}
int main()
{
  int ch;
  printf("\nEnter the maximum size of the queue : ");
  scanf("%d",&N);
  do
  {
    printf("\n\t1.Inject\n\t2.Eject\n\t3.PushDQ\n\t4.PopDQ\n\t5.Display\n\t6.Exit\nEnter the choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : Inject();
               break;
      case 2 : Eject();
               break;
      case 3 : PushDQ();
               break;
      case 4 : PopDQ();
               break;
      case 5 : Display();
               break;
      case 6 : exit(0);
      default : printf("\nInvalid input!!!Enter choices 1-6");
    }
  }while(1);
  printf("\n");
  return 0;
}
