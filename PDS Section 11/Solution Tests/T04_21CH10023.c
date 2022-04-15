
/*

* Section 11

* Roll No. : 21CH10023

* Name : Dibyansh Sekhar Das

* Group No. : 8

* Test problem no : 4

* Description : reverse substrings and count mismatches

*/

#include <stdio.h>
//getting the length of a string
int leng(char a[])
{
    int len=0;
    for (int i = 0; a[i]!='\0'; i++) len++;
    return len;
}

//non recursive function to reverse a string
void krev(char A[20], int k, int len, char B[20])
{
    char temp[20], swap;
    for (int i=0; i<k; i++) temp[i]=A[i];
    temp[k]='\0';
    for (int i=0; i<(k/2);i++)
    {
        swap=temp[i];
        temp[i]=temp[k-i-1];
        temp[k-i-1]=swap;
    }

    for (int i=0; i<k; i++) B[i]=temp[i];
    for (int j=k; j<len; j++) B[j]=A[j];
    B[len]='\0';
    printf("%s\n", B);

}

//recursive function to reverse a string
void rkrev(char temp[20],int i, int k)
{
    char swap;
    if (i>=k)
    {
        return;
    }
    else
    {
        swap=temp[i];
        temp[i]=temp[k];
        temp[k]=swap;
        rkrev(temp, i+1, k-1);
    }



}
//an utility function that uses the recursive function to reverse a string and prints the string B for each value of k
void utilFunc(char A[20], int k, int len, char B[20])
{
    char temp[20];
    for (int i =0; i<k; i++) temp[i]=A[i];
    temp[k]='\0';
    rkrev(temp, 0, k-1);

    for (int i=0; i<k; i++) B[i]=temp[i];
    for (int j=k; j<len; j++) B[j]=A[j];
    B[len]='\0';
    printf("%s\n", B);

}

//non recursive function to get the number of mismatches
int mism(char A[], char B[], int len)
{
    int mism = 0;
    for (int i = 0; i<len; i++)
    {
        if (!(A[i]==B[i] || A[i]==B[i]+32 || A[i]==B[i]-32)) mism++;
    }

return mism;
}

//recursive function to get the number of mismatches
int rmism(char A[], char B[], int len)
{
    if (len==1)
    {
        if (!(A[0]==B[0] || A[0]==B[0]+32 || A[0]==B[0]-32)) return 1;
        else return 0;
    }
    else
    {
        if (!(A[len-1]==B[len-1] || A[len-1]==B[len-1]+32 || A[len-1]==B[len-1]-32)) return (1+rmism(A, B, len-1));
        else return rmism(A,B,len-1);
    }
}


int main(){
printf("Enter string A:\n");
char A[20];
scanf("%s", A);
char B[20];
int length=leng(A);

printf("Using non-recursive functions\n\n");
for (int i=1; i<=length; i++)
{

    printf("For k=%d, The string is: ", i);
    krev(A, i, length, B);
    printf("The number of mismatches is %d\n", mism(A, B, length));
    printf("\n");
}

printf("Using recursive functions\n\n");
for (int i=1; i<=length; i++)
{

    printf("For k=%d, The string is: ",i);
    utilFunc(A, i, length, B);
    printf("The number of mismatches is %d\n", rmism(A, B, length));
    printf("\n");
}

return 0;
}















