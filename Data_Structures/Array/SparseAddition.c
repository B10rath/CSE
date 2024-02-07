//Sparse matrix Addition
#include<stdio.h>
int main()
{
  int A[20][20],B[20][20],C[20][20],i,j,k=0,r1,c1,r2,c2,nonzeroA=0,nonzeroB=0,spA[20][20],spB[20][20],t1=0,t2=0;
  printf("Enter the number of rows and columns of the matrix A:");
  scanf("%d%d",&r1,&c1);
  printf("Enter the matrix elements of A:");
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c1;j++)
    {
      scanf("%d",&A[i][j]);
    }
  }
  printf("Enter the number of rows and columns of the matrix B:");
  scanf("%d%d",&r2,&c2);
  printf("Enter the matrix elements of B:");
  for(i=0;i<r2;i++)
  {
    for(j=0;j<c2;j++)
    {
      scanf("%d",&B[i][j]);
    }
  }
  printf("Entered matrix A:");
  for(i=0;i<r1;i++)
  {
    printf("\n");
    for(j=0;j<c1;j++)
    {
      printf("%d ",A[i][j]);
    }
  }
  printf("\n");
  printf("Entered matrix B:");
  for(i=0;i<r2;i++)
  {
    printf("\n");
    for(j=0;j<c2;j++)
    {
      printf("%d ",B[i][j]);
    }
  }
  printf("\n");
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c1;j++)
    {
      if(A[i][j]!=0)
      {
        nonzeroA++;
        spA[nonzeroA][0]=i;
        spA[nonzeroA][1]=j;
        spA[nonzeroA][2]=A[i][j];
      }
    }
  }
  spA[0][0]=r1;
  spA[0][1]=c1;
  spA[0][2]=nonzeroA;
  printf("Sparse Triplet representation of A:");
  for(i=0;i<=nonzeroA;i++)
  {
    printf("\n");
    for(j=0;j<=2;j++)
    {
      printf("%d ",spA[i][j]);
    }
  }
  printf("\n");
  for(i=0;i<r2;i++)
  {
    for(j=0;j<c2;j++)
    {
      if(B[i][j]!=0)
      {
        nonzeroB++;
        spB[nonzeroB][0]=i;
        spB[nonzeroB][1]=j;
        spB[nonzeroB][2]=B[i][j];
      }
    }
  }
  spB[0][0]=r2;
  spB[0][1]=c2;
  spB[0][2]=nonzeroA;
  printf("Sparse Triplet representation of B:");
  for(i=0;i<=nonzeroB;i++)
  {
    printf("\n");
    for(j=0;j<=2;j++)
    {
      printf("%d ",spB[i][j]);
    }
  }
  printf("\n");
  t1=spA[0][2];
  t2=spB[0][2];
  i=1;j=1;k=1;
  if((spA[0][0]==spB[0][0]) && (spA[0][1]==spB[0][1]))
  {
    while(i<=t1 && j<=t2)
    {
      if((spA[i][0]==spB[j][0])&&(spA[i][1]==spB[j][1]))
      {
        C[k][0]=spA[i][0];
        C[k][1]=spA[i][1];
        C[k][2]=spA[i][2]+spB[j][2];
        i++,j++,k++;
      }
      else if(spA[i][0]==spB[j][0])
      {
        if(spA[i][1]>spB[j][1])
        {
          C[k][0]=spB[j][0];
          C[k][1]=spB[j][1];
          C[k][2]=spB[j][2];
          k++,j++;
        }
        if(spA[i][1]<spB[j][1])
        {
          C[k][0]=spA[i][0];
          C[k][1]=spA[i][1];
          C[k][2]=spA[i][2];
          k++,i++;
        }
      }
      else if(spA[i][0]>spB[j][0])
      {
        C[k][0]=spB[j][0];
        C[k][1]=spB[j][1];
        C[k][2]=spB[j][2];
        k++,j++;
      }
      else if(spA[i][0]<spB[j][0])
      {
        C[k][0]=spA[i][0];
        C[k][1]=spA[i][1];
        C[k][2]=spA[i][2];
        k++,i++;
      }
    }
    while(i<=t1)
    {
      C[k][0]=spA[i][0];
      C[k][1]=spA[i][1];
      C[k][2]=spA[i][2];
      k++,i++;
    }
    while(j<=t2)
    {
        C[k][0]=spB[j][0];
        C[k][1]=spB[j][1];
        C[k][2]=spB[j][2];
        k++,j++;
    }
    C[0][0]=r1;
    C[0][1]=c1;
    C[0][2]=k-1;
    printf("\nSum of entered sparse matrices :");
    for(i=0;i<=k-1;i++)
    {
      printf("\n");
      for(j=0;j<3;j++)
      {
        printf("%d ",C[i][j]);
      }
    }
  }  
  else
  {
    printf("\nAddition is not possible");
  }
  printf("\n");
  return 0;
}
