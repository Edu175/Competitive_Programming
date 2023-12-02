#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

bool sorter(int a, int b) {
    return a > b;
}

ll bombones(int K, vector<int>& bombones) {
    sort(bombones.begin(), bombones.end(), sorter);
    ll counter = 0;
    while (true) {
        ll c = 0;
        for (int i = 0; i < bombones.size(); i++){
            if (bombones[i] > 0) {
                c++;
                bombones[i]--;
            }
            if (c == K) {
                break;
            }
        }

        if (c != K) {
            break;
        }

        counter++;
    }

    return counter;
}
