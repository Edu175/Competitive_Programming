#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>grafo;

void tablero(int N, vector<int> &A, vector<int> &B)
{
    grafo.resize(N+1);
    for(int i=0; i<A.size(); i++)
    {
        grafo[A[i]].push_back(B[i]);
        grafo[B[i]].push_back(A[i]);
    }

}
int con_quien_comercio(vector<int> &controlados)
{
    map<int,bool>Ma;
    for(int i=0; i<controlados.size(); i++)
    {
        Ma[controlados[i]]=true;
    }
    for(int i=0; i<controlados.size(); i++)
    {
        if(Ma[controlados[i]+1]==false&&controlados[i]+1<grafo.size())
        {
            return controlados[i]+1;
        }
    }
    return -1;
}
