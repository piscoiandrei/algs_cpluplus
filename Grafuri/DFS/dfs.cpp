#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
ifstream in("dfs.in");
ofstream out("dfs.out");

const int NMAX = 100005;

int n, m, cc = 0;

bool viz[NMAX];
vector<int>lista[NMAX];

void citire()
{
	in >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		in >> x >> y;
		lista[x].push_back(y);
		lista[y].push_back(x);
	}
}

void dfs(int nod)
{
	viz[nod] = true;
	for (unsigned int i = 0; i < lista[nod].size(); i++)
	{
		int vecin = lista[nod][i];
		if (!viz[vecin])
			dfs(vecin);
	}
}

int main()
{
	citire();
	//cautam componente conexe
	for (int i = 1; i <= n; i++)
		if (!viz[i])
		{
			++cc; dfs(i);
		}
	out << cc;
}


