#include<bits/stdc++.h>
using namespace std;

const int MAXN =  64 + 3;
const int MAXM = 1e6 + 3;
const int INF  = 1e9;
vector <int> A[MAXN];
int F1[MAXN], F2[MAXN], G1[MAXN], G2[MAXN], P[MAXM];
const int MOD = 998244353;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    int TT = 1;
    while(TT --){
        int n, q;
        cin >> n >> q;
        for(int i = 1;i <= n;++ i){
            int x;
            cin >> x;
            P[i] = x;
            A[x].push_back(i);
        }

        // int cnt = 0;
        // for(int i = 1;i <= n;++ i)
        //     for(int j = i + 1;j <= n;++ j)
        //         for(int k = j + 1;k <= n;++ k)
        //             if((P[i] ^ P[j]) == P[k])
        //                 cnt ++;
        // cerr << "!!" << cnt << endl;

        for(int i = 1;i <= q;++ i){
            int l, r, ans = 0;
            cin >> l >> r;
            for(int j = 0;j <= 50;++ j){
                auto L = lower_bound(A[j].begin(), A[j].end(), l    ) - A[j].begin();
                auto R = lower_bound(A[j].begin(), A[j].end(), r + 1) - A[j].begin();
                // [L, R), length = R - L
                if(j == 0 && R > L){
                    ans = -1;
                    cout << r - l << " " << R - L << "\n";
                    break;
                }
                if(j != 0 && R - L >= 2){   // choose two
                    ans = (ans + 1ll * (R - L) * (R - L - 1) / 2) % MOD;
                }
            }
            if(ans == -1) continue;
            if(ans ==  0){
                for(int j = 0;j <= 64;++ j){
                    F1[j] = INF, F2[j] = 0;
                }
                for(int j = l;j <= r;++ j){
                    for(int k = 0;k < 64;++ k){
                        G1[k] = F1[k], G2[k] = F2[k];
                    }
                    if(1 <  G1[P[j]]){
                        G1[P[j]] = 1, G2[P[j]] = 1;
                    }
                    for(int k = 0;k < 64;++ k) if(F2[k]){
                        if(F1[k] + 1 <  G1[k ^ P[j]]){
                            G1[k ^ P[j]] = F1[k] + 1;
                            G2[k ^ P[j]] = F2[k];
                        } else 
                        if(F1[k] + 1 == G1[k ^ P[j]]){
                            G2[k ^ P[j]] = (G2[k ^ P[j]] + F2[k]) % MOD;
                        }
                    }
                    for(int j = 0;j <= 64;++ j){
                        F1[j] = G1[j], F2[j] = G2[j];
                    }
                }
                if(F1[0] == INF)
                    cout << -1 << "\n";
                else
                    cout << r - l + 1 - F1[0] << " " << F2[0] << "\n";
            }
            else 
                cout << r - l - 1 << " " << ans << "\n";
        }
        for(int i = 0;i <= 50;++ i){
            A[i].clear();
        }
    }
    return 0;
}
/*
12 1
1 2 3 4 5 6 7 11 12 13 14 15
1 12
*/