#include <string>
#include <vector>

using namespace std;

int corto(vector<int> &t, vector<int> &e) {
    int n = t.size();
    int r = 1;
    if(t[0] == 2)
    {
        return r;
    }
    for(int i = 0; i<n; i++)
    {
        if(t[i] == 1)
        {
            r++;
        }
    }
    return r;
}
