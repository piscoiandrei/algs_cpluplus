#include <iostream>
#include <cmath>
using namespace std;

#define sol_size 20

int n, sol[sol_size];

void afisare()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sol[i] == j)
				cout << '*' << ' ';
			else
				cout << '-' << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool valid(int pos)
{
	for (int i = 0; i < pos; i++)
		if (sol[i] == sol[pos] || abs(sol[i] - sol[pos]) == abs(i-pos))
			return false;
	return true;
}

void bkt(int pos)
{


	if (pos == n)
		afisare();
	else for (int i = 0; i < n; i++) {
		sol[pos] = i;
		if (valid(pos))
			bkt(pos + 1);
	}

}

int main()
{
	cin >> n;
	bkt(0);
	return 0;
}
