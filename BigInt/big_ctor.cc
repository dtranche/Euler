#include <iostream>
#include <sstream>
#include "BigInt.h"


using namespace now;

bool construct_bigint_integer_test ( int64_t a, std::string result )
{
  BigInt big( a );
  std::ostringstream stream;
  stream << big;
  std::string str = stream.str( );
  if ( str == result ) return true;
  else
    std::cout << str << " != " << result << std::endl;
  return false;
}

int main ( int argc, char *agrv[] )
{
  construct_bigint_integer_test ( 100, "100");
  construct_bigint_integer_test ( -100, "100");
  return 0;
}
