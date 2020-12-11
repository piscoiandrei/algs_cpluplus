#include <iostream>
using namespace std;
// https://www.infoarena.ro/ciurul-lui-eratostene
#define maxsize 1000000

bool c[maxsize];

void sieve(){
   c[1] = 1;
   for(int i = 4; i <= maxsize; i+=2)
        c[i]=true;

   for(int i = 3; i <= maxsize; i+=2){
      if(c[i]==false)
        for(int j = 3*i; j <= maxsize; j+=(i<<1))  // j += i*2;
               c[j] = true;
   }
}
int main()
{

}
