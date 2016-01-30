#include <stdio.h>
#include <stdint.h>
int series_sum ( uint32_t n ) {
/* SUM = n(n+1)/2 */
     return ( n * ( n + 1) ) / 2;
}
int main ( int argc, char ** argv )
{
     uint32_t end = 1000;
     if ( argc == 2 ) {
          end = strtoul ( argv[1], NULL, 10  );
     }
     uint32_t index = 1;
     uint32_t sum = 0;
     while ( end > index * 3 ) {
          sum += index * 3;
          if ( ( ( index * 5 ) % 3 ) != 0  &&
               ( ( 5 * index < end ) ) ) {
               sum += ( index * 5 );
          }
          index++;
     }
     printf ( "The sum is %u for max %u index is index  %u\n",
              sum,
              end,
              index );
     end--;
     uint32_t num_threes = end / 3;
     uint32_t num_fives = end / 5;
     uint32_t num_same = end / ( 3*5 );
     sum = 3*series_sum ( num_threes ) + 5*series_sum ( num_fives ) - (3*5)*series_sum ( num_same );
     printf( "The series sum is %u\n", sum );
}
