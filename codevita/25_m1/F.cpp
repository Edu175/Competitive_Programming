#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

#define ppc __builtin_popcountll

int main(){FIN;
	ll m; cin>>m;
	map<ii,ll> mp;
	vector<vv> g;
	auto get_idx=[&](ii x){
		if(mp.count(x))return mp[x];
		mp[x]=SZ(g);
		g.pb({});
		return mp[x];
	};
	fore(i,0,m){
		ii a,b;
		cin>>a.fst>>a.snd;
		cin>>b.fst>>b.snd;
		ll u=get_idx(a);
		ll v=get_idx(b);
		g[u].pb(v);
		g[v].pb(u);
	}
	ii asd;
	cin>>asd.fst>>asd.snd;
	ll s=get_idx(asd);
	ll n=SZ(g);
	
	fore(x,0,n){
		cout<<x<<": ";
		imp(g[x])
	}
	cout<<endl;
	
	ll N=1ll<<n;
	vv cyc(N);
	vector<vv> dp(N,vv(n));
	dp[1ll<<s][s]=1;
	fore(mk,0,N)fore(x,0,n)if(mk>>x&1){
		auto &cur=dp[mk][x];
		for(auto y:g[x]){
			if(y==s)cyc[mk]++;
			if(!(mk>>y&1))dp[mk^(1ll<<y)][y]+=cur;
		}
	}
	ll res=0;
	fore(mk,0,N){
		ll cur=cyc[mk];
		if(!cur)continue;
		assert(ppc(mk)>=3);
		assert(cur%2==0);
		res+=cur/2;
	}
	cout<<res<<"\n";
	return 0;
}
