#include<stdio.h>

int main()
{
    int n,i,key,b=0,a; //declaring variables

    printf("enter the value of n: "); //asking for the value of n
    scanf("%d",&n);

    int arr[n]; //defining an array of length n

    printf("enter the values in the array:\n"); // asking for the values of the elements the array one by one
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("enter the key value: "); // asking for the value of key
    scanf("%d",&key);

    for (i=0;i<=n;i++) // finding the position at which the key is present and assigning it to a
        if (key==arr[i])
        {
            b=1; // if the key exists in the array assigning 1 to b
            a=i;
            break;
        }

    if(b==1) // if the key exists in array we change the array as directed
    {
        printf("the position of key in the array is: %d\n\n ",a+1); //printing the position of key

        for(i=a;i<n-1;i++)  // shifting the elements present on right of the key one position towards left
            arr[i]=arr[i+1];

        arr[n-1]=key;  //storing the value of key at the end of array

        printf("the new array is:"); // printing the manipulated array
        for(i=0;i<n;i++)
            printf(" %d",arr[i]);
    }
    else
    printf("the key element not found!!"); // if the key does not exist in array ,printing "the key element not found"

    return(0);
}
