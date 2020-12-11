#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
#include <string>
#include <set>
using namespace std;
//https://infoarena.ro/problema/darb
ifstream in("source.in");
ofstream out("source.out");

const int NMAX = 100005;
vector<int> Tree[NMAX];
int dist[NMAX],n;

int BFS(int startNode)
{
	int finalNode = -1;
	queue<int> q;
	q.push(startNode);

	while (!q.empty())
	{
		int node = q.front();
		finalNode = node;
		q.pop();

		for (int i = 0; i < Tree[node].size(); i++)
		{
			int adjNode = Tree[node][i];
			if (dist[adjNode] == -1)
			{
				q.push(adjNode);
				dist[adjNode] = dist[node] + 1;
			}
		}
	}
	return finalNode;
}

void MinusOne()
{
	for (int i = 0; i <= n; i++)
		dist[i] = -1;
}

void read()
{
	in >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		in >> x >> y;
		Tree[x].push_back(y);
		Tree[y].push_back(x);
	}
}
int main()
{
	read();
	MinusOne();
	dist[1] = 0;
	int start  = BFS(1);

	MinusOne();
	dist[start] = 0;
	int end = BFS(start);

	out << dist[end] + 1;
}


