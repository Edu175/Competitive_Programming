#include <string>
#include <vector>
#include <set>

using namespace std;
vector<vector<int>>ady;
int n;
void tablero(int N, vector<int> &A, vector<int> &B) {
   n=N;
   ady.resize(N+1);
   for(int i=0;i<A.size();i++)
   {
      ady[A[i]].push_back(B[i]);
      ady[B[i]].push_back(A[i]);
   }
}

int con_quien_comercio(vector<int> &controlados) {
   set<int>control;
   for(int i=0;i<controlados.size();i++)
   {
     control.insert(controlados[i]);
   }
    for(int i=0;i<=n;i++)
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
