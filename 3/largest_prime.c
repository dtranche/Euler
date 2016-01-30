#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

uint64_t primes[1000000];
uint64_t factors[1000000];
uint32_t last_prime_index = 0;

int cmp(const void * a, const void * b ) {
     return ( *(uint64_t*) a - *(uint64_t*)b );
}

uint32_t removeDup ( uint64_t * array, uint32_t count )
{
     uint32_t src, dst;
     if ( count == 0 ) return 0;
     for ( src=dst=1; src < count; src++ ) {
          if ( array[dst-1] == array[src] ) continue;
          array[dst++] = array[src];
     }
     return dst;
}

bool isPrime ( uint64_t num )
{
     uint64_t i = 0;
     while (primes[i] != 0 ) {
          if ( primes[i] == num ) return true;
          if ( num % primes[i++] == 0 )
               return false;
     }
     primes[last_prime_index++] = num;

     return true;
}

uint32_t calculate_prime_factors ( uint64_t *arrayp , uint64_t value )
{
     uint64_t *init_addr = arrayp;
     *arrayp++ = value;
     uint64_t largest_possible_factor = (uint64_t)ceil ( sqrt ( value ) );
     uint64_t num = 3;
     if ( value % primes[0] == 0 ) {
          *arrayp++ = primes[0];
          *arrayp++ = value / primes[0];
     }
     for ( ; num <= largest_possible_factor; num+=2 ) {
          if ( isPrime ( num ) && ( value  %  num == 0 ) )  {
                    *arrayp++ = num;
                    *arrayp++ = value / num;
          }
     }
//     printf ( "%p - %p = %lu\n", arrayp, init_addr, arrayp - init_addr );
     uint32_t count = (arrayp - init_addr);
     if ( count <= 2 )
          printf ( "This is prime %lu\n", value ) ;
     return count;
}
void print_factors ( uint64_t * arrayp , uint32_t count ) {
     uint32_t i;
     for ( i = 0; i < count; i++)
          printf ( "%6lu ", arrayp[i] );
     printf("\n");
}
int main ( int argc, char ** argv )
{
     uint64_t end = 20;
     memset ( primes, 0, sizeof ( primes ) );
     isPrime ( 2 );
     isPrime ( 3 );
     isPrime ( 5 );
     if ( argc == 2 ) {
          end = strtoull ( argv[1], NULL, 10  );
     }
     uint64_t input = end;
     uint64_t solution = 0;
     uint32_t total_factors = 0;
     uint32_t iteration = 1;
     while ( solution == 0 ) {
          uint32_t num_factors = calculate_prime_factors ( &factors[total_factors], end );
          printf (" Found %u factors for %lu \n", num_factors, end );

          qsort( factors, total_factors + num_factors, sizeof ( uint64_t), cmp );
          total_factors = removeDup( factors, total_factors + num_factors );
          print_factors ( factors, total_factors );
          if ( num_factors <= 2 ) {
               solution = end;
               break;
          }
          end = factors[total_factors - iteration++ - 1];
     }
     printf ( "The largest prime found is %lu and the total number found is %u\n", primes[last_prime_index-1], last_prime_index );

     uint32_t i;
     printf ("The factors for %lu are : \n\t%6u", input, 1 );
     for ( i = 0; i < total_factors; i++) {
          printf ( "%6lu ", factors[i] );
     }
     printf("\n");
     printf ( "The solution for %lu is %lu\n",
              input,
              solution );

     return 0;
}
