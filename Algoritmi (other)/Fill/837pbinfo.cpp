#include <fstream>
#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;
ifstream in("main.in");
ofstream out("main.out");


int n, m;
bool mat[MAX][MAX];
// in cazul de fata nu nevoie de bordare
// pt ca nu circulam pe 0, ca sa echivalam
// bordarea incepem cu indicii pe poz (1,1) samd


const int di[] = {-1, 1, 0 ,0};
const int dj[] = {0, 0, 1, -1};

void citire()
{
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            in>>mat[i][j];
}


// aici folosim fill ca sa stergem
// zonele deja numarate
// ASTA E UN FILL SIMPLIFICAT lowkey
void alg_fill(int i, int j)
{
    mat[i][j] = 0;

    for(int k = 0; k < 4; k++)
    {
        int vecin_i = i+di[k];
        int vecin_j = j+dj[k];

        if(mat[vecin_i][vecin_j])
            alg_fill(vecin_i,vecin_j);

    }
}

int main()
{
    int nr_zone = 0;

    citire();

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(mat[i][j])
            {
                nr_zone++;
                alg_fill(i,j);
            }

    out<<nr_zone;
}
