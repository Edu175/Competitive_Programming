#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool sorter(int a, int b) {
    return a > b;
}

ll bombones(int K, vector<int>& b) {
    vector<int> bombones = b;
    sort(bombones.begin(), bombones.end(), sorter);

    ll total = 0;
    while (bombones.size() >= K) {
        ll mini = bombones[0];
        for (int i = 0; i < K; i++) {
            if (bombones[i] < mini) {
                mini = bombones[i];
            }
        }

        for (int i = 0; i < K; i++) {
            bombones[i] -= mini;
        }

        ll currentInd = 0;
        for (int i = 0; i < K; i++) {
            if (bombones[currentInd] <= 0) {
                bombones.erase(bombones.begin() + currentInd);
            } else {
                currentInd++;
            }
        }

        total += mini;
    }

    bombones = b;
    sort(bombones.begin(), bombones.end());
    ll total2 = 0;
        while (bombones.size() >= K) {
        ll mini = bombones[0];
        for (int i = 0; i < K; i++) {
            if (bombones[i] < mini) {
                mini = bombones[i];
            }
        }

        for (int i = 0; i < K; i++) {
            bombones[i] -= mini;
        }

        ll currentInd = 0;
        for (int i = 0; i < K; i++) {
            if (bombones[currentInd] <= 0) {
                bombones.erase(bombones.begin() + currentInd);
            } else {
                currentInd++;
            }
        }

        total2 += mini;
    }

    return max(total2, total);
}

/*int main() {
    vector<int> x = {1, 2, 10, 3, 4};
    cout << bombones(3, x);
    return 0;
}*/
