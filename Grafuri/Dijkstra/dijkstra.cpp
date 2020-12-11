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

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

// DIJKSTRA with MIN-HEAP using PRIORITY QUEUE
const int NMAX = 50005;

#define PRQ priority_queue < pair<int,int>, vector<pair<int,int>>,decltype(&cmp)>
#define cmpArgs const pair<int,int>&

int n, m;
float dist[NMAX];
vector<pair<int, int>> g[NMAX];//  g[index], edge = [index,g[index].first]
                               //  cost = g[index].second

bool cmp(cmpArgs a, cmpArgs b)
{
    return a.second > b.second; //'>' crescator, fix invers ca la custom compare pt std::sort
}

void qprint(PRQ q)
{
    for (; !q.empty(); q.pop())
    {
        out << q.top().first << ' ' << q.top().second << ' ' << dist[q.top().first] << '\n';
    }
}

void read()
{
    in >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        in >> x >> y >> c;
        g[x].push_back({ y,c });
    }
    for (int i = 0; i <= n; i++)
        dist[i] = INFINITY;
}

void dijsktra(int startNode)
{
    PRQ pq(cmp);
    pq.push({ startNode,0 });// node, cost

    dist[startNode] = 0;

    while (!pq.empty())
    {
        // qprint(pq);
        int node = pq.top().first,
            cost = pq.top().second;
        pq.pop();

        if (dist[node] == cost) // makes no sense, but the program runs faster
            for (auto const& it : g[node])
            {
                int nextNode = it.first,
                    nextCost = it.second; // the cost to get to nextNode

                if (dist[node] + nextCost < dist[nextNode])
                {
                    dist[nextNode] = nextCost + dist[node];
                    pq.push({ nextNode,dist[nextNode] });
                }
            }
    }

}

void print()
{
    for (int i = 2; i <= n; i++)
        out << (dist[i] == INFINITY ? 0 : dist[i]) << ' ';
}

int main()
{
    read();
    dijsktra(1);
    print();
}
