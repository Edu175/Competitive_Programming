// #region fold template
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,modulo-sched,modulo-sched-allow-regmoves,gcse-sm,gcse-las,ipa-pta,tree-loop-im,tree-loop-ivcanon,ivopts,tree-vectorize")
#include "bits/allocator.h"
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2")
#include "bits/stdc++.h"
#else
#include "bits/stdc++.h"
#endif
#ifdef SANITIZE
#define FIN cin.exceptions(cin.failbit), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#else
#define FIN ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/rope"
// using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef __float128 lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pb push_back
#define fst first
#define snd second
#define fori(i, a, b) for (ll i = a; i < (ll)(b); i++)
#define rof(i, a, b) for (ll i = a - 1; i >= b; i--)
#define fore(xs, x) for (auto& x : xs)
#define forp(xs, a, b) for (auto& [a, b] : xs)
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x.size())
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main() {
    FIN;
    ll n;
    cin >> n;
    vector<ll> a(n);
    fore(a, x) cin >> x;
    const ll INF=9;
	ll mi = INF;
    fori(i, 1, 1 << n) {
        ll d = 0;
        fori(j, 0, n) if (i >> j & 1) d = gcd(d, a[j]);
        if (d == 1) {
            mi = min(mi, (ll)__builtin_popcount(i));
        }
    }
    if (mi < INF)cout<<mi<<"\n";
    else cout<<-1<<"\n";
    return 0;
}