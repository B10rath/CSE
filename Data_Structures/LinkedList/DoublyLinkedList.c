//Doubly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next,*prev;
}*head=NULL,*tail=NULL;
void Insert_begin()
{
  int item;
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  newnode->data=item;
  newnode->prev=NULL;
  newnode->next=head;
  if(head!=NULL)
  {
    head->prev=newnode;
  }
  else
  {
    tail=newnode;
  }
  head=newnode;
}
void Insert_end()
{
  int item;
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  newnode->data=item;
  newnode->next=NULL;
  newnode->prev=tail;
  if(tail!=NULL)
  {
    tail->next=newnode;
  }
  else
  {
    head=newnode;
  }
  tail=newnode;
}
void Insert_pos()
{
  int item,pos,i;
  struct node *newnode,*temp,*loc;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  printf("\nEnter the position to be inserted : ");
  scanf("%d",&pos);
  newnode->data=item;
  if(pos==1)
  {
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
  }
  else
  {
    temp=head;
    loc=temp->next;
    for(i=1;i<pos-1;i++)
    {
      loc=loc->next;
      temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=loc;
    loc->prev=newnode;
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
    printf("\nDeleted element : %d",temp->data);
    if(head->next==NULL)
    {
      head=NULL;
    }
    else
    {
      head=head->next;
      head->prev=NULL;
    }
    free(temp);
  }
}
void Delete_end()
{
  struct node *temp;
  if(head==NULL)
  {
    printf("List is empty");
  }
  else
  {
    temp=tail;
    printf("\nDeleted element : %d",temp->data);
    if(head==tail)
    {
      head=tail=NULL;
    }
    else
    {
      tail=tail->prev;
      tail->next=NULL;
    }
    free(temp);
  }
}
void Delete_pos()
{
  struct node *temp,*loc,*temp1;
  int pos,i,count=1;
  printf("\nEnter the position from which the element to be deleted :");
  scanf("%d",&pos);
  temp1=head;
  while(temp1->next!=NULL)
  {
    count++;
    temp1=temp1->next;
  }
  if(head==NULL)
  {
    printf("List is empty");
  }
  else
  {
    if(pos==1)
    {
      Delete_begin();
    }
    else if(pos==count)
    {
      Delete_end();
    }
    else
    {
      temp=head;
      loc=temp->next;
      for(i=1;i<pos-1;i++)
      {
        temp=temp->next;
        loc=loc->next;
      }
      temp->next=loc->next;
      printf("\nDeleted element : %d",loc->data);
      free(loc);
      loc=temp->next;
      loc->prev=temp;
    }
  }
}
void DisplayF()
{
  struct node *temp;
  if(head==NULL)
  {
    printf("\nList is empty");
  }
  else
  {
    printf("\nThe elements of the list : ");
    temp=head;
    while(temp->next!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
  }
}
void DisplayB()
{
  struct node *temp;
  if(head==NULL)
  {
    printf("\nList is empty");
  }
  else
  {
    printf("\nThe elements of the list : ");
    temp=tail;
    while(temp->prev!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->prev;
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
  printf("\n\t1.Insert at begin\n\t2.Insert at end\n\t3.Insert at any position\n\t4.Delete from beginning\n\t5.Delete from end\n\t6.Delete from any position\n\t7.Forward Display\n\t8.Backward Display\n\t9.Exit\nEnter the choice : ");
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
    case 7 : DisplayF();
             break;
    case 8 : DisplayB();
             break;
    case 9 : exit(0);
             break;
    default : printf("\nInvalid input!!\n");
  }
  }while(1);
  return 0;
}
