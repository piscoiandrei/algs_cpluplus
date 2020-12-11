#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in("source.in");
ofstream out("source.out");

const int NMAX = 1000005;

int heap[NMAX], heapSize, index;

void UpHeap(int k)
{
	int parent = k / 2;
	if (parent && heap[parent] < heap[k])
	{
		swap(heap[parent], heap[k]);
		UpHeap(parent);
	}
}

void DownHeap(int k)
{
	int child = k * 2;

	if (child + 1 <= index && heap[child + 1] > heap[child])
		child += 1;

	if (child <= index && heap[k] < heap[child])
	{
		swap(heap[k], heap[child]);
		DownHeap(child);
	}
}

void Insert(int x)
{
	heap[++index] = x;
	UpHeap(index);
}

void Erase()
{
	swap(heap[1], heap[index]);

	index -= 1;

	DownHeap(1);
}

int main()
{
	in >> heapSize;
	for (int i = 1; i <= heapSize; i++)
	{
		int x;
		in >> x;
		Insert(x);
	}

	for (int i = 1; i < heapSize; i++)
		Erase();

	for (int i = 1; i <= heapSize; i++)
		out << heap[i] << ' ';
}
