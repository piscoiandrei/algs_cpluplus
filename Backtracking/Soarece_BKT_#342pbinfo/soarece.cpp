#include <iostream>
using namespace std;

int n, m;
int istart, jstart, istop, jstop;
int map[15][15];
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };
int nrsol;

void citire()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	cin >> istart >> jstart >> istop >> jstop;
}

void bordare()
{
	for (int i = 0; i <= n + 1; i++)
		map[i][0] = map[i][m + 1] = 1;
	for (int j = 0; j <= m + 1; j++)
		map[0][j] = map[n + 1][j] = 1;
}

void afisare()
{
	cout << '\n'; cout << '\n';
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n'; cout << '\n';
}

void bkt(int i, int j)
{
	map[i][j] = 2;
	if (i == istop && j == jstop)
	{
		nrsol++; //afisare();
	}
	else
	{
		for (int k = 0; k < 4; k++)
			if (map[i + di[k]][j + dj[k]] == 0)
				bkt(i + di[k], j + dj[k]);
	}
	map[i][j] = 0;

}

int main()
{
	citire();
	bordare();
	bkt(istart, jstart);
	cout << nrsol;
}
