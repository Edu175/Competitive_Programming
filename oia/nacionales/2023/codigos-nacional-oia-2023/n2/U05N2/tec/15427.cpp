#include <string>
#include <vector>
#include <set>


using namespace std;
vector<vector<int>>ady;
int n,m;
vector<int>a,b;
void tablero(int N, vector<int> &A, vector<int> &B)
{
    n=N;
    m=A.size();
    a=A;
    b=B;

}

int con_quien_comercio(vector<int> &controlados)
{
    vector<vector<int>>ady(n);
    set<int>control;
    for(int i=0; i<controlados.size(); i++)
    {
        control.insert(controlados[i]);
    }
    for(int i=0; i<a.size(); i++)
    {
        if(control.count(a[i])==true && control.count(b[i])==false)
        {
            ady[a[i]].push_back(b[i]);
        }
        else if(control.count(a[i])==false && control.count(b[i])==true)
        {
            ady[b[i]].push_back(a[i]);
        }

    }
    for(int i=1; i<=n; i++)
    {
        if(control.count(i))
        {
            for(int veci:ady[i])
            {
                if(!control.count(veci))
                {
                    return veci;
                }
            }
        }
    }
    return -1;
}
