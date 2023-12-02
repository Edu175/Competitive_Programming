#include <bits/stdc++.h>

using namespace std;

#define pb(v) push_back(v)

using ll = long long;

const ll MAXN = 20000;
const ll MOD = 1000000007;

ll dist[MAXN];
pair <ll, ll> flecha[MAXN];
vector <ll> grafo[MAXN];
ll visitado[MAXN];

ll sums[MAXN];

ll fact[MAXN];

void initfactorial() {

    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i < MAXN; i++) {

        fact[i] = (fact[i - 1] * i) % MOD;

    }

}

void dfs (ll i, ll contador) {

    visitado[i] = true;

    for (ll v : grafo[i]) {

        if (not visitado[v]) {

            dist[v] = contador + 1;
            dfs(v, contador + 1);

        } else {

            if (contador + 1 > dist[v]) {

                dist[v] = contador + 1;
                dfs(v, contador + 1);

            }

        }

    }

}

int serieparalelo(vector<int> &t, vector<int> &e) {

    initfactorial();

    ll abc = t.size();

    dist[0] = 0;
    dist[1] = 0;
    dist[2] = 1;
    flecha[1] = {1, 2};

    ll n = 2;
    ll flechas = 1;

    for (int i = 0; i < abc; i++) {

        if (t[i] == 1) {

            ll v = e[i];

            ll a = flecha[v].first;
            ll b = flecha[v].second;
            ll c = n + 1;

            flecha[v] = {c, b};
            flecha[flechas + 1] = {a, c};

            flechas++;
            n++;

        } else {

            ll v = e[i];

            ll a = flecha[v].first;
            ll b = flecha[v].second;
            ll c = n + 1;

            flecha[flechas + 1] = {a, c};
            flecha[flechas + 2] = {c, b};

            flechas += 2;
            n++;

        }

    }

    for (int i = 1; i <= flechas; i++) {

        ll a = flecha[i].first;
        ll b = flecha[i].second;

        grafo[a].pb(b);

    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {

        ll v = dist[i];

        sums[v] = sums[v] + 1;

    }

    ll result = 1;

    for (int i = 1; i < 10; i++) {

        ll v = fact[sums[i]];

        result *= v;

    }

    return result;

}
