/*
* Section 11
* Roll No. : 21BT10010
* Name : Bidyankur Singha
* Group No. : 1
* Test Problem No. : 01
* Description : To find the unique number greater than n with more than 4 factors
*/
#include<stdio.h>
int main ()
    { int n , m , t , temp ,  c = 0 , d , digits[10] = {0,0,0,0,0,0,0,0,0,0} , u = 1 , f = 0 ;
      printf("Enter n\n") ;
      scanf("%d" , &n ) ;
      printf("n = %d\n" , n ) ;
      m = n ;
      while ( u == 1 || f < 4 )
        { u = 0 ;
          f = 0 ;
          t = ++ m ;
          while ( t > 0 )
            { d = t % 10 ;
              temp = t / 10 ;
              while ( temp > 0 )
                { if ( temp % 10 == d )
                    u = 1 ;
                  temp/= 10 ;
                }
              t /= 10 ;
            }
          for ( int i = 2 ; i < m ; i++ )
            { if ( m % i == 0 )
                f++ ;
            }
        }
      printf( "m = %d\n" , m ) ;
      printf( "All the factors of m other than 1 and m : " ) ;
      for ( int i = 2 ; i < m ; i++ )
            { if ( m % i == 0 )
                { if ( f == 1 )
                    printf( "%d\n" , i ) ;
                  else
                    printf( "%d, " , i ) ;
                  f-- ;
                }
            }
      f = 10 ;
      while ( m > 0 )
        { d  = m % 10 ;
          for ( int i = 0 ; i <= 9 ; i++ )
            { if ( d == i )
                {digits[i]++ ;
                 f-- ;
                }
            }
          m /= 10 ;
        }
      for ( int i = 0 ; i <= 9 ; i++ )
        { if ( digits[i] == 0 )
            c = 1 ;
        }
      if ( c == 1 )
        { printf( "The digits that m does not have are ") ;
          for ( int i = 0 ; i <= 9 ; i++ )
           { if ( digits[i] == 0 )
                { if ( f == 1 )
                    printf( "%d\n" , i ) ;
                  else
                    printf( "%d, " , i ) ;
                  f-- ;
                }
           }
        }
      else
        printf("m has all digits") ;
      return 0 ;
    }
