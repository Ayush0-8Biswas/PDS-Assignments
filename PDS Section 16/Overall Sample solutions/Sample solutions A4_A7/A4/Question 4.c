/*program for which you have printed
becomes your new queue for the next iteration and continue this
process until there are no more elements in the queue or there are no vowels 
remaining in the current queue being considered. */
#include<stdio.h>
#include<math.h>

int main()
{
    //taking the queue size
    int n;
    printf("enter the queue size:");
    scanf("%d",&n);

    //character array initalization and declaration
    char c[n];
    printf("Original queue: ");
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&c[i]);
    }

    //variable declaration
    int j=1,k=0,x;

    // loop for checking of array vowels
    for(int i=0;i<n;i++)
    {
        
        // checking vowels
        if (c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'||
        c[i]=='A'||c[i]=='E'||c[i]=='I'||c[i]=='O'||c[i]=='U')
        {
            k++;
        }
    }

    x=k;

    //checking for next iterations
    while(k!=0)
    {
        printf("——-Iteration-%d———\n",j);
        k = 0;
        printf("New queue:");
        for(int i=x;i<n;i++)
        {
            printf("%c,",c[i]);
            if (c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'||
            c[i]=='A'||c[i]=='E'||c[i]=='I'||c[i]=='O'||c[i]=='U')
            {
               k++;
            }
        }
        x =x+k;
        printf("\n");
        j++;
    }
    return 0;

    //program completed

}
