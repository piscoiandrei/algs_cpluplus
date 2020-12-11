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

ifstream in("source.in");
ofstream out("source.out");

set<int> tree;
set<int> :: iterator it,upperLimit;
int main()
{
	int query;
	in >> query;

	while (query--)
	{
		int q_type, x, y;
		in >> q_type >> x;

		switch (q_type)
		{
		case 1:
			tree.insert(x);
			break;
		case 2:
			tree.erase(tree.find(x));
			break;
		case 3:
			out << (tree.find(x) != tree.end() ? 1 : 0) << '\n';
			break;
		case 4:
			it = tree.lower_bound(x);
			if (it != tree.end() && *it == x) out << x << '\n';
			else out << *(--it) << '\n';
			break;
		case 5:
			it = tree.upper_bound(x);
			if (it == tree.begin())
				out << *it << '\n';
			else
			{
				--it;
				if (*it == x) out << x << '\n';
				else ++it, out << *it << '\n';
			}
			break;
		default:
			in >> y;
			it = tree.lower_bound(x);
			upperLimit = tree.lower_bound(y);
			if (upperLimit != tree.end() and *upperLimit == y) ++upperLimit;
			for(;it != upperLimit; it++)
				out << *it << ' ';
			out << '\n';
			break;
		}
	}
}


