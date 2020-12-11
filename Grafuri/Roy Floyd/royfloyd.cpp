#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;

ifstream in("royfloyd.in");
ofstream out("royfloyd.out");

#define NMAX 105


float mat[NMAX][NMAX], n; // MATRIX must be FLOAT bcs
                          // INFINITY(cmath) is float val
                          // if mat is int, in some cases the result is going to be incorrect

void citire()
{
    in >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            in >> mat[i][j];
            if (!mat[i][j]) mat[i][j] = INFINITY;
        }
    for (int i = 1; i <= n; i++)
        mat[i][i] = 0;
}

void roy()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if ((mat[i][k] + mat[k][j] < mat[i][j]))
                    mat[i][j] = mat[i][k] + mat[k][j];
}

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (mat[i][j] != INFINITY) // mat must be float
                out << mat[i][j] << ' ';
            else
                out << 0 << ' ';

        out << '\n';
    }
}
int main()
{
    citire();
    roy();
    afisare();
}
