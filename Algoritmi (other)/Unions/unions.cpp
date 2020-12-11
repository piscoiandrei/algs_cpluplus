#include <iostream>
using namespace std;

union byte{

   uint8_t B;        //  B and bits share the same memory location
  struct{
   uint8_t b0:1;     // LSB
   uint8_t b1:1;
   uint8_t b2:1;
   uint8_t b3:1;
   uint8_t b4:1;
   uint8_t b5:1;
   uint8_t b6:1;
   uint8_t b7:1;     // MSB
  }bits;

};

void printByte(byte &x)
{
    for(int i = 0; i < 8; i++)
        cout<<(int)((x.B>>i)&1);
}

void printUsingPointer(byte *x){
   for(int i = 0; i < 8; i++)
       cout<<(int)((x->B>>i)&1);
}

int main()
{
   byte reg;
   byte *p = &reg;
   p->B = 0xFF;
   p->bits.b4 = 0;
   p->B &= ~(1<<5);
   printByte(reg);
   cout<<'\n';
   printUsingPointer(p);
}

