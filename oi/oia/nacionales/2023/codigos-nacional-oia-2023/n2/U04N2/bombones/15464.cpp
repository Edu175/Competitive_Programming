#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool sorter(int a, int b) {
    return a > b;
}

ll bombones(int K, vector<int> bombones) {
    sort(bombones.begin(), bombones.end(), sorter);

    ll total = 0;
    while (bombones.size() >= K) {
        ll mini = bombones[0];
        for (int i = 0; i < K; i++) {
            if (bombones[i] < mini) {
                mini = bombones[i];
            }
        }

        int currentInd = 0;
        for (int i = 0; i < K; i++) {
            bombones[currentInd] -= mini;

            if (bombones[currentInd] <= 0) {
                bombones.erase(bombones.begin() + currentInd);
            } else {
                currentInd++;
            }
        }

        total += mini;
    }

    return total;
}
