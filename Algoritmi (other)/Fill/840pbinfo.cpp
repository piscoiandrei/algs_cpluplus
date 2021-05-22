#include <fstream>
#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;
ifstream in("main.in");
ofstream out("main.out");

int n, m;
const char A = 'A',
           C = 'C',
           E = 'E';
char mat[MAX][MAX];

const int di[] = {-1, 1, 0, 0},
          dj[] = {0, 0 , -1, 1};

void alg_fill(int i, int j, char c)
{
    mat[i][j] = c;

    for(int k = 0; k < 4; k++)
    {
        int vi = i+di[k];
        int vj = j+dj[k];

        if(mat[vi][vj] == '1')
        {
            if(c == C)
                alg_fill(vi,vj,E);
            else
                if(c == E)
                    alg_fill(vi,vj,C);
        }
    }

}

int main()
{
    in>>n>>m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            in>>mat[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(mat[i][j]=='0')
                mat[i][j] = A;
            else if(mat[i][j]=='1')
                    alg_fill(i,j,C);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            out<<mat[i][j]<<' ';
        out<<'\n';
    }

}
