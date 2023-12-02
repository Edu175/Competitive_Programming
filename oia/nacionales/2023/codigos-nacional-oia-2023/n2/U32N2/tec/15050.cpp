#include <iostream>
#include <vector>

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
    vector <int> comercia;
    for(int i=0; i<controlados.size(); i++)
    {
        for(int j:grafo[controlados[i]])
        {
            comercia.push_back(j);
        }

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
