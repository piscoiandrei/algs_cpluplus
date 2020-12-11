#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

ifstream in("aib.in");
ofstream out("aib.out");

int fenwickTree[100005];
int n, m;

int LSB(int i)
{
	return i & -i;
}

void readTree()
{
	in >> n >> m;
	for (int i = 1; i <= n; i++)
		in >> fenwickTree[i];
}

void constructTree()// O(n)
{
	for (int i = 1; i <= n; i++)
	{
		int j = i + LSB(i);
		if (j <= n)
			fenwickTree[j] += fenwickTree[i];
	}
}

int prefixSum(int i) // sum of [1,i], parcurgem de la frunze in sus pe arbore // O(log(n))
{
	int sum = 0;

	for(;i; i &= ~(LSB(i)))  // Equivalently, i -= LSB(i);
	{
		sum += fenwickTree[i];
	}

	return sum;
}

int rangeQuery(int a, int b)
{
	return prefixSum(b) - prefixSum(a-1);
}

void add(int pos,int val) // update all the cells that pos impacts, bottom up
{
	for(;pos <= n; pos += LSB(pos))
		fenwickTree[pos] += val;
}

int posMin(int a)//Sa se determine pozitia minima k astfel incat suma valorilor primilor k termeni sa fie exact a.
{
    //O(n*log(n)) se poate O(log^2(n)) cu cautare binara
	for (int i = 1; i <= n; i++)
		if (prefixSum(i) == a)
			return i;
	return -1;
}

int main()
{
	readTree();
	constructTree();

	int request, a, b;
	for (int i = 1; i <= m; i++)
	{
		in >> request;
		switch (request)
		{
		case 0: in >> a >> b;
			add(a, b);
			break;
		case 1: in >> a >> b;
			out << rangeQuery(a, b) << '\n';
			break;
		case 2: in >> a;
			out << posMin(a)<<'\n';
			break;
		default:
			break;
		}
	}
}
