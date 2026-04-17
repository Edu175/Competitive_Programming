#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())

vector<int> inout(vector<int> &t, vector<int> &e)
{
    const int N = SIZE(t);
    vector<pair<int,int>> edgeList;
    vector<int> ret(N+2, 0);
    edgeList.push_back({0,0}); // No hay flecha 0
    edgeList.push_back({1,2});
    ret[0] = 1;
    ret[1] = -1;
    forn(i,N)
    {
        int A = edgeList[e[i]].first;
        int B = edgeList[e[i]].second;
        int newNode = 3+i;
        if (t[i] == 1)
        {
            // Series
            edgeList.push_back({A,newNode});
            edgeList[e[i]] = {newNode,B};
        }
        else if (t[i] == 2)
        {
            // Parallel
            ret[A-1]++;
            ret[B-1]--;
            edgeList.push_back({A,newNode});
            edgeList.push_back({newNode, B});
        }
    }
    return ret;
}
