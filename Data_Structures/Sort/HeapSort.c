// Program to implement Heap sort

#include<stdio.h>
int main()
{
 int i,j,k,n,N=0,p,lc,rc,c[20],a[20],temp,x,y;
 printf("\n\tEnter the number of elements: ");
 scanf("%d",&n);
 printf("\n\tEnter the array elements: ");
 for(i=0;i<n;i++)
	{
	 scanf("%d",&a[i]);
	}
 for(i=0;i<n;i++)
	{
	 N=N+1;
	 c[N]=a[i];
	 j=N;
	 p=j/2;
	 while(p>0 && c[p]<=c[j])
		{
		 temp=c[p];
		 c[p]=c[j];
		 c[j]=temp;
		 j=p;
		 p=p/2;
		}
	}
 printf("\n\tElements after insertion: ");
 for(i=1;i<=n;i++)
	{
	 printf("%d ",c[i]);
	}
 k=N-1;
 printf("\n\n\tDeleted elements: ");
 for(i=0;i<n;i++)
	{
	 a[k]=c[1];
	 k--;
	 printf("%d ",c[1]);
	 c[1]=c[N];
	 N=N-1;
	 j=1;
	 while(j<N)
		{
		 lc=2*j;
		 rc=(2*j)+1;
		 if(lc<=N)
			{
			 x=c[lc];
			}
		 else
			{
			 x=-2401;
			}
		 if(rc<=N)
			{
			 y=c[rc];
			}
		 else
			{
			 y=-2401;
			}
		 if(x<=c[j] && y<=c[j])
			{
			 break;
			}
		 else if(x>=y && x>=c[j])
			{
			 temp=c[j];
			 c[j]=c[lc];
			 c[lc]=temp;
			 j=lc;
			}
		 else if(y>x && y>=c[j])
			{
			 temp=c[j];
			 c[j]=c[rc];
			 c[rc]=temp;
			 j=rc;
			}
		}
	}
 printf("\n\n\tArray after sorting: ");
 for(i=0;i<n;i++)
	 {
	  printf("%d ",a[i]);
	 }
 printf("\n\n");
 return 0;
}
