#include <iostream>
//#include <fstream>
using namespace std;
//ifstream cin("ferma3.in");
//ofstream cout("ferma3.out");
                                  /**  Pb ferma3 infoarena, partea1  */

#define MAX 405

int n, m;
char charMap[MAX][MAX];
int intMap[MAX][MAX];
int indexZona = 1;
int sMax = 1;
int arieZona[MAX*MAX];


const int di[] = {0,0,1,-1};
const int dj[] = {1,-1,0,0};


void citire()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> charMap[i][j];
		}
	}
}


void afisare()
{
	cout << '\n';
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << intMap[i][j] << ' ';
		}
		cout << '\n';
	}cout << '\n';
}
void algFill(int i, int j)
{
	arieZona[indexZona]++;
	intMap[i][j] = indexZona;

	for (int k = 0; k < 4; k++)
	{
		int newi = i + di[k];
		int newj = j + dj[k];

		if (charMap[i][j] == charMap[newi][newj] && intMap[newi][newj] == 0)
		{
			algFill(newi, newj);
		}
	}

}


int main()
{
	int v; cin >> v;

	cin >> n >> m;

	citire();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (intMap[i][j] == 0)
			{
				algFill(i,j);
				if (sMax < arieZona[indexZona])
					sMax = arieZona[indexZona];
				indexZona++;
			}
		}
	}
	//afisare();
	cout << sMax;
}



