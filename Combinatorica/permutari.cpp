#include <fstream>
using namespace std;
ifstream cin("permutari.in");
ofstream cout("permutari.out");

int sol[10];

void afisare(int n){

   for(int i = 1; i <= n; i++)
       cout<<sol[i]<<' ';
   cout<<'\n';
}



bool valid(int x){

    for(int i = 1; i < x; i++)
        if(sol[i]==sol[x])
            return false;
    return true;
}

void bkt(int poz, int n){

    if(poz==n+1) afisare(n);
    else{

        for(int i = 1; i <= n; i++){
         sol[poz] = i;
            if(valid(poz))
                bkt(poz+1,n);
        }
    }
}

int main()
{
   int n;
   cin>>n;
   bkt(1,n);
}
