#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
#define fore(i,s,n) forsn(i,s,n)

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define DBG(x) cout<<#x<<" = "<<(x)<<endl

template<class x> ostream& operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<"]";
    return out;
}

typedef pair<int, int> pi;
typedef pair<pi, pi> pii;

typedef long long ll;
const ll mod = 1e9+7;

map<pi, vector<int>> ch;

vector<ll> facts = {1};
ll fact(int n) {
    while(SZ(facts) <= n) facts.pb(facts.back() * SZ(facts) % mod);
    return facts[n];
}

ll ex(ll f, ll e) {
    ll res = 1;
    while(e) {
        if (e & 1) res = (res * f) % mod;
        f = (f * f) % mod;
        e >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return ex(x, mod - 2);
}

ll choose(int n, int k) {
    return fact(n) * inv(fact(k) * fact(n - k) % mod) % mod;
}

pair<ll, int> calc(int a, int b) {
    int curr = 0;
    ll total = 1;
    for(int n : ch[{a, b}]) {
        auto aa = calc(a, n);
        auto bb = calc(n, b);
        int k = aa.second + bb.second + 1;
        total *= aa.first * bb.first % mod * choose(curr + k, k) % mod;
        total %= mod;
        curr += k;
    }
    return {total, curr};
}

int serieparalelo(vector<int> &t, vector<int> &e) {
    vector<pair<int, int>> es = {{1, 2}};
    int n = 3;
    int k = SZ(t);
    assert(SZ(e) == k);
    forn(i, k) {
        int a = es[e[i]-1].first;
        int b = es[e[i]-1].second;
        ch[{a, b}].pb(n);
        if (t[i] == 2) {
            es.pb({a, n});
            es.pb({n, b});
            n += 1;
        } else {
            es.pb({a, n});
            es[e[i]-1].first = n;
            n += 1;
        }   
    }
    return calc(1, 2).first;
}
