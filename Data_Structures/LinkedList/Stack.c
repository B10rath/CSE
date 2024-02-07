//Linked Stack

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*TOP=NULL;
void push()
{
  int item;
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  newnode->data=item;
  if(TOP==NULL)
  {
    newnode->link=NULL;
    TOP=newnode;
  }
  else
  {
    newnode->link=TOP;
    TOP=newnode;
  }
}
void pop()
{
  struct node *temp;
  if(TOP==NULL)
  {
    printf("\nStack is empty");
  }
  else
  {
    temp=TOP;
    TOP=TOP->link;
    printf("\nPopped element : %d",temp->data);
    free(temp);
  }
}
void display()
{
  struct node *temp;
  if(TOP==NULL)
  {
    printf("\nStack is empty");
  }
  else
  {
    temp=TOP;
    printf("\nElements of the Stack : ");
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
    printf("\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit");
    printf("\nEnter the choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : push();
               break;
      case 2 : pop();
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
