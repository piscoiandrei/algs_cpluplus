#include <iostream>
using namespace std;

int n, sol[20];

int suma;

void afisare(int pas)
{
	cout << n << " = ";
	for (int i = 1; i < pas; i++)
		cout << sol[i] << " + ";
	cout << sol[pas];
	cout << '\n';
}

void bkt(int pas)
{
	if (suma == n)
	{
		afisare(pas - 1);
	}
	else
		for (int i = sol[pas - 1]; i <= n - suma; i++)
		{
			sol[pas] = i;
			suma += i;
			bkt(pas + 1);
			suma -= i;
		}
}

int main()
{
	sol[0] = 1;
	cin >> n;
	bkt(1);
}
