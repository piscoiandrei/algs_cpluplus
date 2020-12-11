#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("source.in");
ofstream out("source.out");

int lcs[1005][1005];

int main()
{
	char s1[1005];
	char s2[1005];

	in.getline(s1, 1002);
	in.getline(s2, 1002);

	int n, m;
	n = strlen(s1);
	m = strlen(s2);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i-1] == s2[j-1])
				lcs[i][j] = 1 + lcs[i - 1][j - 1];
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	out << lcs[n][m] << '\n';

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			out << lcs[i][j] << ' ';
		}
		out << '\n';
	}
}


