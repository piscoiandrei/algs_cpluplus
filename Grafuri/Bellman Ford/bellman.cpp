#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;

ifstream in("bellmanford.in");
ofstream out("bellmanford.out");

#define NMAX 50005
const char msg[] = "Ciclu negativ!";

struct ST{
	int extFinala; // extremitate finala a arcului (x,y)
	int costMuchie;
};

vector<ST> adjList[NMAX];
int n, m;
double dist[NMAX];

void read()
{
	in >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		in >> x >> y >> c;

		adjList[x].push_back({ y,c });
		//        nod       0            1
		// adjList[1] = vecin_nod     vecin_nod    ...
		//              cost_muchie   cost_muchie  ...
		//
		// adjList[2] = vecin_nod     vecin_nod    ...
		//              cost_muchie   cost_muchie  ...
	}

	for (int i = 0; i <= n+1; i++)
		dist[i] = INFINITY; // init dist as INF so every distance we find is < INF
}

void bellman()
{
	dist[1] = 0; // starting from node 1

	// relaxing each edge N-1 times
	for (int k = 0; k < n - 1; k++) // parcurgem graful de n-1 ori, graf liste de adiacenta
		for (int nod = 1; nod <= n; nod++)
		{
			for (int j = 0; j < adjList[nod].size(); j++)
			{
				ST vecin = adjList[nod][j];
				// check if we can update dist with a shorter path
				if (dist[nod] + vecin.costMuchie < dist[vecin.extFinala])
					dist[vecin.extFinala] = dist[nod] + vecin.costMuchie;
			}
		}

	for (int k = 0; k < n - 1; k++) // exec alg inca o data
		for (int nod = 1; nod <= n; nod++)// daca gasim o val care se updateaza inseamna ca
		{                                 // am dat peste un negative cycle
			for (int j = 0; j < adjList[nod].size(); j++)
			{
				ST vecin = adjList[nod][j];

				if (dist[nod] + vecin.costMuchie < dist[vecin.extFinala])
				{
					dist[vecin.extFinala] = -INFINITY;//if we need to mark negative cycles

					// in this case we need just to print a msg if we have a negative cycle
					out << msg;
					return;
				}
			}
		}



	for (int i = 2; i <= n; i++) // printing the distances to all the nodes > 1
		out << dist[i] << ' ';
}

int main()
{
	read();
	bellman();
}
