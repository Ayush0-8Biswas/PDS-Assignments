/*
EDITED TO CORRECT CODE

LOGIC BY --->
Section 11
Roll No  :  21AE30008
Name    :  Jasothan
Group No.: 4
Assignment No : 13
Description :
*/
#include<stdio.h>
#include<stdlib.h>
int union_num(char*a ,char*b,int x,int y)
{
    int i,c[26] = {0},j=0;
    for(i=0;i<26;i++)c[i]=0;
    for(i=0;i<x;i++)c[a[i]-'a']=1;
    for(i=0;i<y;i++)c[b[i]-'a']=1;
    for(i=0;i<26;i++)
    {
        if(c[i]!=0)
            j=j+1;
    }
    return j;
}

char* unionn(char* a,char* b,int x,int y)
{
    int c[26] = {0};
    char*temp = (char*)malloc((100)*sizeof(char));
    int i;
    for(i=0;i<x;i++)c[a[i]-'a']=1;
    for(i=0;i<y;i++)c[b[i]-'a']=1;
    int l = 0;
    for(i=0;i<26;i++)
    {
        if(c[i]==1)
        {
            temp[l] = i+'a';
            l++;
        }
    }
    temp[l] = '\0';
    return temp;
}

char* inters(char* a,char* b,int x,int y)
{
    char* temp = (char*)malloc((x+y)*sizeof(char));
    int i,d[26],e[26];
    for(i=0;i<26;i++)
    {
        d[i]=0;
        e[i]=0;
    }
    for(i=0;i<x;i++)e[a[i]-'a']=1;
    for(i=0;i<y;i++)d[b[i]-'a']=1;
    int l = 0;
    for(i=0;i<26;i++)
    {
        if(e[i]!=0 && d[i]!=0)
        {
            temp[l] = i+'a';
            l++;
        }
    }
    temp[l] = '\0';
    return temp;
}

int inters_num(char* a,char* b,int x,int y)
{
    int i,c[26]={0},d[26]={0},j=0;
    for(i=0;i<x;i++)c[a[i]-'a']=1;
    for(i=0;i<y;i++)d[b[i]-'a']=1;
    for(i=0;i<26;i++)if(c[i]!=0 && d[i]!=0)j=j+1;
    return j;
}


int diffnum(char* a, char* b, int x, int y)
{
    int i,j=0,c[26];
    for(i=0;i<26;i++)c[i]=0;
    for(i=0;i<x;i++)
        c[a[i]-'a']=1;
    for(i=0;i<y;i++)
        c[b[i]-'a']=0;
    for(i=0;i<26;i++)
    {
        if(c[i])
            j=j+1;
    }
    return j;
}

char* diff(char* a,char* b,int x,int y)
{
    int i,j=0;
    int c[26];
    for(i=0;i<26;i++)c[i]=0;
    for(i=0;i<x;i++)c[a[i]-'a']=1;
    for(i=0;i<y;i++)c[b[i]-'a']=0;
    char* temp =(char*)malloc((100)*sizeof(char));
    int l = 0;
    for(i=0;i<26;i++)
    {
        if(c[i]==1)
        {
            temp[l] = i+'a';
            l++;
        }
    }
    temp[l] = '\0';
    return temp;
}



int main()
{
    int m,n,sizep=0,sizeq=0;
    char *p,*q;
    printf("Enter the values of m and n respectively.");
    scanf("%d%d",&m,&n);
    p=(char*)malloc((m+1)*sizeof(char));
    q=(char*)malloc((n+1)*sizeof(char));
    printf("\nEnter two strings of max %d and %d length:",m,n);
    scanf("%s%s",p,q);
    printf("\n%s and %s",p,q);
    int i=0;
    while(p[i]!='\0')
    {
        sizep++;
        i++;
    }
    i=0;
    while(q[i]!='\0')
    {
        sizeq++;
        i++;
    }
    printf("\nno. of elements in union=%d & string=%s",union_num(p,q,sizep,sizeq),unionn(p,q,sizep,sizeq));
    printf("\nno. of elements in intersection=%d & string=%s",inters_num(p,q,sizep,sizeq),inters(p,q,sizep,sizeq));
    printf("\nno. of elements in A-B=%d & string=%s",diffnum(p,q,sizep,sizeq),diff(p,q,sizep,sizeq));
    printf("\nno. of elements in B-A=%d & string=%s\n",diffnum(q,p,sizeq,sizep),diff(q,p,sizeq,sizep));
    return 0;
}

