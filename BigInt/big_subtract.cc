#include <iostream>
#include <sstream>
#include <string>
#include "BigInt.h"
using namespace now;

bool subtract_integer_test ( int64_t a, int64_t b, int64_t result )
{
  BigInt product( a );
  BigInt answer( result );
  product -= b;
  if ( product != answer )
    std::cout << product << " != " << answer << " ";
  return ( product == answer );
}
bool subtract_bigint_test ( int64_t a, int64_t b, int64_t result )
{
  BigInt product ( a );
  product -= BigInt( b );

  BigInt answer ( result );
  if ( product != answer )
    std::cout << product << " != " << answer << " ";
  return ( product == answer );
}

int main ( int argc, char * argv[] )
{
  //subtract_integer_test( 9,7,2 );
  //subtract_integer_test( 10,7,3 );

  std::cout << "Testing 9 - 7   = "  << std::boolalpha << subtract_integer_test( 9,7,2 ) << std::endl;
  std::cout << "Testing 10 - 7   = "  << std::boolalpha << subtract_integer_test( 10,7,3 ) << std::endl;
  std::cout << "Testing 1000 - 1   = "  << std::boolalpha << subtract_integer_test( 1000,1,999 ) << std::endl;

  /*std::cout << "Testing 7 - 10   = "  << std::boolalpha << subtract_integer_test( 7,10,-3 ) << std::endl;
  std::cout << "Testing -10 - 7   = " << std::boolalpha << subtract_integer_test( -10, -7, -17 ) << std::endl;
  std::cout << "Testing 102 - 163   = " << std::boolalpha << subtract_integer_test( 102,-162,-61) << std::endl;
  */
  std::cout << std::endl << std::endl;
  /*std::cout << "**************************************************" << std::endl;
  std::cout << "Testing 123 * 7   = " << std::boolalpha << subtract_bigint_test( 123,7,861 ) << std::endl;
  std::cout << "Testing 123 * 10  = " << std::boolalpha << subtract_bigint_test( 123,10,1230 ) << std::endl;
  std::cout << "Testing 321 * 4   = " << std::boolalpha << subtract_bigint_test( 321,4,1284 ) << std::endl;
  std::cout << "Testing 162 * 102   = " << std::boolalpha << subtract_bigint_test( 162,102,16524 ) << std::endl;
  std::cout << "Testing 999 * 999   = " << std::boolalpha << subtract_bigint_test( 999,999,998001 ) << std::endl;
  */
  return 0;
}
