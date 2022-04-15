/* Take two binary numbers as input.Check if
the inputted numbers are binary or not.Also count the number of bits in both the numbers.*/

/* If both the numbers are valid binary numbers and they are of the same bit length, then,
perform bitwise XOR operation of the two binary numbers from the least significant bit onwards.*/

#include<stdio.h>
#include<math.h>

int main()
{
    //initializing the variables
    long int n1,n2;

    //taking the numbers as input
    printf("enter the binary number1:");
    scanf("%ld",&n1);
    printf("enter the binary number2:");
    scanf("%ld",&n2);

    /*NOTE:IN THE PROCESS OF FINDING THE NUMBER OF DIGITS OF N1 AND N2,
    THE ORIGINAL VALUE OF N1 AND N2 GETS MODIFIED DURING THE UPDATE EXPRESSSION
    OF THE WHILE LOOP.TO ENSURE THAT THE VALUE DOESN'T GETS LOST,I AM COPYING THEIR VALUES
    IN AUXULLARY VARIBALES TEMP1 AND TEMP2*/
    int temp1=n1;
    int temp2=n2;

    //count variables are used to count the number of digits
    int count1=0,count2=0;

    //checking if the number1 is binary and finding its number of digits
    while (n1>0)
    {
        if (n1%10!=0 && n1%10!=1)
        {
            //if there is any digit other than 1 or 0,break the loop
            printf("the number1 is not a binary number.\n");
            count1=0;
            break;
        }
        else
        {
            //counter is updated
            count1+=1;
        }
        n1=n1/10;
    }

    //checking if the number2 is binary and finding its number of digits
    //same process is again repeated
    while (n2>0)
    {
        if (n2%10!=0 && n2%10!=1)
        {
            printf("the number2 is not a binary number.\n");
            count2=0;
            break;
        }
        else
        {
            count2+=1;
        }
        n2=n2/10;
    }

    //checking if the binary numbers are of the same size and printing their size
    //counter==0 means that the numbers are not binary in nature
    if(count1!=0 && count2!=0)
    {
        if (count1==count2)
        {
        printf("the numbers are of the same bit.\n");
        printf("the size of each number is:%d \n",count1);
        }
        else
        {
        printf("the numbers are not of the same bit.ERROR!\n");
        printf("the number of digits in number1:%d \n",count1);
        printf("the number of digits in number2:%d \n",count2);
        }
    }

    //performing the bitwise XOR operation
    //variable t is the result of each bitwise XOR operation
    int t;

    //we can perform the XOR operation iff both have same number of bits
    if (count1==count2)
    {
        printf("the result after XNOR operation is:");

        //iterating for both the numbers
        while(temp1>0 && temp2>0)
        {
            /*XOR IS A BINARY OPEATION.THE OUTPUT DEPENDS
            ON THE VALUE OF EITHER OF THE TWO OPERAND.USING THIS IF ELSE CONSTRUCT
            I AM CHECKING THE VALUE OF THE OPERANDS AND ASSIGNING THE RESULT TO VARIABLE T*/

            if(temp1%10==0 && temp2%10==0)
            {
                t=0;
            }
            else if(temp1%10==0 && temp2%10==1)
            {
                t=1;
            }
            else if(temp1%10==1 && temp2%10==0)
            {
                t=1;
            }
            else if(temp1%10==1 && temp2%10==1)
            {
                t=0;
            }
            //printing the results one by one(rightmost bits at first)
            printf("%d",t);

            //update expression in the while loop
            temp1=temp1/10;
            temp2=temp2/10;
        }
    }
}
