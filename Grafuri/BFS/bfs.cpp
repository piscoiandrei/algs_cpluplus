#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;
ifstream in("bfs.in");
ofstream out("bfs.out");

const int NMAX = 100005;
int n, m, nodStart, dist[NMAX];
vector<int>adjList[NMAX];

queue<int>q;

void citire()
{
	in >> n >> m >> nodStart;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		in >> x >> y;
		adjList[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		dist[i] = -1;
	dist[nodStart] = 0;
}

void bfs()
{
	int nod, vecin;
	while (!q.empty())
	{
		nod = q.front();
		q.pop();

		for (unsigned int i = 0; i < adjList[nod].size(); i++)
		{
			vecin = adjList[nod][i];
			if (dist[vecin] == -1)
			{
				q.push(vecin);
				dist[vecin] = dist[nod] + 1;
			}
		}
	}
}

int main()
{
	citire();
	q.push(nodStart);
	bfs();

	for (int i = 1; i <= n; i++)
		out << dist[i] << ' ';
}

