#include <string>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector<int> Ks;
int maxIndex;

bool inv(int i, int j) { return i > j; }

long long bombones(int K, vector<int> &x) {
    int N = x.size();
    ll boxes = 0;
    sort(x.begin(), x.end(), inv);
    
    for (int i = 0; i < K; ++i)
        Ks.push_back(i);
    
    maxIndex = K - 1;

    bool all0 = false;

    while (!all0)
    {
        boxes++;
        for (int i = 0; i < Ks.size(); ++i)
        {
            x[Ks[i]]--;
            if (x[Ks[i]] == 0)
                Ks[i] = ++maxIndex;
            if (maxIndex == N)
            {
                all0 = true;
                break;
            }
        }
    }

    return boxes;
}
