//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *lchild,*rchild;
}*root=NULL;
void insert_bst()
{
  int item;
  struct node *x,*ptr,*parent;
  x=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&item);
  x->data=item;
  x->lchild=NULL;
  x->rchild=NULL;
  if(root==NULL)
  {
    root=x;
  }
  else
  {
    ptr=root;
    while(ptr!=NULL)
    {
      if(item<ptr->data)
      {
        parent=ptr;
        ptr=ptr->lchild;
      }
      else
      {
        parent=ptr;
        ptr=ptr->rchild;
      }
    }
    if(item<parent->data)
    {
      parent->lchild=x;
    }
    else
    {
      parent->rchild=x;
    }
  }
}
void search_bst()
{
  int item,flag=0;
  struct node *ptr;
  if(root==NULL)
  {
    printf("\nTree does not exist");
  }
  else
  {
    printf("\nEnter the element to be searched : ");
    scanf("%d",&item);
    ptr=root;
    while(ptr!=NULL&&flag==0)
    {
      if(item==ptr->data)
      {
        flag=1;
      }
      else if(item<ptr->data)
      {
        ptr=ptr->lchild;
      }
      else
      {
        ptr=ptr->rchild;
      }
    }
    if(flag==1)
    {
      printf("\nElement %d found\n",item);
    }
    else
    {
      printf("\nElement not found\n");
    }
  }
}
struct node* inorder_succ(struct node *ptr)
{
  struct node *ptr1;
  ptr1=ptr->rchild;
  while(ptr1->lchild!=NULL)
  {
    ptr1=ptr1->lchild;
  }
  return ptr1;
}
void delete_bst(int item)
{
  struct node *ptr,*ptr1,*parent;
  int item1,step=0,flag=0;
  if(root==NULL)
  {
    printf("\nTree does not exist");
  }
  else
  {
    ptr=root;
    while(ptr!=NULL&&flag==0)
    {
      if(item==ptr->data)
      {
        flag=1;
      }
      else if(item<ptr->data)
      {
        parent=ptr;
        ptr=ptr->lchild;
      }
      else
      {
        parent=ptr;
        ptr=ptr->rchild;
      }
    }
    if(flag==0)
    {
      printf("\nItem does not exist");
    }
    if(ptr->lchild==NULL&&ptr->rchild==NULL)
    {
      step=1;
    }
    else if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
    {
      step=3;
    }
    else
    {
      step=2;
    }
    if(step==1)
    {
      if(parent->rchild==ptr)
      {
        parent->rchild=NULL;
      }
      else
      {
        parent->lchild=NULL;
      }
      free(ptr);
    }
    else if(step==2)
    {
      if(parent->rchild==ptr)
      {
        if(ptr->lchild==NULL)
        {
          parent->rchild=ptr->rchild;
        }
        else
        {
          parent->rchild=ptr->lchild;
        }
      }
      else
      {
        if(ptr->lchild==NULL)
        {
          parent->lchild=ptr->rchild;
        }
        else
        {
          parent->lchild=ptr->lchild;
        }
      }
      free(ptr);
    }
    else if(step==3)
    {
      ptr1=inorder_succ(ptr);
      item1=ptr1->data;
      delete_bst(item1);
      ptr->data=item1;
    }
  }
}
void preorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
  }
}
void inorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    inorder(ptr->lchild);
    printf("%d ",ptr->data);
    inorder(ptr->rchild);
  }
}
void postorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->data);
  }
}
void traversal()
{
  int opt;
  struct node *x;
  do{
  printf("\n\t1.Preorder\n\t2.Inorder\n\t3.Postorder\n\t4.Exit\nEnter the choice : ");
  scanf("%d",&opt);
  x=root;
  switch(opt)
  {
    case 1 : preorder(x);
             break;
    case 2 : inorder(x);
             break;  
    case 3 : postorder(x);
             break;   
  }}while(opt<4);
}
int main()
{
  int ch,item;
  do{
  printf("\nBinary Search Tree\n\t1.Insertion\n\t2.Search\n\t3.Deletion\n\t4.Traversal\n\t5.Exit");
  printf("\nEnter the choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1 : insert_bst();
             break;
    case 2 : search_bst();
             break;
    case 3 : printf("\nEnter the element to be deleted : ");
             scanf("%d",&item);
             delete_bst(item);
             break;
    case 4 : traversal();
             break;
    case 5 : exit(0);
    default : printf("\nInvalid input!!!Enter the options 1-4");
  }
  }while(1);
  return 0;
}
