#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
//arbori de intervale infoarena
ifstream in("source.in");
ofstream out("source.out");

#define dim 100005

int maximum,n,m;

int segmentTree[dim*4];
int values[dim];// initial values, in this problem is not going to be used

void Update(int node, int left, int right, int position, int val);
// left and right, are indices that represent the [left,right] interval from values[]
// position is reffers to a position from values[]

void Query(int node, int left, int right, int q_left, int q_right);
// [q_left, q_right] the interval we query from values[]

int main()
{
	in >> n >> m;

	for (int i = 1; i <= n; i++)
	{

		in >> values[i];
		Update(1, 1, n, i, values[i]);
		// update the whole tree starting from node 1, change the value on position i
	}


	for (int i = 0; i < m; i++)
	{
		int request_type, a, b;

		in >> request_type >> a >> b;

		if (request_type == 0)
		{
			maximum = -0xB00B1E5;
			Query(1, 1, n, a, b);
			out << maximum << '\n';
		}
		else
		{
			Update(1, 1, n, a, b);
		}

	}

}


void Update(int node, int left, int right, int position, int val)
{
	if (left == right) // we arrived at a leaf, leafs = values[]
	{
		segmentTree[node] = val; // update the value in the node
		return;
	}


	int middle = (left + right) / 2;

	if (position <= middle)
		Update(node * 2, left, middle, position, val);
	else
		Update(node * 2 + 1, middle + 1, right, position, val);

	// updating the nodes bottom up;
	segmentTree[node] = max(segmentTree[node * 2], segmentTree[node * 2 + 1]);
}

void Query(int node, int left, int right, int q_left, int q_right)
{
	if (q_left <= left && right <= q_right)//total overlap
	{
		if (segmentTree[node] > maximum)
			maximum = segmentTree[node];

		return;
	}

	// partial overlaps

	//         |----------|
 	//    |------|

	//         |----------|
	//               |---------|

	int middle = (left + right) / 2;

	if (q_left <= middle)//proceeding to left branch
		Query(node * 2, left, middle, q_left, q_right);

	if (middle < q_right) // proceeding to right branch
		Query(node * 2 + 1, middle + 1, right, q_left, q_right);

	//in case of no overlap we do nothing
}
