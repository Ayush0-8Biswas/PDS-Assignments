#include <stdio.h>

int main()
{
    int a1, a2, a3, a4, unique, c1, c2, c3, c4;
    int b1, b2, b3, b4;
    printf("Give 4 integers input (separated by space): ");
    scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
    unique = 1;
    b1 = a1;

    if ((a2!=b1))
    {
        b2 = a2;
        unique+=1;
    }
    else
        b2 = -1;

    if ((a3!=b1)&&(a3!=b2))
    {
        b3 = a3;
        unique+=1;
    }
    else
        b3 = -1;

    if ((a4!=b1) && (a4!=b2) && (a4!=b3))
    {
        b4 = a4;
        unique+=1;
    }
    else
        b4 = -1;

    printf("\nNo. of unique values: %d\n",unique);

    c1=b1;
    printf("\nThe numbers in non-decreasing order: ");

    switch (unique)
    {
    case 1:
        printf("%d",c1);
        break;

    case 2:
        {
            if (b2>0)
                c2 = b2;
            else if (b3>0)
                c2 = b3;
            else
                c2 = b4;

            if (c1>c2)
                printf("%d %d",c2,c1);
            else
                printf("%d %d",c1,c2);
            break;
        }
    case 3:
        {
            if (b2<0)
            {
                c2 = b3;
                c3 = b4;
            }
            else if (b3<0)
            {
                c2 = b2;
                c3 = b4;
            }
            else
            {
                c2 = b2;
                c3 = b3;
            }

            if (c1>c2)
            {
                if (c1>c3)
                {
                    if (c2>c3)
                    {
                        printf("%d %d %d",c3,c2,c1);
                    }
                    else
                    {
                        printf("%d %d %d",c2,c3,c1);
                    }
                }
                else
                {
                    printf("%d %d %d",c2,c1,c3);
                }
            }
            else
            {
                if (c1>c3)
                {
                    printf("%d %d %d",c3,c1,c2);
                }
                else
                {
                    if (c2>c3)
                    {
                        printf("%d %d %d",c1,c3,c2);
                    }
                    else
                    {
                        printf("%d %d %d",c1,c2,c3);
                    }
                }
            }
            break;
        }

    case 4:
        {
            c2 = b2;
            c3 = b3;
            c4 = b4;

            if (c1>c2)
            {
                if (c1>c3)
                {
                    if (c1>c4)
                    {
                        if (c2>c3)
                        {
                            if (c2>c4)
                            {
                                if (c3>c4)
                                {
                                    printf("%d %d %d %d",c4,c3,c2,c1);
                                }
                                else
                                {
                                    printf("%d %d %d %d",c3,c4,c2,c1);
                                }
                            }
                            else
                            {
                                printf("%d %d %d %d",c3,c2,c4,c1);
                            }
                        }
                        else
                        {
                            if (c2>c4)
                            {
                                printf("%d %d %d %d",c4,c2,c3,c1);
                            }
                            else
                            {
                                if (c3>c4)
                                {
                                    printf("%d %d %d %d",c2,c4,c3,c1);
                                }
                                else
                                {
                                    printf("%d %d %d %d",c2,c3,c4,c1);
                                }
                            }
                        }
                    }
                    else
                    {
                        if (c2>c3)
                        {
                            printf("%d %d %d %d",c3,c2,c1,c4);
                        }
                        else
                        {
                            printf("%d %d %d %d",c2,c3,c1,c4);
                        }
                    }
                }
                else
                {
                    if (c1>c4)
                    {
                        if (c2>c4)
                        {
                            printf("%d %d %d %d",c4,c2,c1,c3);
                        }
                        else
                        {
                            printf("%d %d %d %d",c2,c4,c1,c3);
                        }
                    }
                    else
                    {
                        if (c3>c4)
                        {
                            printf("%d %d %d %d",c2,c1,c4,c3);
                        }
                        else
                        {
                            printf("%d %d %d %d",c2,c1,c3,c4);
                        }
                    }
                }
            }
            else
            {
                if (c1>c3)
                {
                    if (c1>c4)
                    {
                        if (c3>c4)
                        {
                            printf("%d %d %d %d",c4,c3,c1,c2);
                        }
                        else
                        {
                            printf("%d %d %d %d",c3,c4,c1,c2);
                        }
                    }
                    else
                    {
                        if (c2>c4)
                        {
                            printf("%d %d %d %d",c3,c1,c4,c2);
                        }
                        else
                        {
                            printf("%d %d %d %d",c3,c1,c2,c4);
                        }
                    }
                }
                else
                {
                    if (c1>c4)
                    {
                        if (c2>c3)
                        {
                            printf("%d %d %d %d",c4,c1,c3,c2);
                        }
                        else
                        {
                            printf("%d %d %d %d",c4,c1,c2,c3);
                        }
                    }
                    else
                    {
                        if (c2>c3)
                        {
                            if(c2>c4)
                            {
                                if (c3>c4)
                                {
                                    printf("%d %d %d %d",c1,c4,c3,c2);
                                }
                                else
                                {
                                    printf("%d %d %d %d",c1,c3,c4,c2);
                                }
                            }
                            else
                            {
                                printf("%d %d %d %d",c1,c4,c2,c3);
                            }
                        }
                        else
                        {
                            if (c2>c4)
                            {
                                printf("%d %d %d %d",c1,c4,c2,c3);
                            }
                            else
                            {
                                if (c3>c4)
                                {
                                    printf("%d %d %d %d",c1,c2,c4,c3);
                                }
                                else
                                {
                                    printf("%d %d %d %d",c1,c2,c3,c4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
