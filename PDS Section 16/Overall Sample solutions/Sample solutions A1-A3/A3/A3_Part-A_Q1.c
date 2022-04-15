/* You have ‘n’ number of balls numbered from 1 through n (1,2,3,.......,n). You are playing a game
where you select any two cards each of which has some integer number printed over it. Your
task is to choose only those balls whose associated numbers are a multiple of either of the two
numbers printed on the cards that you have selected (i.e any one or both the card numbers).
Print “Game Lost” in case no balls can be selected. You can assume
all positive integer values including 1 but excluding 0 for ‘n’, ‘x’ and ‘y’.*/

#include<stdio.h>

int main()
{
    //taking the number of balls as input
    int n;
    printf("enter the number of balls:");
    scanf("%d",&n);

    //the number that is printed on the two cards that we have picked are taken as input
    int x,y;
    printf("enter the number on the first card:");
    scanf("%d",&x);
    printf("enter the number on the second card:");
    scanf("%d",&y);

    /*in order to check if we can select any ball at all or
    not,we are initializing the count variable which will count the
    number of balls that we can pick.*/
    int count=0;

    //finding the ball whose number is either a multiple of x or y
    for (int i=1;i<=n;i++)
    {
        //checking if the number on the ball is a multiple of x
        if (i%x==0)
        {
            printf("%d \n",i);
            count+=1;
        }

        //checking if the number on the ball is a multiple of y
        else if(i%y==0)
        {
            printf("%d \n",i);
            count+=1;
        }
    }

    //if count==0,there are no balls to be selected
    if (count==0)
    {
        printf("Game Lost \n");
    }
    else
    {

    }

}
