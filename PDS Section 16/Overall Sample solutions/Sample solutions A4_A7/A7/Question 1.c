#include <stdio.h>
main()
{
    int n,sum=0,i,j,min,count;
    printf("Enter the number of zoos in the country : ");
    scanf("%d",&n);
    int temp_array[n];
    //Defining the structure.
    struct zoo
    {
        int elephant;
        int tiger;
        int lion;
    };
    struct zoo zoo_count[n]; //Defining the array variable for structure.
    printf("\n");
    //Inputting data for various zoos.
    for (i=0;i<n;++i)
    {
        printf("-- Enter data for ZOO %d --\n",i+1);
        printf("No. of Elephants : ");
        scanf("%d",&zoo_count[i].elephant);
        printf("No. of Tigers : ");
        scanf("%d",&zoo_count[i].tiger);
        printf("No. of Lions : ");
        scanf("%d",&zoo_count[i].lion);
        printf("\n");
    }
    //Finding the total number of tigers in all zoo.
    for (i=0;i<n;++i)
    {
        sum+=zoo_count[i].tiger;
    }
    printf("Total number of tigers in all the zoo within the country is : %d \n\n",sum);
    printf("Zoos with number of lions less than or equal to 6 are : ");
    //Searching for zoos with lions less than or equal to 6.
    for (i=0;i<n;++i)
    {
       if (zoo_count[i].lion<=6)
       {
           printf("%d ",i+1);
       }
    }
    printf("\n\n");
    printf("Zoos as per increasing order of elephant : ");
    //Storing the number of elephants in different zoo in a temporary array.
    for (i=0;i<n;++i)
    {
        temp_array[i]=zoo_count[i].elephant;
    }
    //Performing bubble sort on the temporary array to sort the number of elephants in ascending order.
    for (i=0;i<n;++i)
    {
        for (j=i+1;j<n;++j)
        {
            if (temp_array[j]<temp_array[i])
            {
                temp_array[j]=temp_array[j]-temp_array[i];
                temp_array[i]=temp_array[j]+temp_array[i];
                temp_array[j]=temp_array[i]-temp_array[j];
            }
        }
    }
    //Comparing the value and printing the index of the zoo.
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            if (temp_array[i]==zoo_count[j].elephant)
            {
                printf("%d ",j+1);
            }
        }
    }
    printf("\n");
}
