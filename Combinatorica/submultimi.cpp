#include <iostream>
//#include <fstream>
using namespace std;

//ifstream cin("submultimi.in");
//ofstream cout("submultimi.out");

int n;
int sol[20];

void afisare(int x)
{
	for (int i = 1; i <= x; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}

void bkt(int pas)
{
	for (int i = 1; i <= n; i++)
	{
		sol[pas] = i;
		if (sol[pas - 1] < sol[pas])
		{
			afisare(pas);
			bkt(pas + 1);
		}
	}

}


int main()
{
	cin >> n;
	bkt(1);
}
