/*program to find mean,standard deviation and grades of student */

#include<stdio.h>
#include<math.h>

int main()
{
    //variable and array declaration
    int a[10],sum=0;
    double mean=0.0,sd=0.0;

    //taking input of marks
    printf("Enter the marks of students\n");
    for (int i=0;i<10;i++)
    {
        printf("Student %d=",i+1);
        scanf("%d",&a[i]);

        //if marks not in range
        while(a[i]>100||a[i]<0)
        {
            printf("Error,please enter marks within range\nStudent %d=",i+1);
            scanf("%d",&a[i]); 
        }
    }

    // finding mean 
    for(int i=0;i<10;i++)
    {
        sum=sum+a[i];
    }
    mean=sum/10.0;

    // finding standard deviation
    for (int i=0;i<10;i++)
    {
        sd=sd+pow((a[i]-mean),2);
    }
    sd=sqrt(sd/10);

    //cgecking for grades and printing them
    for(int i=0;i<10;i++)
    {
        if (a[i]>=(mean+1.5*sd))
        printf("\nGrade of Student %d=10",i+1);

        else if (a[i]<(mean+1.5*sd)&&a[i]>=(mean+1.0*sd))
        printf("\nGrade of Student %d=9",i+1);

        else if (a[i]<(mean+1.0*sd)&&a[i]>=(mean+0.5*sd))
        printf("\nGrade of Student %d=8",i+1);

        else if (a[i]<(mean+0.5*sd)&&a[i]>=(mean+0*sd))
        printf("\nGrade of Student %d=7",i+1);

        else if (a[i]<(mean-0.0*sd)&&a[i]>=(mean-0.5*sd))
        printf("\nGrade of Student %d=6",i+1);

        else if (a[i]<(mean-0.5*sd)&&a[i]>=(mean-1.0*sd))
        printf("\nGrade of Student %d=5",i+1);

        else if (a[i]<(mean-1.0*sd)&&a[i]>=(mean-1.5*sd))
        printf("\nGrade of Student %d=4",i+1);

        else 
        printf("\nGrade of Student %d=FAIL",i+1);
    }

    //program completed
    return 0;
}