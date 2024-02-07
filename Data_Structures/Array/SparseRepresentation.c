//Sparse Triplet Representstion
#include<stdio.h>
int main()
{
  int A[20][20],i,j,r,c,nonzero=0,sp[20][20];
  printf("Enter the number of rows and columns of the matrix:");
  scanf("%d%d",&r,&c);
  printf("Enter the matrix elements:");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d",&A[i][j]);
    }
  }
  printf("Entered matrix:");
  for(i=0;i<r;i++)
  {
    printf("\n");
    for(j=0;j<c;j++)
    {
      printf("%d ",A[i][j]);
    }
  }
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(A[i][j]!=0)
      {
        nonzero++;
        sp[nonzero][0]=i;
        sp[nonzero][1]=j;
        sp[nonzero][2]=A[i][j];
      }
    }
  }
  sp[0][0]=r;
  sp[0][1]=c;
  sp[0][2]=nonzero;
  printf("\n");
  printf(" Sparse Triplet representation:");
  for(i=0;i<=nonzero;i++)
  {
    printf("\n");
    for(j=0;j<=2;j++)
    {
      printf("%d ",sp[i][j]);
    }
  }
  printf("\n");
  return 0;
}
