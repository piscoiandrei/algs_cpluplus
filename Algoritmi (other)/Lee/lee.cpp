#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>                           /** LEE normal*/
using namespace std;

#define map_size 180
#define directii 4

int dj[directii] = { 0,0,1,-1 };
int di[directii] = { 1,-1,0,0 };           /** LEE normal*/

int n, m;
int map[map_size][map_size];
int startx, starty, stopx, stopy;

queue<pair<int, int>> coada;


void citire()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = -1;
	}
	cin >> startx >> starty;
	cin >> stopx >> stopy;
}

bool OK(int i, int j)
{
	if (map[i][j] == -1) // daca dai cu capu de pom
		return false;
	if (i < 1 || j<1 || i>n || j>n) // depasim granitele
        /**  Bordarea e mai eficienta */
		return false;
	return true;
}

void lee()
{
	int i, j, i_urmator, j_urmator;
	map[startx][starty] = 1;
	coada.push(make_pair(startx, starty));

	while (!coada.empty())
	{
		i = coada.front().first;
		j = coada.front().second;
		coada.pop();

		for (int directie = 0; directie < directii; directie++)
		{
			i_urmator = i + di[directie];
			j_urmator = j + dj[directie];
			if (OK(i_urmator, j_urmator) && map[i_urmator][j_urmator] == 0)
			{
				map[i_urmator][j_urmator] = map[i][j] + 1; // pasi necesari
				coada.push(make_pair(i_urmator, j_urmator));
			}
		}
	}
}

int main()
{
	citire();
	lee();
	cout << map[stopx][stopy];
}

/**-----------------------------------------------------------------------------------------------------------------*/
/**-----------------------------------LEE MULTIPLE STARTS, pb muzeu infoarena---------------------------------------*/
/**-----------------------------------------------------------------------------------------------------------------*/
#include <fstream>
#include <queue>
//#include <iostream>
using namespace std;
ifstream cin("muzeu.in");
ofstream cout("muzeu.out");

#define MAX 260

int map[MAX][MAX];

int n;
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };

queue<pair<int, int>> q;


void citire()
{
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> c;
			if (c == '.')
				map[i][j] = -1;
			else
			{
				if (c == '#')
					map[i][j] = -2;
				else
				{
					if (c == 'P')
					{
						map[i][j] = 0;
						q.push({i,j});
					}
				}
			}
		}
	}
}

void afisare()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bordare()
{
	for (int i = 0; i <= n + 1; i++)
	{
		map[0][i] = map[i][0] = map[i][n + 1] = map[n + 1][i] = -2;
	}
}

//bool OK(int iprev, int jprev, int i,int j)
//{
//	if (map[i][j] != -1)
//	{
//		if (map[i][j] == -2)
//			return false;
//		if (map[iprev][jprev] >= map[i][j])
//			return false;
//		return true;
//
//	}
//	return true;
//
//}

void lee()
{
	int i_urmator, j_urmator,i,j;

	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			i_urmator = i + di[k];
			j_urmator = j + dj[k];

			if (map[i_urmator][j_urmator] != -2)
			{
				if (map[i_urmator][j_urmator] == -1)
				{
					map[i_urmator][j_urmator] = map[i][j] + 1;
					q.push({ i_urmator,j_urmator });
				}
				else
				{
					if (map[i_urmator][j_urmator]-1 > map[i][j])
					{
						map[i_urmator][j_urmator] = map[i][j] + 1;
						q.push({ i_urmator,j_urmator });
					}
				}
			}
		}

	}
}

int main()
{
	citire();
	bordare();
	lee();
	afisare();
}


