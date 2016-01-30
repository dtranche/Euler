#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
bool isPalindrome( uint32_t value )
{
  uint32_t nDigits = (uint32_t) log10 ( value ) + 1;
  // printf("The number of digit in %u is %u\n",
  //                value, nDigits );
  uint8_t  * digits = calloc ( nDigits, sizeof ( uint8_t ) );
  uint32_t i;
  for ( i = 0; i < nDigits; i++ ) {
    digits[i] = value % 10;
    value /= 10;
    //    printf ("Digits[%u] = %u\n", i, digits[i]);
  }

  for ( i = 0 ; i < nDigits/2; i++ ) {
    if ( digits[i] != digits[nDigits-1-i] ) return false;
  }
  return true;
}


int main ( int argc, char ** argv )
{
  uint32_t num = 0;
  if ( argc == 2 )
    num = strtoul ( argv[1], NULL, 10 );
  /*  printf ( " Is %u is a palindrome? %s\n",
           num, isPalindrome(num) ? "TRUE" : "FALSE");
  return 0;
  */
  uint32_t i = 100;
  uint32_t j = 100;
  uint32_t max_pal = 0;
  for ( i = 100; i < 1000; i++ ) {
    for ( j = 100; j < 1000; j++ ) {
      num = i * j;
      if ( isPalindrome ( num ) ) {
        if ( num > max_pal ) {
          max_pal = num;
          printf ( "%u is a palindrome for %u x %u\n",
                   num, i, j );
        }
      }
    }
  }
  printf("The largest palindrome is %u\n", max_pal );
  return 0;
}
