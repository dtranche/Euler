#include <iostream>
#include <sstream>
#include <string>
#include "BigInt.h"
using namespace now;

bool multiply_integer_test ( int64_t a, int64_t b, int64_t result )
{
  BigInt product( a );
  BigInt answer( result );
  product *= b;
  if ( product != answer )
    std::cout << product << " != " << answer << " ";
  return ( product == answer );
}
bool multiply_bigint_test ( int64_t a, int64_t b, int64_t result )
{
  BigInt product ( a );
  product *= BigInt( b );

  BigInt answer ( result );
  if ( product != answer )
    std::cout << product << " != " << answer << " ";
  return ( product == answer );
}

int main ( int argc, char * argv[] )
{
  std::cout << "Testing 123 * 7   = " << std::boolalpha << multiply_integer_test( 123,7,861 ) << std::endl;
  std::cout << "Testing 123 * 10  = " << std::boolalpha << multiply_integer_test( 123,10,1230 ) << std::endl;
  std::cout << "Testing 321 * 4   = " << std::boolalpha << multiply_integer_test( 321,4,1284 ) << std::endl;
  std::cout << "Testing 102 * 162   = " << std::boolalpha << multiply_integer_test( 102,162,16524 ) << std::endl;
  std::cout << "Testing 999 * 999   = " << std::boolalpha << multiply_integer_test( 999,999,998001 ) << std::endl;
  std::cout << "Testing -1 * -1   = " << std::boolalpha << multiply_integer_test( -1,-1,1 ) << std::endl
;
  std::cout << std::endl << std::endl;
  std::cout << "**************************************************" << std::endl;
  std::cout << "Testing 123 * 7   = " << std::boolalpha << multiply_bigint_test( 123,7,861 ) << std::endl;
  std::cout << "Testing 123 * 10  = " << std::boolalpha << multiply_bigint_test( 123,10,1230 ) << std::endl;
  std::cout << "Testing 321 * 4   = " << std::boolalpha << multiply_bigint_test( 321,4,1284 ) << std::endl;
  std::cout << "Testing 162 * 102   = " << std::boolalpha << multiply_bigint_test( 162,102,16524 ) << std::endl;
  std::cout << "Testing 999 * 999   = " << std::boolalpha << multiply_bigint_test( 999,999,998001 ) << std::endl;

  /* project Euler #20 */
  BigInt big(1);
  for ( size_t i = 1; i < 100; ++i ) {
    big *= i;
  }
  std::ostringstream stream;
  stream << big;
  std::string str = stream.str( );
  uint32_t num = 0;
  for ( auto it = str.begin ( ); it != str.end ( ); it++ ) {
    num += (*it) - '0';
  }
  std::cout << " The sum of the digits on 100 factorial is " << num << std::endl;

  /* project Euler #25 */

  BigInt Fib_n_2(1);
  BigInt Fib_n_1(1);
  BigInt Fib;
  num = 2;
  while ( true ) {
    num++;
    Fib = Fib_n_1 + Fib_n_2;
    //    std::cout<< " F(" <<num << ") = " << Fib << std::endl;
    if ( Fib.num_digits ( ) >= 1000 ) break;
    Fib_n_2 = Fib_n_1;
    Fib_n_1 = Fib;
  }
  std::cout << "After " << num << " The number of digits is " << Fib.num_digits ( ) << std::endl;
#if 0
  ///while ( Fib.num_digits ( ) < 1000 ) {

  std::cout << "The Factorial index for 1000 digits is " << num << std::endl;
  num = 0;
  for ( auto it = str.crbegin ( ); it != str.crend ( ); it++ ) {
    if ( (*it) != '0' ) break;
    num++;
  }
  std::cout << "The first non-zero index is " << num << std::endl;
#endif
  return 0;
}
