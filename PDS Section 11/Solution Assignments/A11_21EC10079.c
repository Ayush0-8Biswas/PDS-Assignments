/* Section - 11
 * Roll No.: 21EC10079
 * Name: Teerath Agarwal
 * Group No.: 8
 * Assignment No.: 11
 * Description: This program reverses the digits stored in the array entered, then sort both the arrays, then finds the median of the combined array.
*/

#include <stdio.h>

/* This function returns a^b */
int power(int a, int b)
{
    int d=1;
    for (int i=1; i<=b; i++) d = d*a;
    return d;
}

/* This function returns the number of digits in x */
int digit(int x)
{
    int k=0;
    while (x>=1)
    {
        x/=10;
        k++;
    }
    return k;
}

int revdig(int n)
{
    if (n<10) return n;
    else
    /* Taking out last digit, puting it to the starting then reversing the remaining number */
    /* If number is 1234, then it returns 4 + reverse(123), which 4321 */
    return (n%10)*(power(10,digit(n)-1)) + revdig(n/10);
}

void rsort(int mode, int z[], int st, int ed, int p)
{
    /* Sorting z, here st stores starting index, ed stores ending index and p is the index to which we are comparing */
    if (st>=ed) return;
    else
    {
        int temp;
        if ((!mode && z[p]<z[st]) || (mode && z[p]>z[st]))
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
        rsort(mode,z,st,ed,p);
        return;
    }
}

float rmed(int x[], int st, int ed)
{
    if (ed-st==1) return (float)(x[st]+x[ed])/2;
    else if (ed==st) return x[st];
    else return rmed(x,st+1,ed-1);
}

int main()
{
    /* Taking input data from the user and printing it */
    int n, A[20], B[20];
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("n = %d\n",n);


    printf("Enter the Array A: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
        /* Reversing digits in A and storing in B */
        B[i] = revdig(A[i]);
    }

    /* Printing unsorted Arrays */
    printf("\nArray A: ");
    for (int i=0; i<n; i++) if (i==n-1) printf("%d",A[i]); else printf("%d, ",A[i]);
    printf("\nArray B: ");
    for (int i=0; i<n; i++) if (i==n-1) printf("%d",B[i]); else printf("%d, ",B[i]);

    /* Sorting the arrays and printing them */
    rsort(0,A,0,n-1,0);
    rsort(1,B,0,n-1,0);
    printf("\n\nAfter Sorting:");
    printf("\nArray A: ");
    for (int i=0; i<n; i++) if (i==n-1) printf("%d",A[i]); else printf("%d, ",A[i]);
    printf("\nArray B: ");
    for (int i=0; i<n; i++) if (i==n-1) printf("%d",B[i]); else printf("%d, ",B[i]);

    /* Storing combined array A and B in C, then sorting C so that we can find its median */
    int C[40],t=0;
    for (; t<n; t++) C[t] = A[t];
    for (; t<2*n; t++) C[t] = B[t-n];
    rsort(0,C,0,2*n-1,0);

    /* Finding the median and printing it */
    printf("\n\nMedian of combination Array A and B = %.1f\n\n", rmed(C,0,2*n-1));

    return 0;
}