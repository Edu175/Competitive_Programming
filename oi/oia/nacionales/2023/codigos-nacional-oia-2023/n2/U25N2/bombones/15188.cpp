#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
    bool sat = false;
    long long tot = 0;

    if (x.size() == 1) return x[0] / K;

    while(!sat)
    {
        sort(x.begin(), x.end(), greater<int>());
        //reverse(x.begin(), x.end());
        int curr = 0;

        for(int i = 0; i < x.size(); i++)
        {
            if(x[i] == 0 && i != x.size()-1) continue;

            if (x[i] != 0) {
                curr++;
                x[i] -= 1;
            }

            if(curr == K) {
                tot++;
                break;
            }

            if (i == x.size()-1) {
                sat = true;
                break;
            }
        }

        while(!x.empty() && x.back() == 0)
            x.pop_back();
    }

    return tot;
}
