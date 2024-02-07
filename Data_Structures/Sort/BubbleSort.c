//Program to implement Bubble sort

#include<stdio.h>
int main()
{
  int ar[50],i,n,temp,j;
  printf("Enter the array limit:");
  scanf("%d",&n);
  printf("\nEnter the elements of the array:\t");
  for(i=0;i<n;i++)
  { 
    scanf("%d",&ar[i]);
  }
  printf("\nThe array is\t");
  for(i=0;i<n;i++)
  {
    printf("%d ",ar[i]);
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(ar[j]>ar[j+1])
      {
        temp=ar[j];
        ar[j]=ar[j+1];
        ar[j+1]=temp;
      }
    }
  }
  printf("\nSorted array: ");
  for(i=0;i<n;i++)
  {
    printf("%d ",ar[i]);
  }
  printf("\n");
  return 0;
} 
