#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i, a, b) for (ll i = a, jet = b; i < jet; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define mset(a, v) memset((a), (v), sizeof(a))
#define FIN                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0)
#define show(v)               \
	{                         \
		for (auto i : v)      \
			cout << i << " "; \
		cout << "\n";         \
	}
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;

#define ppc __builtin_popcountll
#define ctz __builtin_ctzll

unordered_map<ll, ll> dp;
vv g;
ll n;
ll ele(ll x) { return ~(g[x] | (1ll << x)); }
ll f(ll mk)
{
	if (!mk)
		return 0;
	if (dp.count(mk))
		return dp[mk];
	auto &res = dp[mk];
	ll x = ctz(mk);
	ll vec = g[x] & mk;
	ll deg = ppc(vec);
	if (deg <= 1)
	{
		return res = 1 + f(mk & ele(x));
	}
	if (deg == 2)
	{
		ll y1 = ctz(vec);
		ll y2 = ctz(vec ^ (1ll << y1));
		ll si = 1 + f(mk & ele(x));
		res=si;
		if(!(g[y1]>>y2&1)){
			res=min(res,2 + f(mk & ele(y1) & ele(y2)));
		}
		return res;
	}
	ll no = f(mk ^ (1ll << x));
	ll si = f(mk & ele(x));
	return res = min(no, si);
}

int main()
{
	FIN;
	ll q;
	cin >> q >> n;
	vector<vv> mat(n, vv(n));
	map<string, ll> mp;
	set<ll> tmp;
	auto get_id = [&](string s)
	{
		if (!mp.count(s))
		{
			ll sz = SZ(mp);
			mp[s] = sz;
		}
		return mp[s];
	};
	auto do_clique = [&]()
	{
		for (auto i : tmp)
			for (auto j : tmp)
				if (i != j)
					mat[i][j] = 1;
		tmp.clear();
	};
	fore(i, 0, q)
	{
		ll ty;
		cin >> ty;
		if (ty == 1)
			do_clique();
		else
		{
			string s;
			cin >> s;
			ll id = get_id(s);
			tmp.insert(id);
		}
	}
	do_clique();

	// mt19937 rng;
	// fore(x,0,n)fore(y,x+1,n)mat[x][y]=mat[y][x]=(rng()%20==0);
	// fore(x,0,n)fore(y,0,n)mat[x][y]=0;
	// fore(x,0,n-1)mat[x][x+1]=mat[x+1][x]=1;
	// mat[0][n-1]=mat[n-1][0]=1;
	g.resize(n);
	fore(x, 0, n) fore(y, 0, n) if (mat[x][y]) g[x] |= (1ll << y);
	// fore(x,0,n){
	//     cerr<<x<<": ";
	//     for(auto y:g[x])cerr<<y<<" ";;cerr<<"\n";
	// }
	ll res = f((1ll << n) - 1);
	cout << res << "\n";
	return 0;
}