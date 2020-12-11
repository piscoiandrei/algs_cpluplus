#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("scmax.in");
ofstream out("scmax.out");

#define NMAX 100005

int maxLen = 1, best[NMAX], poz[NMAX];
int v[NMAX];
int n, pmax, p;
int main()
{
	in >> n;
	for (int i = 1; i <= n; i++) in >> v[i];

	best[n] = 1;
	poz[n] = -1;
	pmax = 1; p = n;

	for (int i = n - 1; i >= 1; i--)
	{
		best[i] = 1;
		poz[i] = -1;

		for (int j = i + 1; j <= n; j++)
		{
			if (v[i] < v[j] && best[i] < best[j] + 1)
			{
				best[i] = best[j] + 1;
				poz[i] = j;

				if (best[i] > pmax)
				{
					pmax = best[i];
					p = i;
				}
			}
		}
	}

	out << pmax << '\n';

	int x = p;

	while (x != -1)
	{
		out << v[x] << ' ';
		x = poz[x];
	}

}
