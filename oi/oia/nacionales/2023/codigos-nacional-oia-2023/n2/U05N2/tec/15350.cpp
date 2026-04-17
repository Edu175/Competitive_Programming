#include <string>
#include <vector>
#include <set>

using namespace std;
vector<vector<int>>ady;
int n,m;
void tablero(int N, vector<int> &A, vector<int> &B) {
   n=N;
   m=A.size();
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
   if(control.size()==n)
   {
       return -1;
   }
   if(m==n-1)
   {
       for(int i=1;i<=n;i++)
       {
           if(!control.count(i))
           {
               return i;
           }
       }
   }
   else {

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
    }}
    return -1;
}
