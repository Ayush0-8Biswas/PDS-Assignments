#include<stdio.h>
#include<stdlib.h>

// Defining the structure vector
struct vector
{
    int n;
    float *arr;
};

// Defining the function for computing vector sum
struct vector vectorSum(struct vector *v1,struct vector *v2,int n)
{
    struct vector v3;
    v3.arr = (float*) malloc(n * sizeof(float));
    for(int i=0;i<n;i++)
        *(v3.arr+i)=*(v1->arr+i)+*(v2->arr+i);
    return v3;
};

// Defining the function for testing Orthogonality
int orthogonalTest(struct vector *v1,struct vector *v2,int n)
{
    float sum = 0;
    for(int i=0;i<n;i++)
        sum = sum + *(v1->arr+i)**(v2->arr+i);
    return sum;
}

// Main Function
int main()
{
    struct vector vector1, vector2, sum_vector;
    int n;
    float flag = 0.0;
    
    // Accepting vector dimension from user
    printf("Enter dimension: ");
    scanf("%d",&n);
    
    // Dynamically allocating memory for the vectors and accepting their values from user
    vector1.arr = (float*) malloc(n * sizeof(float));
    vector2.arr = (float*) malloc(n * sizeof(float));
    printf("Enter Vector1: ");
    for(int i=0;i<n;i++)
        scanf("%f",&vector1.arr[i]);
    printf("Enter Vector2: ");
    for(int i=0;i<n;i++)
        scanf("%f",&vector2.arr[i]);
    
    // Printing the values of the vectors
    printf("Vector 1 is: (%d, [", n);
    for(int i=0;i<n;i++)
        if (i==n-1)
            printf("%f]",vector1.arr[i]);
        else
            printf("%f, ",vector1.arr[i]);
        
    printf("\nVector 2 is: (%d, [", n);
    for(int i=0;i<n;i++)
        if (i==n-1)
            printf("%f]",vector2.arr[i]);
        else
            printf("%f, ",vector2.arr[i]);
    
    // Calling the vectorSum function and Printisng the result
    sum_vector = vectorSum(&vector1,&vector2,n);
    printf("\nSum of the two vectors is: (%d, [",n);
    for(int i=0;i<n;i++)
        if (i==n-1)
            printf("%f]",sum_vector.arr[i]);
        else
            printf("%f, ",sum_vector.arr[i]);
     
    // Calling the orthogonalTest function and Printing the result   
    flag = orthogonalTest(&vector1,&vector2,n);
    if (!flag)
        printf("\nThe vectors are orthogonal.\n");
    else
        printf("\nThe vectors are not orthogonal.\n");
        
    return 0;
}