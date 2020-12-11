#include <iostream>
//#include <fstream>
using namespace std;

//ifstream cin("combinari.in");
//ofstream cout("combinari.out");

int n, k;
int sol[20];

void afisare()
{
	for (int i = 1; i <= k; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}

void bkt(int pas)
{
	if (pas == k+1)
	{
		afisare();
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			sol[pas] = i;
			if (sol[pas - 1] < sol[pas])
			{
				bkt(pas + 1);
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	bkt(1);
}
