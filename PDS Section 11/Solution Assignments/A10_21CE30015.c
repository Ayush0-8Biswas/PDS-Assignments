/*
* Section 11
* Roll No. - 21CE30015
* Name - Shriram Deshpande
* Group 6
* Assignment 10
* Description-Finding the largest palindrome in a given string
*/

#include <stdio.h>

int pal(char S[],int i,int j)
{
    int k,test;
    test=1;
    for(k=0;k<((i+j)/2);k++){
        if(S[i+k]!=S[j-k]){
            test=0;
            {break;}
        }
    }
    return test;
}

int rpal(char S[], int i, int j)
{
    int test;
    test=1;
    if(i>=j)return test;
    if(S[i]!=S[j]){
        test=0;
        return test;
    }
    else if (S[i]==S[j]){
       test=rpal(S,i+1,j-1);
       return test;
    }
}

int main(){
    //Declaring and intialising variables
    char S[100];
    int i,j,k,res,A[30],l,temp;
    l=0;

    //Taking the string from user
    printf("Enter a string S:\n");
    scanf("%s", S);
    printf("%s\n", S);

    //Converting it to all lowercase
    for(i=0;S[i]!='\0';i++){
        if((S[i]>='A')&&(S[i]<='Z'))S[i]=S[i]-'A'+'a';
    }

    //for loop which checks for all possible palindromes
    for(i=0;S[i]!='\0';i++)
        for(j=i+2;S[j]!='\0';j++){
            res=0;
            res=pal(S,i,j);
            if (res==1){
                A[l]=j-i+1;
                for(k=i;k<=j;k++)printf("%c", S[k]);
                printf("\ti=%d,j=%d\n", i+1,j+1);
                l++;
            }
        }

    //finding the length of the largest palindrome
    temp=A[0];
    for(i=1;i<l;i++){
        if (A[i]>temp)temp=A[i];
    }

    //Using the length to determine which palindrome are largest as there can be multiple
    if (l!=0){
        printf("The largest palindrome are:\n");
    for(i=0;S[i]!='\0';i++)
        for(j=i+2;S[j]!='\0';j++){
            res=0;
            res=pal(S,i,j);
            if (res==1){
                if ((j-i+1)==temp){
                    for(k=i;k<=j;k++)printf("%c", S[k]);
                    printf("\n");
                }
            }

        }
    }
    else printf("NO palindrome in the string\n");//if no palindromes are found

    printf("\n\nChecking using recursive function:\n\n");
    for(i=0;S[i]!='\0';i++)
        for(j=i+2;S[j]!='\0';j++){
            res=0;
            res=rpal(S,i,j);
            if (res==1){
                A[l]=j-i+1;
                for(k=i;k<=j;k++)printf("%c", S[k]);
                printf("\ti=%d,j=%d\n", i+1,j+1);
                l++;
            }
        }

    //finding the length of the largest palindrome
    temp=A[0];
    for(i=1;i<l;i++){
        if (A[i]>temp)temp=A[i];
    }

    //Using the length to determine which palindrome are largest as there can be multiple
    if (l!=0){
        printf("The largest palindrome are:\n");
    for(i=0;S[i]!='\0';i++)
        for(j=i+2;S[j]!='\0';j++){
            res=0;
            res=rpal(S,i,j);
            if (res==1){
                if ((j-i+1)==temp){
                    for(k=i;k<=j;k++)printf("%c", S[k]);
                    printf("\n");
                }
            }

        }
    }
    else printf("NO palindrome in the string\n");//if no palindromes are found


    return 0;
}
