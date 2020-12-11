#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

ifstream in("hashuri.in");
ofstream out("hashuri.out");

const int MOD = 999983;//preferably a prime number
vector<int> HashTable[MOD+1]; // MOD+1 mandatory

int HASH(int x)
{
	return x % MOD;
	//simplest hash function ever
}

void insert(int x)
{
	int pos = HASH(x);
	for (auto const& it : HashTable[pos])
	{
		if (it == x)
			return;
	}
	HashTable[pos].push_back(x);
}

void del(int x)
{
	int pos = HASH(x);
	for (int i = 0; i < HashTable[pos].size(); i++)
	{
		if (HashTable[pos][i] == x)
			HashTable[pos].erase(HashTable[pos].begin() + i);
	}
}

void inTable(int x)
{
	int pos = HASH(x);
	for (auto const& it : HashTable[pos])
	{
		if (it == x)
		{
			out << 1 << '\n'; return;
		}
	}
	out << 0 << '\n';
}

int main()
{
	int n;
	for (in >> n; n--;)
	{
		int op, x;
		in >> op >> x;
		if (op == 1)
			insert(x);
		else
			if (op == 2)
				del(x);
			else
				inTable(x);
	}
}
/**
/// method using map

map<int, int> MAP;

int main()
{
	int n, key = 0;
	for (in >> n; n--;)
	{
		int t, x;
		in >> t >> x;
		if (t == 1 && (MAP.find(x) == MAP.end()))
			MAP[x] = ++key; // MAP[x] : value and key : MAP[x]'s key
		else
			if (t == 2)
				MAP.erase(x);
			else
				out << (MAP.find(x) != MAP.end()) << '\n';
	}
}
*/
