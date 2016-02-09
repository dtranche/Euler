#include "BigInt.h"
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
namespace now
{
  BigInt::BigInt () :
    _positive ( true )

  {
    //std::cout << "The maximum size of this integer is " << _digits.max_size() << " digits" << std::endl;
    //    _digits.push_back(0);
  }

  BigInt::BigInt ( int64_t num ) : _positive ( true )
  {
    std::string num_str = std::to_string ( num );
    if ( num < 0 ) {
      num_str.erase(0,1);
      _positive = false;
    }
    for ( auto it = num_str.rbegin ( );
          it != num_str.rend();
          it++) {
      _digits.push_back ( *it - '0' );
    }
    //std::cout << " ctor int " << *this << std::endl;
  }

  BigInt::BigInt ( std::string num ) : _positive ( true )
  {
    if ( num[0] == '-' ) {
      num.erase(0,1);
      _positive = false;
    }
    for ( auto it = num.rbegin ( );
          it != num.rend();
          it++) {
      _digits.push_back ( *it - '0' );
    }
  }

  BigInt::BigInt( const BigInt& other ) :
    _digits ( other._digits ),
    _positive ( other._positive )
  {
    //std::cout << "BigInt copy constructor " << *this <<std::endl;
  }

  BigInt & BigInt::operator= ( const BigInt & other )
  {
    //std::cout << "BigInt assignment operator" << std::endl;

    if ( this != &other ) {
      _digits.empty();
      _digits = other._digits;;
      _positive = other._positive;
    }
    return *this;
  }

  inline const BigInt & BigInt::operator- ( )
  {
    _positive = !(_positive);
    return *this;
  }
  const BigInt & BigInt::operator+= ( const BigInt & rhs )
  {
    uint32_t temp;
    uint32_t carry = 0;

    if ( !rhs.num_digits ( ) ) return *this;
    /* TODO handle a += a */

    auto it = _digits.begin ();
    auto rhs_it = rhs._digits.begin ();
    while ( !( it == _digits.end () || rhs_it == rhs._digits.end ( ) ) ){
      temp = (*it) + (*rhs_it) + carry;
      *it = temp % 10;
      carry = temp / 10;
      /* This is here since the while loop breaks when the first is hit */
      it++; rhs_it++;
    }
    /* The logic here is if the num_digits for the rhs is > the current number of digits then we need to push them onto the digit vector *
     * adding the carry value when needed *
     * If the num_digits is >= rhs.num_digits then the carry value must be added if it exists
     */
    if ( carry && num_digits ( ) == rhs.num_digits ( ) ) {
      _digits.push_back ( carry );
    } else if ( carry && num_digits ( ) > rhs.num_digits ( ) ) {
      while ( it != _digits.end ( ) && carry ) {
        temp = *it + carry;
        *it = temp % 10;
        carry = temp /10;
        it++;
      }
      if ( carry ) _digits.push_back ( carry );
    }
    else if ( num_digits ( ) < rhs.num_digits ( ) ) {
      while ( rhs_it != rhs._digits.end ( ) ) {
        temp = (*rhs_it) + carry;
        _digits.push_back (  temp % 10 );
        carry = temp / 10;
        rhs_it++;
      }
      if ( carry ) _digits.push_back ( carry );
    }
    return *this;
  }

  const BigInt & BigInt::operator-= ( const BigInt & rhs )
  {
    uint32_t temp;
    bool carry = false;
    bool negate = false;
    /* Do the easy case first this > rhs */

    BigInt left(*this);
    BigInt right(rhs);
    if ( left < right ) {
      negate = true;
      std::swap (left, right );
    }
    auto rhs_it = right._digits.begin ( ) ;
    auto it     = left._digits.begin ( );
    while ( rhs_it != right._digits.end ( ) ) {
      uint32_t  temp = *it;
      if ( carry ) temp--;
      if ( *it < *rhs_it ) {
        carry = true;
        *it = 10 + temp - *rhs_it;
      }
      else {
        *it = temp - *rhs_it;
        carry = false;
      }
      it++; rhs_it++;
    }
    while ( carry && it != left._digits.end() ) {
      if ( *it == 0 ) {
        *it = 9;
      } else {
        *it -= 1;
        carry = false;
      }
      it++;
   }
    /* Remove leading zeros */
    while ( true ) {
      it =  left._digits.end ( ) - 1;
      if ( *it != 0 ) break;
      left._digits.pop_back ( );
    }
    std::swap ( left, *this );
    if ( negate ) _positive = false;
    return *this ;
  }

