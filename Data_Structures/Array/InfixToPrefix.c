//To convert an expression in infix to prefix
#include<stdio.h>
#include<math.h>
char infix[100],reverse[100],prefix2[100],prefix[100],stack[100];
int stack2[100];
int top=0,top2=-1;
int ISP(char a)
{
    if(a=='^')
    {
        return 4;
    }
    else if(a=='*'||a=='/')
    {
        return 2;
    }
    else if(a=='+'||a=='-')
    {
        return 1;
    }
    else if(a==')')
    {
     return 0;
    }
}

int ICP(char a)
{
    if(a=='^')
    {
        return 3;
    }
    else if(a=='*'||a=='/')
    {
        return 2;
    }
    else if(a=='+'||a=='-')
    {
        return 1;
    }
    else if(a==')')
    {
     return 4;
    }
}

void PUSH(char c)
{
    top++;
    stack[top]=c;
}

void PUSH2(int n)
{
    top2++;
    stack2[top2]=n;
}

char POP()
{
    char p;
    p=stack[top];
    top--;
    return p;
}

int POP2()
{
    int n;
    n=stack2[top2];
    top2--;
    return n;
}

void EVAL(char pre[100])
{
    int i=0,item,value,x,y,result=0;
    while(pre[i]!='\0')
    {
        item=pre[i];
        i++;
        if(item!='*' && item!='+' && item!='-' && item!='/' && item!='^')
        {
            printf("Enter the value %c : ",item);
            scanf("%d",&value);
            PUSH2(value);
        }
        else if(item=='*' || item=='+' || item=='-' || item=='/' || item=='^')
        {
            x=POP2();
            y=POP2();
            if(item=='*')
            {
                result=x*y;
            }
            else if(item=='+')
            {
                result=x+y;
            }
            else if(item=='-')
            {
                result=x-y;
            }
            else if(item=='/')
            {
                result=x/y;
            }
            else if(item=='^')
            {
                result=pow(x,y);
            }
            PUSH2(result);
        }
    }
    printf("Prefix evaluation output : %d\n",stack2[top2]);
}

int main()
{   
    int i=0,j;
    char x,item;
    //Read expression
    printf("Enter the infix Expression: ");
    scanf("%s",&infix);
    //print expression
    printf("Entered infix expression: ");
    while(infix[i]!='\0')
    {
        printf("%c",infix[i]);
        i++;
    }
    j=i-1;
    i=0;
    while(j>=0)
    {
        reverse[i]=infix[j];
        j--;
        i++;
    }
    reverse[i]='(';
    reverse[i+1]='\0';
    stack[top]=')';
    i=0;j=0;
    while(top!=-1)
    {
        item=reverse[i];
        i++;
        if(item!='*' && item!='+' && item!='-' && item!='/' && item!='^' && item!='(' && item!=')')
        {
            prefix[j]=item;
            j++;
        }
        else if(item=='(')
        {
            x=POP();
            while(x!=')')
            {   
                prefix[j]=x;
                j++;
                x=POP();
            }
        }
        else if(item=='*' || item=='+' || item=='-' || item=='/' || item=='^' || item==')')
        {   
            x=POP();
            if(ISP(x)>ICP(item))
            {
                while(ISP(x)>ICP(item))
                {
                    prefix[j]=x;
                    j++;
                    x=POP();
                }
                PUSH(x);
                PUSH(item);
            }
            else if(ISP(x)<=ICP(item))
            {
                PUSH(x);
                PUSH(item);
            }
            else
            {
                printf("Invalid Operator!!!");
            }
        }
    }
    printf("\nPrefix Expression :");
    
    i=j-1;
    j=0;
    while(i>=0)
    {
        prefix2[j]=prefix[i];
        j++;
        i--;
    }
    prefix[j]='\0';
    prefix2[j]='\0';
    i=0;
    while(prefix2[i]!='\0')
    {
        printf("%c",prefix2[i]);
        i++;
    }
    printf("\n");
    
    EVAL(prefix);
    
    return 0;
}
