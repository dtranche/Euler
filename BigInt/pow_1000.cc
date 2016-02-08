#include <iostream>
#include <sstream>
#include "BigInt.h"
using namespace now;
/* This solves Euler #16 */
int main ( int argc, char * argv[ ] )
{
  BigInt pow_2 ( 1 );
  for ( int i = 1; i < 1001; i++ ) {
    pow_2 *= 2;
  }

  std::ostringstream stream;
  stream << pow_2;
  std::string str = stream.str( );
  uint32_t num = 0;
  for ( auto it = str.begin ( ); it != str.end ( ); it++ ) {
    num += (*it) - '0';
  }
  std::cout << " The sum of the digits on 2^1000 factorial is " << num << std::endl;

  return 0;
}
