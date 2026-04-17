#include <bits/stdc++.h>
using namespace std;

/*
 * Build a factory with N rows and M columns that produces the target rate.
 *
 * P: the target numerator of the fraction P / (2^A * 3^B)
 * A: the exponent of 2 in the denominator
 * B: the exponent of 3 in the denominator
 */
vector<string> solve(int P, int A, int B) {
    // YOUR CODE HERE
    return {"."};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        vector<string> factory = solve(P, A, B);
        int N = (int) factory.size();
        int M = (int) factory[0].size();
        cout << N << ' ' << M << '\n';
        for (const string& row : factory) {
            cout << row << '\n';
        }
    }
    return 0;
}
