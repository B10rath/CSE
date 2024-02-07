//Linked Queue

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*FRONT=NULL,*REAR=NULL;
void enqueue()
{
  int item;
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  newnode->data=item;
  newnode->link=NULL;
  if(FRONT==NULL && REAR==NULL)
  {
    FRONT=REAR=newnode;
  }
  else
  {
    REAR->link=newnode;
    REAR=newnode;
  }
}
void dequeue()
{
  struct node *temp;
  if(FRONT==NULL)
  {
    printf("\nQueue is empty");
  }
  else
  {
    temp=FRONT;
    printf("\nDeleted element : %d",temp->data);
    if(FRONT==REAR)
    {
      FRONT=REAR=NULL;
    }
    else
    {
      FRONT=FRONT->link;
    }
    free(temp);
  }
}
void display()
{
  struct node *temp;
  if(FRONT==NULL)
  {
    printf("\nQueue is empty");
  }
  else
  {
    temp=FRONT;
    printf("\nElements of the queue : ");
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->link;
    }
  }
  printf("\n");
}
int main()
{
  int ch;
  do
  {
    printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit\nEnter the choice :");
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
               break;
      default : printf("\nInvalid input!!!Enter choices 1-4");
    }
  }while(1);
  return 0;
}
