#include <string>
#include <vector>

using namespace std;
vector<int> a;
vector<int> b;
void tablero(int N, vector<int> &A, vector<int> &B) {
    for(int i=0; i<A.size(); i++)
        a.push_back(A[i]);
    for(int i=0; i<A.size(); i++)
        b.push_back(B[i]);
}

int con_quien_comercio(vector<int> &controlados) {
    int r=-1;
    bool ban, ban2;
    for(int i=0; i<controlados.size(); i++)
    {
        for(int j=0; j<a.size(); j++)
        {
            ban=false; ban2=false;
            int c=0;
            for(int k=0; k<controlados.size();k++){
            if(a[j]==controlados[i]&&b[j]!=controlados[k])
            {
                c++;
            }
            if(c==controlados.size())
            {
                return b[j];
                ban=true;

                }
            }
            if(ban==false)
            {
            for(int k=0; k<controlados.size();k++){
            if(b[j]==controlados[i]&&a[j]!=controlados[k])
            {
                c++;
            }
            if(c==controlados.size())
            {
                return a[j];
                ban2=true;
                }
            }
            if(ban==false &&ban2==false)
                return r;
            }
        }
    }
}
