#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>grafo;

vector<bool>visitados;

void DFS(int nodo)
{
    visitados[nodo]=true;
    for(int i=0; i<grafo[nodo].size(); i++)
    {
        if(!visitados[grafo[nodo][i]])
        {
            DFS(grafo[nodo][i]);
        }
    }
}

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
    vector <int> comercia;
    for(int i=0; i<controlados.size(); i++)
    {
        visitados.resize(grafo.size(), false);
        DFS(controlados[i]);
        for(int i=1; i<visitados.size(); i++)
        {
            if(visitados[i]==true&&i!=controlados[i])
            {
                comercia.push_back(i);
            }
        }
        visitados.resize(0);
    }
    for(int i=0; i<comercia.size(); i++)
    {
        bool controlado=false;
        for(int j=0; j<controlados.size(); j++)
        {
            if(comercia[i]==controlados[j])
            {
                controlado = true;
            }
        }
        if(controlado==false)
        {
            return comercia[i];
        }
    }
    return -1;
}
