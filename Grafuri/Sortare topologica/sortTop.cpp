#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;
ifstream in("sortaret.in");
ofstream out("sortaret.out");
#define NMAX 50005
//Topological Order, on Directed Acyclic Graph(the only way possible)
bool vis[NMAX];
vector<int>adjList[NMAX], ordering;
int n, m;

void citire()
{
    in >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        in >> x >> y;
        adjList[x].push_back(y);
    }
}

void dfs(int nod)
{
    vis[nod] = true;
    for (unsigned int i = 0; i < adjList[nod].size(); i++)
    {
        int v = adjList[nod][i];
        if (!vis[v])
            dfs(v);
    }
    ordering.push_back(nod);// needs reverse to print in correct order
}

int main()
{
    citire();
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    reverse_copy(ordering.begin(), ordering.end(), ostream_iterator<int>(out, " "));
}
 


