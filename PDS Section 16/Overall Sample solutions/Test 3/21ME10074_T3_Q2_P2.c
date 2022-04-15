#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
XVBghy7J
ghfVbn@
ghjtJLI
fb$76bhK
*/

//Declaring structure
struct password
{
    char Content[50];

    int Length;
    int Uppercase;
    int Lowercase;
    int Numbers;
    int Special;
    int Size;
    int Strength;
};

//Finding no. of atrributes which are similar
float similarity(struct password a,struct password b)
{
    int attribute=0;

    //Increasing attribute by 1 if any atrribute is same for them

    if(a.Length==b.Length)
    {
        attribute++;
    }
    if(a.Lowercase==b.Lowercase)
    {
        attribute++;
    }
    if(a.Uppercase==b.Uppercase)
    {
        attribute++;
    }
    if(a.Numbers==b.Numbers)
    {
        attribute++;
    }
    if(a.Size==b.Size)
    {
        attribute++;
    }
    if(a.Special==b.Special)
    {
        attribute++;
    }
    if(a.Strength==b.Strength)
    {
        attribute++;
    }

    //returning percentage similarity
    return 100*(attribute)/7.0;
}

int main()
{
    struct password *p; //declaring structure pointer

    //Prompting user to enter n
    int n;

    printf("Enter no. of password(n) u want to store = ");
    scanf("%d",&n);

    //Allocating right space for p
    p=(struct password *)malloc(n * sizeof(struct password) );

    //inputting password
    printf("Enter Passwords :-\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",p[i].Content);

       // printf("%c",p[i].Content[0]);

        p[i].Length=strlen(p[i].Content); //length is initialized
        p[i].Size=strlen(p[i].Content);   //Size(in bytes) = Length

        //Initializing initial attributes to 0
        p[i].Uppercase=0;
        p[i].Lowercase=0;
        p[i].Numbers=0;
        p[i].Special=0;
        p[i].Strength=0;

        int first1=-1,first2=0; //for finding first upper case character

        //Creating a loop to
        for(int j=0;j<strlen(p[i].Content);j++)
        {
            //each time, if a character in password lies b/w particular ASCII value then increasing that attribute value by 1

            if(p[i].Content[j]>='A' && p[i].Content[j]<='Z')
            {
                p[i].Uppercase++;
            }
            else if(p[i].Content[j]>='a' && p[i].Content[j]<='z')
            {
                p[i].Lowercase++;
            }
            else if(p[i].Content[j]>='0' && p[i].Content[j]<='9')
            {
                p[i].Numbers++;
            }
            else
            {
                p[i].Special++;
            }
        }

        //Creating loop for finding 1st upper case letter
        int k;
        for(k=0;k<strlen(p[i].Content);k++)
        {
            if(p[i].Content[k]>='A' && p[i].Content[k]<='Z')
            {
                first1=k;
                break;
            }
        }

        for(int m=k;m<strlen(p[i].Content);m++)
        {
            if(p[i].Content[m]>='a' && p[i].Content[m]<='z')
            {
                first2=m;
                break;
            }
        }
        //now starting loop from first upper case letter and ending when first Lower case letter is found
        if(first2!=0){
        for(int l=k;l<strlen(p[i].Content);l++)
        {
            p[i].Strength++; //increasing by 1 for each character found b/w first upper case and lower case letter
            if(p[i].Content[l]>='a' && p[i].Content[l]<='z')
            {
                break; //breaking the loop after 1st lower case letter
            }
        }}
        //if upper case is present but no lower case is present
        if(first1!=(-1) && first2==0)
        {
            p[i].Strength=1;
        }
    }

    //Printing values
    for(int i=0;i<n;i++)
    {
        printf("\nPassword %d is %s\n",i+1,p[i].Content);
        printf("Length = %d\n",p[i].Length);
        printf("Uppercases = %d\n",p[i].Uppercase);
        printf("Lowercases  = %d\n",p[i].Lowercase);
        printf("Special chars= %d\n",p[i].Special);
        printf("Size = %d bytes\n",p[i].Size);
        printf("Strength = %d\n",p[i].Strength);
    }

    //Creating nested loop for finding similarity b/w any two pair
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            printf("\nSimilarity Index for (%d,%d) = %0.2f\n",i+1,j+1,similarity(p[i],p[j]));
        }
    }

    return 0;
}
