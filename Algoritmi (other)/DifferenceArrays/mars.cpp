#include <iostream>
using namespace std;
const int NMAX = 200005;
int mars[NMAX], n, m;

void print()
{
    for (int i = 1; i <= n; i++)
        cout << mars[i] << " ";
    cout << '\n';
}
//https://www.pbinfo.ro/articole/2541/smenul-lui-mars
//https://infogenius.ro/smenul-lui-mars-cpp/
int main()
{
    cin >> n >> m;

    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        mars[l] += x;
        mars[r + 1] -= x;
        print();
    }
    for (int i = 1; i <= n; i++)
    {
        mars[i] += mars[i - 1];
        cout << mars[i] << ' ';
    }
}

