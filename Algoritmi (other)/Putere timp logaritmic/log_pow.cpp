#include <iostream>
using namespace std;

#define ll long long

ll power(ll n, ll p){

   ll sol = 1;
   for(ll i = 0; (1LL<<i)<=p; i++){
      if(((p>>i)&1LL) == 1LL)
        sol*=n;
     n*=n;
   }

   return sol;
}

#define ull unsigned long long


ull pw(ull n, ull p)
{
    ull a = n;
    ull sol = 1;

    for(ull i = 0; (1ULL<<i)<= p; i++)
    {
        if((p>>i)&1ULL)
            sol*=a;
        a*=a;
    }
    return sol;
}

int main()
{
    ll n,p;
    cin>>n>>p;
    cout<<power(n,p);
}
