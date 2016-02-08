#ifndef _NOW_BIGINT_H_
#define _NOW_BIGINT_H_

#include <cstdint>
#include <deque>
#include <vector>
#include <ostream>
namespace now {
  class BigInt{
  public:
    BigInt();
    BigInt(int64_t);
    BigInt(std::string);
    BigInt( const BigInt & a);
    //: bigint(a.bigint) { }

    BigInt& operator= ( const BigInt & );
    size_t num_digits ( ) const { return _digits.size ( ) ; }

    const BigInt & operator+= ( const BigInt & rhs );
    const BigInt & operator*= ( int64_t num );
    const BigInt & operator*= ( const BigInt & rhs );

    const BigInt & operator-= ( const BigInt & rhs );

    const BigInt & operator- ( );
    /*
      bool operator >  ( const BigInt& lhs, const BigInt& rhs );
      bool operator <= ( const BigInt& lhs, const BigInt& rhs );
      bool operator >= ( const BigInt& lhs, const BigInt& rhs );
    */
    /* the following operators will need to be writen */
    /* + for add */
    /* - for subtract */
    /* * for multiple */
    /* * for divide */

    /* < = > */
    /* for printing */
    friend std::ostream& operator<< ( std::ostream &out, const BigInt &);
    friend bool operator< ( const BigInt& lhs, const BigInt& rhs );

    inline bool isPositive ( ) const { return _positive;  }
    inline bool isNegative ( ) const { return !isPositive ( ); }
  private:
    std::vector<uint8_t> _digits;
    bool _positive;
  };
  BigInt operator +(const BigInt & lhs, const BigInt & rhs);
  BigInt operator -(const BigInt & lhs, const BigInt & rhs);
  BigInt operator *(const BigInt & lhs, const BigInt & rhs);
  BigInt operator *(const BigInt & lhs, int num);
  BigInt operator *(int num, const BigInt & rhs);
  BigInt operator /(const BigInt & lhs, const BigInt & rhs);
  BigInt operator /(const BigInt & lhs, int num);
  BigInt operator %(const BigInt & lhs, const BigInt & rhs);

  bool operator < ( const BigInt &lhs, const BigInt &rhs );
  bool operator > ( const BigInt &lhs, const BigInt &rhs );
  bool operator <= ( const BigInt &lhs, const BigInt &rhs );
  bool operator >= ( const BigInt &lhs, const BigInt &rhs );
  bool operator == ( const BigInt &lhs, const BigInt &rhs );
  bool operator != ( const BigInt &lhs, const BigInt &rhs );

} /* namespace */

#endif /* _NOW_BIGINT_H_ */
