#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

bool isPossible(int num, vector<int> bombones, int K) {
    for (int i = 0; i < num; i++) {
        int c = 0;
        for (int k = 0; k < bombones.size(); k++) {
            if (bombones[k] > 0) {
                bombones[k]--;
                c++;
            }
            if (c == K) {
                break;
            }
        }

        if (c != K) {
            return false;
        }
    }

    return true;
}

bool sorter(int a, int b) {
    return a > b;
}

ll bombones(int K, vector<int>& bombones) {
    sort(bombones.begin(), bombones.end(), sorter);

    // hacer bin search
    ll start = 0;
    ll sum = 0;
    for (int x : bombones) {
        sum += x;
    }
    ll end = floor(sum / K);

    while (end - start > 1) {
        ll mid = (end + start) / 2;
        if (isPossible(mid, bombones, K)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        //cout << start << " " << end << " " << mid << endl;
    }

    if (isPossible(end, bombones, K)) {
        return end;
    } else {
        return end - 1;
    }
}
