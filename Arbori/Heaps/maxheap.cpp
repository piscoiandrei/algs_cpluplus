#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in("source.in");
ofstream out("source.out"); /// IMPLEMENTARE NORMALA

const int NMAX = 200005;

int heap[NMAX], heapSize, index;

void UpHeap(int k)
{
    int parent = k / 2;
    if (parent && heap[k] > heap[parent])
    {
        swap(heap[k], heap[parent]);
        UpHeap(parent);
    }
}

void DownHeap(int k)
{
    int child = k * 2;

     /// selectam fiul cu valoarea cea mai mare
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
    --index;
    DownHeap(1);
}
int main()
{
    int n; in >> n;

    for (int i = 0; i < n; i++)
    {
        int c;
        in >> c;
        if (c == 1)
        {
            int x;
            in >> x;
            Insert(x);
        }
        else
        {
            out << heap[1] << '\n';
            Erase();
        }
    }
}
