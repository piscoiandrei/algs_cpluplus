#include <bits/stdc++.h>
#define SIZE 4
using namespace std;
/**  important operations
 x >>= 1; // divide by 2
 x <<= 1; // multiply by 2



 //  Function to check if x is power of 2
bool isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0
     return x && (!(x & (x - 1)));
}


//Count set bits in integer

int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x-1);   <--- IMPORTANT  // scadem cel mai nesemnificativ bit
        count++;
    }
    return count;
}

// check if n is a power of 2

int isTwoPower(long n) {
    return ( n & (n - 1) ) == 0 ;
}

**/

bool even(int x);

bitset<SIZE> set_bit(bitset<SIZE> x, int n); // sets the bit at the n'th position

bitset<SIZE> unset_bit(bitset<SIZE> x, int n); // unsets the bit at the n'th position

bool read_bit(int x, int n);// reads the bit at the n'th pos

bitset<SIZE> toggle_bit(bitset<SIZE> x, int n); // toggles the bit (from 1 to 0 and from 0 to 1)

bitset<SIZE> clear_LSB_to_n(bitset<SIZE>x, int n); // unsets all the bits from the least significant bit to  the n'th bit

bitset<SIZE> clear_MSB_to_n(bitset<SIZE>x, int n); // unsets all the bits from MSB to the n'th bit

int MSB_position(int x);

/**  IN ORDER TO WRITE/READ/TOGGLE etc  A BIT IN A NUMBER LARGER THAN NORMAL (e.g. 64 BITS)

     ---------------- USE '1LL' instead of a normal '1' ---------------
                          ----
*/
int main()
{
   bitset<SIZE> a = 0b0100;
   bitset<SIZE> b = 0b1111;
   //cout<<read_bit(88,2);
}

bool even(int x)
{
    return x&1 ?  false :  true;
}

bitset<SIZE> set_bit(bitset<SIZE> x, int n)
{
   x |= (1<<n);
   return x;
}

bitset<SIZE> unset_bit(bitset<SIZE> x, int n)
{
   x &= ~(1<<n);
   return x;
}

bitset<SIZE> toggle_bit(bitset<SIZE> x, int n)
{
    return (x ^= (1<<n));
}

bitset<SIZE> clear_LSB_to_n(bitset<SIZE>x, int n)
{
    return x &=(~((1<<n)-1));
}

bool read_bit(int x, int n)
{
  x = (x>>n)&1;
  return x;

}

bitset<SIZE> clear_MSB_to_n(bitset<SIZE>x, int n)
{
    return x&=((1<<n)-1);
}
int MSB_position(int x)
{
    int counter = -1;
    while(x)
    {
        x>>=1;
        counter++;
    }
    return counter;
}

int lsb(int i)
{
    return i & -i;
    // Returns the value of the least significant bit (LSB)
  // lsb(108) = lsb(0b1101100) =     0b100 = 4
  // lsb(104) = lsb(0b1101000) =    0b1000 = 8
  // lsb(96)  = lsb(0b1100000) =  0b100000 = 32
  // lsb(64)  = lsb(0b1000000) = 0b1000000 = 64
}


/**    SWAP 2 VARIABLES WITHOUT A 3rd VARIABLE

#include <iostream>
using namespace std;

int toggle_bit(int x, int n){
   return (x^=(1<<n));
}

bool read_bit(int x, int n){
   return ((x>>n)&1);
}

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i = sizeof(n)*8 - 1; i>=0; i--){
    if(read_bit(n,i)!=read_bit(m,i)){
       n = toggle_bit(n,i);
       m = toggle_bit(m,i);
    }
  }
  cout<<n<<' '<<m;
}
*/
