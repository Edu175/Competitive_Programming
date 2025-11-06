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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vector<vv> g(n);
		vv r(n);
		fore(i,0,n)cin>>r[i];
		vv ind(n);
		vector<ii> dp(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			ind[v]++;
		}
		ii mx={0,0};
		fore(x,0,n){
			auto &now=dp[x];
			if(now.snd>r[x])now.fst++;
			now.snd=r[x];
			for(auto y:g[x])dp[y]=max(dp[y],now);
			mx=max(mx,now);
		}
		vector<ii> ss;
		fore(i,0,n)if(!ind[i])ss.pb({r[i],i});
		sort(ALL(ss));
		ll res=1e18;
		for(auto [asd,s]:ss){
			ll cur=mx.fst*k+mx.snd-asd;
			res=min(res,cur);
			set<ll> st={s};
			while(SZ(st)){
				auto x=*st.begin(); st.erase(st.begin());
				auto &now=dp[x];
				now.fst++;
				mx=max(mx,now);
				for(auto y:g[x])if(!(now<=dp[y]))st.insert(y);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
