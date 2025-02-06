#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
// Auto explicativo
	
using namespace std;
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
 
using ll = long long;
using ull = unsigned long long;
using iii = tuple<int,int,int>;
 
const ll inf = 100000000000000000;
const int mod = 1e9+7;
const int maxn = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
void solve(){
	int n; cin >> n;
    vector<tuple<int, ll, ll, ll>> segs;
    vector<int> tt;
    ll xx = 0, yy = 0, qnt = 0;
    char lst = 'Z';
    map<char, char> opp;
    opp['R'] = 'L';
    opp['L'] = 'R';
    opp['D'] = 'U';
    opp['U'] = 'D';
    vector<ll> compr;
    for (int i = 0; i < n; ++i) {
        char d; cin >> d;
        int qq; cin >> qq;
        if (lst != d and i != 0) {
            if (lst == 'R') segs.pb({0, yy, xx, xx+qnt}), xx += qnt;
            if (lst == 'L') segs.pb({0, yy, xx-qnt, xx}), xx -= qnt;
            if (lst == 'U') segs.pb({1, xx, yy, yy+qnt}), yy += qnt;
            if (lst == 'D') segs.pb({1, xx, yy-qnt, yy}), yy -= qnt;
            tt.pb(lst);
            qnt = 0;
        }
        qnt += qq;
        lst = d;
    }
    if (lst == 'R') segs.pb({0, yy, xx, xx+qnt}), xx += qnt;
    if (lst == 'L') segs.pb({0, yy, xx-qnt, xx}), xx -= qnt;
    if (lst == 'U') segs.pb({1, xx, yy, yy+qnt}), yy += qnt;
    if (lst == 'D') segs.pb({1, xx, yy-qnt, yy}), yy -= qnt;
    for (auto [a, b, c, d] : segs) compr.pb(b), compr.pb(c), compr.pb(d);
    sort(all(compr));
    compr.erase(unique(all(compr)), end(compr));
    vector<tuple<int, int, int, int>> short_segs;
    auto fuck = [&] (ll x) {
        return int(lower_bound(all(compr), x) - begin(compr));
    };
    for (auto [a, b, c, d] : segs) {
        short_segs.pb({a, fuck(b), fuck(c), fuck(d)});
    }
    tt.pb(lst);
    vector<tuple<int, int, int, int>> hor, ver;
    for (int i = 0; i < sz(short_segs); ++i) {
        auto [a, b, c, d] = short_segs[i];
        if (a) ver.pb({b, c, d, i});
        else hor.pb({b, c, d, i});
    }
    sort(all(hor));
    sort(all(ver));
    auto can = [&] (int X) {
        vector<array<int, 4>> events;
        for (int __ = 0; __ < 2; ++__) {
            for (int kk = 0, jj = 0; kk != sz(hor); kk = jj) {
                while (jj != sz(hor) and get<0>(hor[kk]) == get<0>(hor[jj])) jj++;
                int L = mod;
                for (int k = kk; k < jj; ++k) {
                    if (get<3>(hor[k]) > X) continue;
                    if (L != mod and get<1>(hor[k]) <= L) return false;
                    L = get<2>(hor[k]);
                }
            }
            swap(hor, ver);
        }
        for (auto [x, y, z, id] : hor) if (id <= X) events.pb({x, 2, y, z});
        int z = 0;
        for (auto [x, l, r, id] : ver) {
            if (id > X) continue;
            events.pb({r+1, 1, x, z});
            events.pb({l, 0, x, z});
            z++;
        }
        sort(all(events));
        ord_set<pair<int, int>> s;
        ll ans = 0;
        for (auto [y, tipo, l, r] : events) {
            if (tipo == 0) s.insert({l, r});
            else if (tipo == 1) s.erase({l, r});
            else ans += s.order_of_key({r, n+10}) - s.order_of_key({l-1, n+10});
        }
        return ans == X;
    };
    int l = 0, r = sz(segs)-1, resp = -1;
    while (l <= r) {
        int md = l + (r-l+1)/2;
        if (can(md)) resp = md, l = md + 1;
        else r = md - 1;
    }
    ll ans = 0;
    for (int i = 0; i <= resp; ++i) {
        auto [t, L, lx, rx] = segs[i];
        ans += rx - lx;
    }
    if (resp != sz(segs)-1) {
        auto [type, line, aba, bab] = segs[resp+1];
        int ttt = type;
        type = tt[resp+1];
        vector<pair<ll, ll>> s;
        for (int i = 0; i <= resp; ++i) {
            auto [t, L, lx, rx] = segs[i];
            if (t == ttt) {
                if (line == L) s.push_back({lx, rx}); 
            } else {
                if (lx <= line and line <= rx) s.push_back({L, L});
            }
        }
        sort(all(s));
        vector<pair<ll, ll>> ss;
        for (auto [lx, rx] : s) {
            while (!ss.empty() and ss.back().second >= lx) ckmax(rx, ss.back().second), lx = ss.back().first, ss.pop_back();
            ss.pb({lx, rx});
        }
        if (type == 'R' or type == 'U') {
            for (ll i = aba+1; i <= bab; ++i) {
                if (opp[tt[resp]] == type) break;
                auto j = lower_bound(all(ss), make_pair(i+1, -inf)) - begin(ss) - 1;
                ans++;
                if (0 <= j and j < sz(ss) and ss[j].second >= i) break;
            }
        } else {
            for (ll i = bab-1; i >= aba; --i) {
                if (opp[tt[resp]] == type) break;
                auto j = lower_bound(all(ss), make_pair(i+1, -inf)) - begin(ss) - 1;
                ans++;
                if (0 <= j and j < sz(ss) and ss[j].second >= i) break;
            }
        }
    }
    cout << ans << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}