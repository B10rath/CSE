//Program for polynomial addition
#include<stdio.h>
int x;
struct polynomial
{
  int coff;
  int exp;
}poly1[50],poly2[50],poly3[50];
void read(struct polynomial poly[],int n)
{
  int i;
  x++;
  for(i=0;i<n;i++)
  {
    printf("Enter the coefficent of term %d :",i+1);
    scanf("%d",&poly[i].coff);
    printf("Enter the exponent of term %d :",i+1);
    scanf("%d",&poly[i].exp);
  }
}
void print(struct polynomial poly[],int n)
{
  int i;
  printf("%dx^%d",poly[0].coff,poly[0].exp);
  for(i=1;i<n;i++)
  {
    printf(" + %dx^%d",poly[i].coff,poly[i].exp);
  }
}
int main()
{
  int n1,n2,i=0,j=0,k=0;
  printf("Enter the number of terms of polynomial 1 :");
  scanf("%d",&n1);
  read(poly1,n1);
  printf("Enter the number of terms of polynomial 2 :");
  scanf("%d",&n2);
  read(poly2,n2);
  printf("Entered polynomial 1 :");
  print(poly1,n1);
  printf("\nEntered polynomial 2 :");
  print(poly2,n2);
  while(i<n1 && j<n2)
  {
    if(poly1[i].exp==poly2[j].exp)
    {
      poly3[k].coff=poly1[i].coff+poly2[j].coff;
      poly3[k].exp=poly1[i].exp;
      i++;j++;k++;
    }
    else if(poly1[i].exp>poly2[j].exp)
    {
      poly3[k].coff=poly1[i].coff;
      poly3[k].exp=poly1[i].exp;
      i++;k++;
    }
    else
    {
      poly3[k].coff=poly2[j].coff;
      poly3[k].exp=poly2[j].exp;
      j++;k++;
    }
  }
  while(i<n1)
  {
    poly3[k].coff=poly1[i].coff;
    poly3[k].exp=poly1[i].exp;
    i++;k++;
  }
  while(j<n2)
  {
    poly3[k].coff=poly2[j].coff;
    poly3[k].exp=poly2[j].exp;
    j++;k++;
  }
  printf("\nSum of polynomials = ");
  printf("%dx^%d",poly3[0].coff,poly3[0].exp);
  for(i=1;i<k;i++)
  {
    printf(" + %dx^%d",poly3[i].coff,poly3[i].exp);
  }
  printf("\n");
  return 0;
}
