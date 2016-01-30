#include <stdio.h>
#include <stdint.h>

int main ( int argc, char ** argv )
{
     uint32_t end = 20;
     uint32_t sum = 0;
     uint32_t first = 1;
     uint32_t second = 2;

     if ( argc == 2 ) {
          end = strtoul ( argv[1], NULL, 10  );
     }

     do {
          if ( second % 2 == 0 ) sum += second;
          uint32_t temp = first + second;
          first = second;
          second = temp;
     } while ( second < end );

     printf ( "Sum of even fib nums is %u\n", sum );
     return 0 ;
}
