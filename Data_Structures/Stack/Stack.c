//stack
#include<stdio.h>
#include<stdlib.h>
int S[50],TOP=-1,N;
void push()
{
  int item;
  if(TOP>=N-1)
  {
    printf("STACK is FULL");
  }
  else
  {
    printf("Enter the element to pushed:");
    scanf("%d",&item);
    TOP++;
    S[TOP]=item;
  }
  printf("\n");
}
void pop()
{
  int item;
  if(TOP<=-1)
  {
    printf("STACK is EMPTY");
  }
  else
  {
    item=S[TOP];
    printf("Popped element: %d\n",item);
    TOP--;
  }
  printf("\n");
}
void display()
{
  int i;
  printf("Current status of the STACK: ");
  for(i=TOP;i>=0;i--)
  {
    printf("%d ",S[i]);
  }
  printf("\n");
}
int main()
{
  int i,ch;
  printf("Enter the stack size:");
  scanf("%d",&N);
  do
  {
    printf("\t1.PUSH\n\t2,POP\n\t3.DISPLAY\n\t4.EXIT");
    printf("\nEnter an option: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: push();
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: exit(0);
      default: printf("Invalid input");
    }    
  }while(1);
  return 0;
}
