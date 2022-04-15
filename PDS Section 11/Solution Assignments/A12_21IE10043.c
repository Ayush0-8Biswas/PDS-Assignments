#include<stdio.h>
/* Utsav Mandal
   21IE10043
   Section-11
   Group-5
   */
int largek(int a[],int n,int k)
{
 int t,j;
if(n==1)
{
   a[0]==a[0];
}
else
{
for(j=0;j<n-1;j++)
if(a[j+1]>a[j])
{
    t=a[j+1];
    a[j+1]=a[j];
    a[j]=t;
}
largek(a,n-1,k);
}
return a[k-1];
}

int sortr(int a[20][20],int n,int i)
{
    int t,j;
if(n==1)
{
   a[i][0]==a[i][0];
}
else
{
for(j=0;j<n-1;j++)
if(a[i][j+1]<a[i][j])
{
    t=a[i][j+1];
    a[i][j+1]=a[i][j];
    a[i][j]=t;
}
sortr(a,n-1,i);
}
}


   int main()
   {
       int n,a[20][20],i,j,k;
       scanf("%d",&n);
       printf("n=%d\n",n);
       for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
        {
        printf("Row %d:     ",i+1);
       for(j=0;j<n;j++)
       printf("%d\t",a[i][j]);
       printf("\n");
        }
scanf("%d",&k);
if(k<1||k>n*n)
printf("Not valid value of k.\n");
else
{ 
int c[400],q=0,v;
 for(i=0;i<n;i++)
       for(j=0;j<n;j++)
      { c[q]=a[i][j];q++;}
v=largek(c,q,k);
printf("%d largest is =%d\n",k,v);
for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       if(a[i][j]==v)printf("Indices are Row:%d and Column:%d.\n",i+1,j+1);

 for(i=0;i<n;i++)
 sortr(a,n,i);
for(i=0;i<n;i++)
        {printf("Column %d:     ",i+1);
       for(j=0;j<n;j++)
       printf("%d\t",a[j][i]);
       printf("\n");}
for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       if(a[i][j]==v)printf("Now Indices are Row:%d and Column:%d.\n",i+1,j+1);}
   }