#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1030], b[1030];
int lcs[1030][1030];
int n, m;
int index, sir[1030];

void citire()
{
	in >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		in >> a[i];
	}
	for (int j = 1; j <= m; j++)
	{
		in >> b[j];
	}
}

void afisare()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			out << lcs[i][j] << ' ';
		}
		out << '\n';
	}
}

void subsir()
{
	int i = n, j = m;

	while (i && j)
	{
		if (a[i] == b[j])
		{
			sir[index++] = a[i];
			--i;
			--j;
		}
		else
		{
			if (lcs[i - 1][j] < lcs[i][j - 1])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}

}
int main()
{
	citire();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			  lcs[i][j] = 1 + lcs[i - 1][j - 1];
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	out << lcs[n][m]<<'\n';

	subsir();
	for (int i = index - 1; i >= 0; i--)
		out << sir[i] << ' ';
	//out << '\n';
	//afisare();
}


