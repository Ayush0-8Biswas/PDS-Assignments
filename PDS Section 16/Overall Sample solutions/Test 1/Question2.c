#include<stdio.h>
int main()
{
    /*Declaring variables for the number to be accepted, the longest non-decreasing subsequence,
    the length of the current subsequence,the most recent input and the number of non-decreasing subsequences*/
    int input,longSeq,currentSeq,prevInput,seqNo;
    currentSeq=1;
    //Accepting the value of the first member of the subsequence
    scanf("%d",&input);
    seqNo=0;
    for(longSeq=0;input>0;)
    {
        prevInput = input;
        scanf("%d",&input);
        if(input>=prevInput)
            currentSeq++;
        //Ending the current subsequence and checking if it was the longest
        else
        {
            if(currentSeq>longSeq)
                longSeq=currentSeq;
            currentSeq=1;
        }
        if(currentSeq==1)
            seqNo++;
    }
    printf("The number of non-decreasing subsequences is: %d",seqNo);
    printf("\nThe longest non-decreasing subsequence is: %d",longSeq);
    return 0;
}
