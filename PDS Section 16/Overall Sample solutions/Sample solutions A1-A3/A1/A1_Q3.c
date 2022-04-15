/*
Complex numbers are represented geometrically as a point in a 2D Argand plane, where the
x-axis denotes the real part and the y-axis denotes the imaginary part. Take input one complex
number from the keyboard. Hence reflect this complex number in the Argand plane with respect
to the vertical y-axis.
(a) Display the reflected complex number in the form “a + ib” (i.e if the real part is 2 and the
imaginary part is -5 then you should display “2-i5” on the screen).
(b) Additionally, display the area enclosed by the rectangle between the horizontal x-axis (the
real axis) and the straight horizontal line connecting the two complex numbers, i.e the
original and the reflected complex number. The other two sides of the rectangle are the
vertical height of the imaginary part of the two complex numbers.
[Hint: For input, maintain two separate variables, one denoting the real and the other
imaginary part for one complex number. You can assume all integer variables.]
*/

#include<stdio.h>

int main()
{
    //initialize the variables
    //x represents real part of the complex number
    //y is the imaginary part
    
    int x,y;
    
    printf("Enter the real part of the complex number:"); //prompt the user to enter the real part
    scanf("%d",&x); //store the input in x

    printf("Enter the imaginary part of the complex number:"); //prompt the user to enter the imaginary part
    scanf("%d",&y); //store the input in y

    printf("The original complex number is: %d+i%d \n",x,y);

    //after reflecting the complex number a+ib about the y axis,it becomes -a+ib
    x=-x;
    printf("After reflecting,the complex number is:%d+i%d \n",x,y);

    /* The area enclosed by the rectangle between the x-axis  and the straight horizontal line connecting the two complex numbers.
     The other two sides of the rectangle are the vertical height of the imaginary part of the two complex numbers.*/
    /*The length of the rectangle is 2x and breadth is y.*/
    /*So area is 2*x*y.*/

    printf("the area of the required rectangle is=%d square units",(2*x*y));

    return 0;

}
