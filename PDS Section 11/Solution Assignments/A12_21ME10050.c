/*
* Section 11
* Rollno:21ME10050
* Name:Mayukh Banerjee
* Group no:5
* Assignment no:12
* Description:finding kth largest in a matrix and performing tasks on it with some condtns.
*/
#include <stdio.h>

int largek(int a[][100],int n,int k)
{
    int arr[100],i,j,l=0,max,f;
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {

             arr[n*i+j]=a[i][j];
        }

    }
    for(i=0;i<n*n-1;i++)
    {
        max=i;
        for(j=i+1;j<n*n;j++)
        {
            if (arr[j]>arr[max])

                max=j;
        }
                f=arr[max];
                arr[max]=arr[i];
                arr[i]=f;


    }
   return arr[k-1];
}

int sortr(int a[][100],int n)
{
    int i,j,k,min,f;
    for (i=0;i<n;i++)
        {


        for(j=0;j<n-1;j++)
        {
        min=j;
        for(k=j+1;k<n;k++)
        {
            if (a[i][k]<a[i][min])

                min=k;
        }
                f=a[i][min];
                a[i][min]=a[i][j];
                a[i][j]=f;


    }
}


}





int main()
{

    int a[100][100],arr[100],i,j,n,m,k,l,x;

    printf("enter n:");
    scanf ("%d",&n);
    printf("\nn=%d\n",n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
    }



    printf("\nenter k:");
    scanf("%d",&k);
    if((k<1) || (k>n*n))
    {
        printf("\nWRONG K\n");
    }
    x=largek(a,n,k);
    printf("\n%dth largest element is:%d",k,x);
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if (x==a[i][j]) printf("\nThe index of %d is:(%d,%d)\n",x,i,j);
    }
    sortr(a,n);
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",a[j][i]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if (x==a[i][j]) printf("\nThe updated index of %d is:(%d,%d)\n",x,j,i);
    }

}

