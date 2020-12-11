#include <fstream>
using namespace std;
ifstream cin("aranjamente.in");
ofstream cout("aranjamente.out");
int sol[10];
int n,k;

void afisare()
{
    for(int i = 1; i <= k; i++)
        cout<<sol[i]<<' ';
    cout<<'\n';
}
bool valid(int pos)
{
    for(int i = 1; i < pos; i++)
        if(sol[pos]==sol[i])
            return false;
    return true;
}

void bkt(int pos){
   if(pos == k+1) afisare();
   else
   for(int i = 1; i <= n; i++){
       sol[pos] = i;
       if(valid(pos))
         bkt(pos+1);
   }
}

int main()
{
     cin>>n>>k;
     bkt(1);
}
