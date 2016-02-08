/* The following code tests the now::BigInt *
 * It can be built with clang *
 * clang++ -std=c++11 -Wall -o bigint_test bigint_test.cc BigInt.cc *
 */

#include <iostream>
#include "BigInt.h"

using namespace now;
int main ( int argc, char * agrv[] )
{
  /* Three constructors */
  BigInt a = 17;
  BigInt b ( 14 );
  BigInt c ( "12345678901011121314151617" );

  BigInt d = c; // Calls copy constructor
  BigInt e(d);  // Calls copy constructor

  BigInt f = 59;
  BigInt g = 43;


  std::cout << " The number of digits for a is " << a.num_digits ( ) << " for "  << a << std::endl;
  std::cout << " The number of digits for b is " << b.num_digits ( ) << " for "  << b << std::endl;
  std::cout << " The number of digits for c is " << c.num_digits ( ) << " for "  << c << std::endl;
  std::cout << " The number of digits for d is " << e.num_digits ( ) << " for "  << d << std::endl;
  std::cout << " The number of digits for e is " << e.num_digits ( ) << " for "  << e << std::endl;

  std::cout << " Is " << a << " < " <<  b << " " << std::boolalpha << (a < b) <<  std::endl;
  std::cout << " Is " << a << " > " <<  b << " " << std::boolalpha << (a > b) <<  std::endl;
  std::cout << " Is " << a << " <= " <<  b << " " << std::boolalpha << (a <= b) <<  std::endl;
  std::cout << " Is " << a << " >= " <<  b << " " << std::boolalpha << (a >= b) <<  std::endl;
  std::cout << " Is " << a << "  == " <<  b << " " << std::boolalpha << (a == b) <<  std::endl;

  b += a;
  std::cout << " Is " << a << " < " <<  b << " " << std::boolalpha << (a < b) <<  std::endl;
  std::cout << " Is " << a << " > " <<  b << " " << std::boolalpha << (a > b) <<  std::endl;
  std::cout << " Is " << a << " <= " <<  b << " " << std::boolalpha << (a <= b) <<  std::endl;
  std::cout << " Is " << a << " >= " <<  b << " " << std::boolalpha << (a >= b) <<  std::endl;
  std::cout << " Is " << a << "  == " <<  b << " " << std::boolalpha << (a == b) <<  std::endl;

  g += f;

  f += g;
  std::cout << " The number of digits for g is " << g.num_digits ( ) << " for "  << g << std::endl;
  std::cout << " The number of digits for f is " << f.num_digits ( ) << " for "  << f << std::endl;

  BigInt _a = 1;
  BigInt _b = 999;

  _b += _a;
  /*
  BigInt _c = 1;
  BigInt _d = 999;
  _c += _d ;
  std::cout << " The number of digits for _b is " << _b.num_digits ( ) << " for "  << _b << std::endl;
  std::cout << " The number of digits for _c is " << _c.num_digits ( ) << " for "  << _c << std::endl;

  std::cout << _b << " + " << _c << " = " << ( _b + _c ) << std::endl;

  std::cout << _b << " + " << 4 << " = " << ( _b + 4 ) << std::endl;

  _c *= 129875;
  std::cout << " The number of digits for _c is " << _c.num_digits ( ) << " for "  << _c << std::endl;

  _c *= 129875;
  std::cout << " The number of digits for _c is " << _c.num_digits ( ) << " for "  << _c << std::endl;

  _c *= 129875;
  std::cout << " The number of digits for _c is " << _c.num_digits ( ) << " for "  << _c << std::endl;

  _c *= 129875;
  std::cout << " The number of digits for _c is " << _c.num_digits ( ) << " for "  << _c << std::endl;
  */
  BigInt _num ( 123);
  std::cout << _num << " * 10 = ";
  _num *= 10;
  std::cout << _num << std::endl;

  g *= f;
  std::cout << " The number of digits for g is " << g.num_digits ( ) << " for "  << g << std::endl;

    /*
  std::cout << "The new a is " << a << std::endl;
  std::cout << " Is c < e  "  << std::boolalpha << ( c < e )  <<  std::endl;
  std::cout << " Is c > e  "  << std::boolalpha << ( c > e )  <<  std::endl;
  std::cout << " Is c <= e "  << std::boolalpha << ( c <= e ) <<  std::endl;
  std::cout << " Is c >= e "  << std::boolalpha << ( c >= e ) <<  std::endl;
  std::cout << " Is c == e "  << std::boolalpha << ( c == e ) <<  std::endl;
  */
  return 0;
}
