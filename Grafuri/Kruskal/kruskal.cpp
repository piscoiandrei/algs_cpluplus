#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;

//ifstream in("apm.in");
//ofstream out("apm.out");
ifstream in("source.in");
ofstream out("source.out");

#define NMAX 200005

struct edge{ // edge from x y
	int x;
	int y;
	int cost;
};
bool comparator(const edge& lhs, const edge& rhs)
{
	return lhs.cost < rhs.cost;
}

vector<edge> graph;
vector<pair<int, int>> solution;

int n, m, total = 0;
int t[NMAX], rang[NMAX];

void read()
{
	in >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, c;
		in >> x >> y >> c;
		graph.push_back({ x,y,c });
		//graph.push_back({ y,x,c});

		t[i] = i;
		rang[i] = 1;
	}

	sort(graph.begin(), graph.end(), &comparator);

}

int find(int nod) // cautam tatal nodului curent
{
	while (t[nod] != nod)
		nod = t[nod];
	return nod;
}

void Union(int x, int y)
{
	if (rang[x] < rang[y])
		t[x] = y;

	if (rang[x] > rang[y])
		t[y] = x;

	if (rang[x] == rang[y]) // daca 2 tati de arbori au acelasi rang
	{                       // ii crestem rangul unuia la intamplare
		t[x] = y;          // si updatam tatal unui arbore cu celalalt => ii unim
		rang[y]++;
	}

}

void solve()
{
	for (const auto& e : graph) // parcurgem graful
	{
		int tatal_x = find(e.x);
		int tatal_y = find(e.y);

		if (tatal_x != tatal_y) // verificam pt cicluri
		{
			Union(tatal_x,tatal_y);
			solution.push_back({ e.x,e.y });
			total += e.cost;
		}
	}
}

void print()
{

	out << total << '\n';
	out << solution.size()<<'\n';

	for (const auto& p : solution)
	{
		out << p.first << ' ' << p.second << '\n';
	}
}

int main()
{
	read();
	solve();
	print();
}
