#include <iostream>

int main ( int argc, char * argv[] )
{

  int a = 3;
  int &b = a;
  int &c = b;

  std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
  b = 5;
  std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
  c = 4;
  std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;

  const int &d = a;
  std::cout << "a = " << a << " b = " << b << " c = " << c <<  " d = " << d << std::endl;

  a = 2;
  std::cout << "a = " << a << " b = " << b << " c = " << c <<  " d = " << d << std::endl;
  return 0;
};
