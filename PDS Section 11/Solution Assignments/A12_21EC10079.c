/* Section - 11
 * Roll No.: 21EC10079
 * Name: Teerath Agarwal
 * Group No.: 8
 * Assignment No.: 12
 * Description: 
*/

#include <stdio.h>

void sortr(int z[], int st, int ed, int p)
{
    if (st>=ed) return;
    else
    {
        int temp;
        if (z[p]<z[st])
        {
            temp = z[p];
            z[p] = z[st];
            z[st] = temp;
        }
        if (p==ed)
        {
            st++;
            p=st;
        }
        else p++;
        sortr(z,st,ed,p);
        return;
    }
}

int largek(int k, int x[], int size)
{
    int max_index=0;
    for (int i=0; i<size; i++)
    if (x[max_index]<x[i]) max_index = i;

    if (k==1) return x[max_index];
    else
    {
        x[max_index] = -2,147,483,648;
        return largek(k-1,x,size);
    }
}

int main()
{
    /* Taking input data from the user and printing it */
    int n, k, lk, k_row, k_column, a[20][20], b[400];
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("n = %d\n",n);

    printf("Enter the 2-D matrix:\n");
    for (int i=0; i<n; i++)
    {
        printf("Row %d: ",i+1);
        for (int j=0; j<n; j++)
        scanf("%d",&a[i][j]);
    }

    printf("\nMatrix Entered:");
    for (int i=0; i<n; i++)
    {
        printf("\nRow %d: ",i+1);
        for (int j=0; j<n; j++)
        printf("%d ", a[i][j]);
    }

    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    b[i*n+j] = a[i][j];

    printf("\n\nEnter the value of k to find k-th largest integer: ");
    scanf("%d",&k);
    if (k>n*n || k<1) printf("Error: Invalid value of k was entered!\n");
    else
    {
        lk = largek(k,b,n*n);
        printf("\nk-th largest element of the matrix = %d\n", lk);
        for (int i=0; i<n*n; i++)
        if (b[i]==lk)
        {
            k_row = (i/n)+1;
            k_column = (i%n)+1;
        }
        printf("Location indeces ([row,column]): [%d,%d]", k_row, k_column);
    }

    for (int i=0; i<n; i++)
    sortr(a[i],0,n-1,0);

    printf("\n\nSorted matrix printing column-wize:");
    for (int i=0; i<n; i++)
    {
        printf("\nColumn %d: ",i+1);
        for (int j=0; j<n; j++)
        printf("%d ", a[j][i]);
    }
    for (int i=0; i<n; i++)
    if (a[k_row-1][i]==lk) k_column = i+1;
    printf("\n\nNew location indeces of k-th largest element ([row,column]): [%d,%d]\n\n",  k_row,k_column);

    return 0;
}