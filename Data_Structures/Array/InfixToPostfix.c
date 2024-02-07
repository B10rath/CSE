//To convert an expression in infix to postfix
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int IS[50],TOP=-1;
char S[50];
int PUSH(char x)
{
 if (TOP>=49)
 	{
 	 printf("\n\tSTACK OVERFLOW!!\n\n");
 	}
 else
 	{
 	 TOP++;
 	 S[TOP]=x;
 	}
 return 0;
}
int POP()
{
 char elem;
 if (TOP!=-1)
 	{
 	 elem=S[TOP];
 	 TOP--;
 	 return elem;
 	}
 else
 	{
 	 printf("\n\tSTACK UNDERFLOW\n\n");
 	 return 0;
 	}
}
int IPUSH(int num)
{
 if (TOP>=49)
 	{
 	 printf("\n\tSTACK OVERFLOW!!\n\n");
 	}
 else
 	{
 	 TOP++;
 	 IS[TOP]=num;
 	}
 return 0;
}
int IPOP()
{
 int element;
 if (TOP==-1)
 	{
 	 printf("\n\tSTACK UNDERFLOW!!\n\n");
 	 return 0;
 	}
 else
 	{
 	 element=IS[TOP];
 	 TOP--;
 	 return element;
 	}
}
int IDISP()
{
 int a;
 if(TOP==-1)
 	{
 	 printf("\n\tStack is empty.\n\n");
 	 return 0;
 	}
 else
 	{
 	 a=TOP;
 	 while (a!=-1)
 	 	{
 	 	 printf("%d ",IS[a]);
 	 	 a--;
 	 	}
 	 printf("\n\n");
 	 return 0;
 	}
}
int ISP(char a)
{
 if (a=='^')
 	return 3; 
 if (a=='/' || a=='*')
 	return 2;
 if (a=='+' || a=='-')
 	return 1;
 if (a=='(')
 	return 0;
}
int ICP(char b)
{
 if (b=='^')
 	return 4; 
 if (b=='/' || b=='*')
 	return 2;
 if (b=='+' || b=='-')
 	return 1;
 if (b=='(')
 	return 4;
}
int main()
{
 char infix[50],postfix[50],ITEM,x;
 int i=0,j=0,flag=0,val,y,z,t;
 printf("\n\tEnter the expression: ");
 scanf("%s",infix);
 infix[strlen(infix)]=')';
 PUSH('(');
 while (TOP!=-1)
 	{
 	 ITEM=infix[i];
 	 i++;
 	 if (isalpha(ITEM))
 	 	{
 	 	 postfix[j]=ITEM;
 	 	 j++;
 	 	}
 	 else if (ITEM==')')
 	 	{
 	 	 x=POP();
 	 	 while (x!='(')
 	 	 	{
 	 	 	 postfix[j]=x;
 	 	 	 j++;
 	 	 	 x=POP();
 	 	 	}
 	 	}
 	 else if (ITEM =='^' || ITEM=='*' || ITEM=='/' || ITEM=='+' || ITEM=='-' || ITEM=='(')
 	 	{
 	 	 x=POP();
 	 	 if (ISP(x)>=ICP(ITEM))
 	 	 	{
 	 	 	 while (ISP(x)>=ICP(ITEM))
 	 	 	 	{
 	 	 	 	 postfix[j]=x;
 	 	 	 	 j++;
 	 	 	 	 x=POP();
 	 	 	 	}
 	 	 	 PUSH(x);
 	 	 	 PUSH(ITEM);
 	 	 	}
 	 	 else if (ISP(x)<ICP(ITEM))
 	 	 	{
 	 	 	 PUSH(x);
 	 	 	 PUSH(ITEM);
 	 	 	}
 	 	}
 	 else
 	 	{
 	 	 flag=1;
 	 	 printf("\n\tERROR:INVALID ELEMENTS IN THE EXPRESSION!!\n\n");
 	 	 break;
 	 	}
 	}
 if (flag==0)
 	{
 	 printf("\n\tThe postfix form: %s\n\n",postfix);
 	}
 i=0;
 TOP=-1;
 ITEM=postfix[i];
 while (postfix[i]!='\0')
 	{
 	 if (isalpha(ITEM))
 	 	{
 	 	 printf("\n\tEnter the value of %c: ",ITEM);
 	 	 scanf("%d",&val);
 	 	 IPUSH(val);
 	 	}
 	 else
 	 	{
 	 	 z=IPOP();
 	 	 y=IPOP();
 	 	 switch (ITEM)
 	 	 	{
 	 	 	 case '+':t=y+z;
 	 	 	 	  break;
 	 	 	 case '-':t=y-z;
 	 	 	 	  break;
 	 	 	 case '*':t=y*z;
 	 	 	 	  break;
 	 	 	 case '/':t=y/z;
 	 	 	 	  break;
 	 	 	 case '^':t=pow(y,z);
 	 	 	 	  break;
 	 	 	}
 	 	 IPUSH(t);
 	 	}
 	 i++;
 	 ITEM=postfix[i];
 	}
 printf("\n\n\tResult of evaluation: ");
 IDISP();
 return 0;
}
