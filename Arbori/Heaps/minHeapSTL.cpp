#include <fstream>
#include <iostream>
#include <set>
#include <vector>
                    ///  STL MIN-HEAP IMPLEMENTATION USING set<>
using namespace std;
ifstream in("source.in");
ofstream out("source.out");

const int NMAX = 200005;

set<int> heap;

int main()
{
	int n, caz;
	in >> n;

	for (int i = 0; i < n; i++)
	{
		in >> caz;
		if (caz == 1)
		{
			int x; in >> x;
			heap.insert(x);
			order.push_back(x);
		}
		else if (caz == 2)
		{
			int nth; in >> nth;
			heap.erase(order[nth]);
		}
		else
			out << *heap.begin() << '\n';
	}

}
