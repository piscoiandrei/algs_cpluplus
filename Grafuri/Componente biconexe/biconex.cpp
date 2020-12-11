#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

ifstream in("biconex.in");
ofstream out("biconex.out");

vector<int> d, low, g[100005];//d[i] = x; x-al catelea nod vizitat este i / d = dfs spanning tree
stack<pair<int, int>> s; // retinem muchiile parcurse in dfs
vector<vector<int>> ans;
int n, m;

void read()
{
    for (in >> n >> m; m--;)
    {
        int x, y;
        in >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    const int size = n + 3;
    d.resize(size), low.resize(size);
    d.assign(size, -1);
}

void bicomp(int x, int y)
{
    vector<int>component;
    int tx, ty;
    do
    {
        tx = s.top().first;
        ty = s.top().second;
        s.pop();
        component.push_back(tx);//adding nodes component
        component.push_back(ty);
    } while (tx != x || ty != y);

    ans.push_back(component);
}

void dfs(int node, int id)
{
    d[node] = low[node] = id;
    for (auto it = g[node].begin(); it != g[node].end(); it++)
    {
        if (d[*it] == -1)
        {
            s.push({ node,*it });
            dfs(*it, id + 1);
            low[node] = min(low[node], low[*it]);

            if (low[*it] >= d[node])//articulation point
                bicomp(node, *it);
        }
        else
            low[node] = min(low[node], d[*it]);
    }
}

void print()
{
    out << ans.size() << '\n';
    for (auto it : ans)
    {
        //deleting duplicates
        sort(it.begin(), it.end());
        it.erase(unique(it.begin(), it.end()), it.end());

        copy(it.begin(), it.end(), ostream_iterator<int>(out, " "));
        out << '\n';
    }
}
int main()
{
    read();
    dfs(1, 1);
    print();
}
