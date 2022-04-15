/*
Given the base radius and total surface area (curved surface area + top circular area + bottom
circular area) of an enclosed right circular cylinder in cm, first calculate the height of the cylinder
(in cm) and then find its volume (in cm3). Hence, calculate the cost of storing a perfume to fill
exactly (2/3)rd of the cylinder at an amount of Rs.10 per cubic centimeter and the remaining
volume is filled with Nitrogen gas at Rs.2 per cubic centimeter. Your input should be the radius
and surface area of the cylinder (in cm and cm2 respectively) and you should display the height,
volume and the cost of storing the perfume with the Nitrogen gas.
Assume,
π = 3.141
Curved surface area of cylinder = 2*π*base radius*height
Volume = π*radius2*height
*/

#include <stdio.h>

int main()
{
 //declaring the variables
 float r,h,tsa,csa,vol,cost;

 //input the base radius and the curved surface area
 printf("Enter the base radius\n");
 scanf("%f",&r);

 printf("Enter the total surface area\n");
 scanf("%f",&tsa);

 //calculating curved surface area
 csa=tsa-(2*3.141*r*r);

 //calculating the height
 h=csa/(2*3.141*r);

 //calculating volume of cylinder
 vol=3.141*r*h;

 //calculating the cost of storing perfume
 cost=0.67*vol*10+0.33*vol*2;

 //printing the results
 printf("Height:%1.3f\n",h);
 printf("Volume of the Cylinder:%1.3f\n",vol);
 printf("The Total Cost: Rs%1.2f\n",cost);

 return 0;
}
