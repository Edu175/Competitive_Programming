#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 51;
int was[N];
int cur[N];
int a[N];
int lul[N];
int dp[N];
double temp = 1;
double t0 = 1e9;

int main()
{
/*#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    freopen("subrev.in", "r", stdin);
    freopen("subrev.out", "w", stdout);
#endif*/
    srand(2);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        lul[i] = rand() % 2;
        cin >> a[i];
    }
    temp = t0;
    int ans = 0;
    int cur = 0;
    while (clock() / (double) CLOCKS_PER_SEC <= 1.99)
    {
        vector <int> p;
        for (int i = 0; i < n; i++)
        {
            was[i] = lul[i];
        }
        for (int it = 0; it < n * temp / t0; it++)
        {
            lul[rand() % n] ^= 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (lul[i])
            {
                p.push_back(i);
            }
        }
        int t = p.size();
        for (int i = 0; i < t / 2; i++)
        {
            swap(a[p[i]], a[p[t - 1 - i]]);
        }
        int kek = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[j] <= a[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            kek = max(kek, dp[i]);
        }
        ans = max(ans, kek);
        for (int i = 0; i < t / 2; i++)
        {
            swap(a[p[i]], a[p[t - 1 - i]]);
        }
        if (kek > cur)
        {
            cur = kek;
        }
        else
        {
            double t = exp((kek - cur) / temp);
            int x = 1 + rand();
            int y = 1 + rand();
            x %= y;
            if (x / (double) y <= t)
            {
                cur = kek;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    lul[i] = was[i];
                }
            }
        }
        temp *= 0.9999;
    }
    cout << ans << '\n';
}
