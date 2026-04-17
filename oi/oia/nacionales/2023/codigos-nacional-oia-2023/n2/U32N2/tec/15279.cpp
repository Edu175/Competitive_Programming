#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>grafo;

void tablero(int N, vector<int> &A, vector<int> &B)
{
    grafo.resize(N+1);
    for(int i=0; i<grafo.size(); i++)
    {
        grafo[A[i]].push_back(B[i]);
        grafo[B[i]].push_back(A[i]);
    }

}
int con_quien_comercio(vector<int> &controlados)
{
    for(int i=1; i<=controlados.size(); i++)
    {
        bool band=false;
        for(int j=0; j<controlados.size(); j++)
        {
            if(i==controlados[j])
            {
                band = true;
            }
        }
        if(band == false)
        {
            return i;
        }
    }
    return -1;
}