  const BigInt & BigInt::operator*= ( int64_t num )
  {
    if ( num < 0 ) {
      _positive = !_positive;
      num = -num;
    }
    uint64_t carry = 0;

    for ( auto it = _digits.begin (); it != _digits.end ( ); it++ ) {
      uint64_t temp = (*it) * num + carry;
      *it = temp % 10;
      carry = temp / 10;
    }
    if ( carry ) {
      std::string num_str = std::to_string ( carry );
      for ( auto it = num_str.rbegin ( );
            it != num_str.rend();
            it++) {
        _digits.push_back ( *it - '0' );
      }
    }
    return *this;
  }
  const BigInt & BigInt::operator*= ( const BigInt & rhs )
  {
    BigInt result;
    //    std::cout << "Multiplying " << *this << " by " << rhs << std::endl;
    if ( rhs.isNegative ( ) ) _positive = !_positive;
    uint32_t digit = rhs.num_digits ( );
    for ( auto it = rhs._digits.crbegin (); it != rhs._digits.crend ( ); it++ ) {
      if ( *it == 0 ) {
        digit--;
        continue;
      }
      BigInt cpy = *this;
      cpy *= (*it);
      for ( auto i = digit;  i > 1 ; i-- ) {
        cpy *= 10;
      }
      digit--;
      result += cpy;

    }
    std::swap ( result, *this );
    return * this;
  }

  /* Binary operators */
  /* Non-member functions are below here */

  BigInt operator+( const BigInt & lhs, const BigInt & rhs )
  {
    BigInt temp ( lhs );
    temp += rhs;
    return temp;
  }

  /* Relational operators  */
  bool operator < ( const BigInt &lhs, const BigInt &rhs )
  {
    if ( &lhs == &rhs ) return false;  /* These are the same */
    /* if lhs is negate and rhs is positive lhs < rhs */
    if ( lhs.isNegative ( ) && !( rhs.isNegative ( ) ) ) return true;
    /* if lhs isPositive and rhs is negative  rhs < lhs */
    if ( !(lhs.isNegative ( ) ) && rhs.isNegative ( )  ) return false;

    if ( lhs._digits.size () < rhs._digits.size() ) return true;
    if ( lhs._digits.size () > rhs._digits.size() ) return false;
    auto lhs_it = lhs._digits.crbegin();
    auto rhs_it = rhs._digits.crbegin();
    /* At this point the sizes are the same */
    while ( lhs_it !=  lhs._digits.crend() ) {
      if (*lhs_it < *rhs_it ) return true;
      if (*lhs_it < *rhs_it ) return false;
      ++lhs_it; ++rhs_it;
    }
    /* same number */
    return false;
  }

  bool operator > ( const BigInt &lhs, const BigInt &rhs )
  {
    return ( rhs < lhs );
  }

  bool operator <= ( const BigInt &lhs, const BigInt &rhs )
  {
    return ! ( rhs < lhs );
  }

  bool operator >= ( const BigInt &lhs, const BigInt &rhs )
  {
    return ! ( lhs < rhs );
  }

  bool operator == ( const BigInt &lhs, const BigInt &rhs )
  {
    return  ( ( lhs >= rhs ) && ( lhs <= rhs ) );
  }
  bool operator != ( const BigInt &lhs, const BigInt &rhs )
  {
    return  ( ! ( lhs == rhs ) );
  }

  /* output stream to view the number as a string */
  std::ostream & operator<< ( std::ostream & out , const BigInt & big )
  {
    /* by default uint8_t == char which prints ascii value*/
    if (!big._positive) out << "-";
    for ( auto it = big._digits.crbegin ( );
          it != big._digits.crend();
          it++) {
      out << static_cast<uint32_t>( *it );
    }

    return out;
  }
} /* namespace */
