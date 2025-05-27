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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vector<vector<ii>> g;

void add_edge(ll u, ll v, ll w=0){
	ll m=max(u,v);
	if(m>=SZ(g))g.resize(m+1);
	g[u].pb({v,w});
}
vv dp;

ll f(ll x){
	auto &res=dp[x];
	if(res!=-1)return res;
	res=0;
	for(auto [y,w]:g[x])res=max(res,w+f(y));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		g.clear();
		ll cnt=2*n;
		auto in=[&](ll u){assert(u<n);return 2*u;};
		auto out=[&](ll u){assert(u<n);return 2*u+1;};
		vector<vv> vs(n);
		fore(i,0,m){
			ll u,v; string s; cin>>u>>s>>v; u--,v--;
			if(s=="->")add_edge(out(u),in(v),1);
			else {
				vs[u].pb(cnt);
				vs[v].pb(cnt^1);
				cnt+=2;
			}
		}
		fore(u,0,n)add_edge(in(u),out(u));
		fore(u,0,n){
			auto &v=vs[u];
			ll m=SZ(v);
			vv pre(m+1),suf(m+1);
			for(auto &i:pre)i=cnt++;
			for(auto &i:suf)i=cnt++;
			add_edge(pre[0],out(u));
			add_edge(suf[m],out(u));
			fore(i,1,m+1){
				add_edge(pre[i],pre[i-1]);
				add_edge(pre[i],v[i-1]^1);
			}
			for(ll i=m-1;i>=0;i--){
				add_edge(suf[i],suf[i+1]);
				add_edge(suf[i],v[i]^1);
			}
			fore(i,0,m){
				add_edge(v[i],pre[i],1);
				add_edge(v[i],suf[i+1],1);
			}
			//para los que vienen de arista dirigida posta:
			fore(i,0,m)add_edge(in(u),v[i]^1);
		}
		
		dp=vv(cnt,-1);
		ll res=0;
		fore(i,0,cnt)res=max(res,f(i));
		// fore(i,0,cnt){
		// 	cout<<i<<": "; impr(g[i])
		// }
		cout<<res<<"\n";
	}
	return 0;
}
