#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    bool sat = false;
    long long tot = 0;
    while(!sat)
    {
        int curr = 0;
        for(int i = 0; i < x.size(); i++)
        {
            if (i == x.size()-1 && curr < K-1) {
                sat = true;
                break;
            }
            if (x[i] == 0) continue;
            curr++;

            if(curr == K) {
                tot++;
                break;
            }

            x[i] -= 1;
        }
    }

    return tot;
}
