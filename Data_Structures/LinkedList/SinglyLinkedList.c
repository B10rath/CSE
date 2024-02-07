//Singly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*head=NULL;
void Insert_begin()
{
  int item;
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  newnode->data=item;
  if(head==NULL)
  {
    newnode->link=NULL;
    head=newnode;
  }
  else
  {
    newnode->link=head;
    head=newnode;
  }
}
void Insert_end()
{
  int item;
  struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  newnode->data=item;
  newnode->link=NULL;
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
    temp=head;
    while(temp->link!=NULL)
    {
      temp=temp->link;
    }
    temp->link=newnode;
  }
}
void Insert_pos()
{
  int item,pos,i;
  struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  printf("\nEnter the position to be inserted : ");
  scanf("%d",&pos);
  newnode->data=item;
  if(pos==1)
  {
    newnode->link=head;
    head=newnode;
  }
  else
  {
    temp=head;
    for(i=1;i<pos-1;i++)
    {
      temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;
  }
}
void Delete_begin()
{
  struct node *temp;
  if(head==NULL)
  {
    printf("List is empty");
  }
  else
  {
    temp=head;
    head=head->link;
    printf("\nDeleted element : %d",temp->data);
    free(temp);
  }
}
void Delete_end()
{
  struct node *temp,*loc;
  if(head==NULL)
  {
    printf("List is empty");
  }
  else
  {
    if(head->link==NULL)
    {
      temp=head;
      printf("\nDeleted element : %d",head->data);
      head=head->link;
      free(temp);
    }
    else
    {
      temp=head;
      loc=temp->link;
      while(loc->link!=NULL)
      {
        temp=temp->link;
        loc=loc->link;
      }
      temp->link=NULL;
      printf("\nDeleted element : %d",loc->data);
      free(loc);
    }
  }
}
void Delete_pos()
{
  struct node *temp,*loc;
  int pos,i;
  printf("\nEnter the position from which the element to be deleted :");
  scanf("%d",&pos);
  if(pos==1)
  {
    temp=head;
    head=head->link;
    printf("\nDeleted element : %d",temp->data);
    free(temp);
  }
  else
  {
    temp=head;
    loc=temp->link;
    for(i=1;i<pos-1;i++)
    {
      temp=temp->link;
      loc=loc->link;
    }
    temp->link=loc->link;
    printf("\nDeleted element : %d",loc->data);
    free(loc);
  }
}
void Display()
{
  struct node *temp;
  if(head==NULL)
  {
    printf("\nList is empty");
  }
  else
  {
    printf("\nCurrent status of the list : ");
    temp=head;
    while(temp->link!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->link;
    }
    printf("%d",temp->data);
    printf("\n");
  }
}
int main()
{
  int ch;
  do
  {
  printf("\n\t1.Insert at begin\n\t2.Insert at end\n\t3.Insert at any position\n\t4.Delete from beginning\n\t5.Delete from end\n\t6.Delete from any position\n\t7.Display\n\t8.Exit\nEnter the choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1 : Insert_begin();
             break;
    case 2 : Insert_end();
             break;
    case 3 : Insert_pos();
             break;
    case 4 : Delete_begin();
             break;
    case 5 : Delete_end();
             break;
    case 6 : Delete_pos();
             break;
    case 7 : Display();
             break;
    case 8 : exit(0);
             break;
    default : printf("\nInvalid input!!\n");
  }
  }while(1);
  return 0;
}
