#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("rucsac.in");
ofstream out("rucsac.out");

#define nmax 10005

int best[nmax][nmax], n, p[nmax], w[nmax],wmax;

int main()
{
	in >> n >> wmax;
	for (int i = 1; i <= n; i++)
	{
		in >> w[i] >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= wmax; j++)
		{
			best[i][j] = best[i - 1][j];
			if (w[i]<=j)
				best[i][j] = max(best[i - 1][j], best[i - 1][j - w[i]] + p[i]);
		}
	}
	out << best[n][wmax];
}

