#include <fstream>
#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;
ifstream in("main.in");
ofstream out("main.out");

bool mat[MAX][MAX];
bool b[MAX][MAX];
int n, t;

const int di[]={-1, 0, 1, 0},
          dj[]={ 0, 1, 0,-1};


void bordare()
{
    for(int i=0; i <= n+1; i++)
    {
        mat[i][0] = mat[i][n+1] = 1;
        mat[0][i] = mat[n+1][i] = 1;
    }
}

void alg_fill(int i, int j)
{
    mat[i][j] = 1;
    b[i][j] = 1;
    // matricea b reprezinta matricea
    // pe unde am trecut cu fillu
    // a fost necesar pt ca putea sa
    // iti dea sa verifici si o camera
    // ocupata (cu 1) si daca foloseai
    // doar 'mat' nu iti dadea bine

    for(int k = 0; k < 4; k++)
    {
        int vi = i + di[k];
        int vj = j + dj[k];

        if(mat[vi][vj]==0)
            alg_fill(vi,vj);
    }

}

void exec_fill()
{
    for(int i = 1; i <= n; i++)
    {
        if(mat[1][i]==0)
            alg_fill(1, i);
        if(mat[i][1]==0)
            alg_fill(i, 1);
        if(mat[i][n]==0)
            alg_fill(i, n);
        if(mat[n][i]==0)
            alg_fill(n, i);
    }
}

int main()
{
    int x, y;

    in>>n>>t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            in>>mat[i][j];

    bordare();
    exec_fill();

    for(int i = 0; i < t; i++)
    {
        in>>x>>y;
        if(b[x][y])
            out<<"da\n";
        else
            out<<"nu\n";
    }
}

