#include <stdio.h>
/*

a x b d
c d b c
c b c c
d b x y


a b c
f d f
x b y

a d c d e
a b c d e
e b c b e
e d c d a
a d c d e
*/
int main()

{
    int n,i,j,k,count_diag,t;
    int n_elements=0;

    char arr1[10],arr2[10];
    char matrix[10][10];

    printf("Enter n:");
    scanf("%d",&n);


    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("a[%d%d]:",i+1,j+1);
            scanf(" %c",&matrix[i][j]);
        }
    }

    count_diag=0;
    for (k=1;k<n-1;k++)
    {

        /*
        clear arr1, arr2
        */
        for(i=0;i<10;i++)
        {
            arr1[i]=0;arr2[i]=0;
        }

        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (j==i+k)
                {
                    arr1[i]=matrix[i][j];
                }
                else if (i==j+k)
                {
                    arr2[j]=matrix[i][j];
                }
            }
        }
        n_elements=0;
        for (t=0;t<n-k;t++)
        {
            if (arr1[t]==arr2[n-k-(t+1)])
            {
                n_elements++;
            }
        }
        if (n_elements==n-k)
        {
            printf("Symmetric left diagonal:");
            for (t=0;t<n-k;t++)
            {
                printf(" %c",arr1[t]);
            }
            printf("\n");
            count_diag++;
        }
    }

    if (count_diag>0)
    {
        printf(" The 2D array is character-mirrored , %d Symmetric found: ",count_diag);
    }
    else
    {
        printf(" The 2D array is not character-mirrored : ");
    }
}
