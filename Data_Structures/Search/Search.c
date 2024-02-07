//Linear search and Binary search 
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int A[50],i,j,n,key,flag=0,c=0,opt,temp,low,high,mid;
  do
  {
  printf("\n\t1.Linear search\n\t2.Binary search\n\t3.Exit");
  printf("\nEnter an option: ");
  scanf("%d",&opt);
  switch(opt)
  {
    case 1 : printf("Enter the array limit:");
             scanf("%d",&n);
             printf("Enter the array elements:");
             for(i=0;i<n;i++)
             {
               scanf("%d",&A[i]);
             }
             printf("\nEnter the element to be searched:");
             scanf("%d",&key);
             printf("The entered array is:\t");
             for(i=0;i<n;i++)
             {
               printf("%d ",A[i]);
             }
             for(i=0,j=0;i<n;i++)
             {
                if(A[i]==key)
                {
                  flag=1;
                  c++;
                }
             }
             printf("\n");
             if(flag==1)
             { 
               printf("Element %d found %d times\n",key,c);
             }
             else
             {
               printf("Element not found\n");
             }
             break;
    case 2 : printf("Enter the array limit:");
             scanf("%d",&n);
             printf("Enter the array elements:");
             for(i=0;i<n;i++)
             {
               scanf("%d",&A[i]);
             }
             printf("\nEnter the element to be searched:");
             scanf("%d",&key);
             printf("The entered array is:\t");
             for(i=0;i<n;i++)
             { 
                printf("%d ",A[i]);
             }
             for(i=0;i<n;i++)
             {
              for(j=0;j<n-i-1;j++)
              {
                if(A[j]>A[j+1])
                {
                  temp=A[j];
                  A[j]=A[j+1];
                  A[j+1]=temp;
                }
              }
            }
            printf("\nSorted array is : ");
            for(i=0;i<n;i++)
            {
              printf("%d ",A[i]);
            }
            low=0;
            high=n-1;
            while(low<=high)
            {
              mid=(low+high)/2;
              if(A[mid]==key)
              {
                flag=1;
                break;
              }
              else if(key>A[mid])
              {
                low=mid+1;
              }
              else if(key<A[mid])
              {
                high=mid-1;
              }
            }
            if(flag==1)
            {
              printf("\nElement %d found at position %d\n",key,mid+1);
            } 
            else
            {
              printf("Element not found\n");
            }
            break;
    case 3 : exit(0);
             break;
    default :printf("Invalid option\n");
  }
  }while(1);
  return 0;      
}
