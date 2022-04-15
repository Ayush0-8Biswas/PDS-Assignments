//program to input a number and find the number of digits and check whether a triangle is possible using those numbers
#include <stdio.h>
//declaring i as a global variable
int i;
//defining a funtion calculate to find the number of digits
long int calculate (long int x)
{
  i = 0;
  while (x > 0)
    {
      x = x / 10;
      i++;
    }
  return i;
}

int main ()
{
  long int a, b, c;
  printf ("enter the three numbers \n");
  //accepting values from the user
  scanf ("%ld %ld %ld", &a, &b, &c);
  long int x = calculate (a);
  long int y = calculate (b);
  long int z = calculate (c);
  printf("%ld \n %ld \n %ld \n ",x,y,z);
  //checking whether the following triangle is possible or not
  if (x + y > z && y + z > x && z + x > y)
    {
      printf ("triangle is possible \n");
      if (x == y && y == z)
	printf ("equilateral \n");
      else if ((x == y && y != z) || (y == z && z != x) || (z == x && x != y))
	printf ("isosceles \n");
      else
	printf ("scalene \n");

    }
  else
    printf ("triangle not possible");
  return 0;
}
