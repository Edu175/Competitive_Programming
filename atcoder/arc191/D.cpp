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
const ll MAXN=2e5+5,INF=1e18;

vv g[MAXN];

ll ban[MAXN];
ll n;
vv bfs(ll s, ii ar={-1,-1}){
	assert(!ban[s]);
	vv d(n,-1);
	queue<ll> q;
	q.push(s); d[s]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(!ban[y]&&d[y]==-1){
			if(ar==ii({x,y})||ar==ii({y,x}))continue;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

int main(){FIN;
	ll m,s,t; cin>>n>>m>>s>>t; s--,t--;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	// if(m==n-1){
	// 	ll fg=1;
	// 	fore(i,0,n)fg&=SZ(g[i])<=2;
	// 	if(fg){ // line
	// 		cout<<"-1\n";
	// 		return 0;
	// 	}
	// }
	// ahora siempre se puede
	auto ds=bfs(s);
	auto dt=bfs(t);
	ll dis=ds[t];
	
	vector<vv> h(n);
	fore(x,0,n)h[ds[x]].pb(dt[x]);
	ll mn=2; // extra
	fore(d,0,n){
		auto vec=h[d];
		sort(ALL(vec));
		if(SZ(vec)>1){
			ll cur=d+vec[1];
			mn=min(mn,cur-dis);
		}
	}
	if(mn<2){
		// cerr<<"first\n";
		cout<<2*dis+mn<<"\n";
		return 0;
	}
	fore(x,0,n)if(x!=s&&x!=t){
		if(ds[x]+dt[x]==dis&&SZ(g[x])>=3){
			// cerr<<"second\n";
			cout<<2*dis+2<<"\n";
			return 0;
		}
	}
	ll res=INF; // total
	fore(x,0,n)if(SZ(g[x])>=3){
		ll k=min(ds[x],dt[x]);
		ll cur=2*dis+4*(k+1);
		res=min(res,cur);
	}
	fore(x,0,n)if(x!=s&&x!=t&&ds[x]+dt[x]==dis)ban[x]=1;
	auto d2=bfs(s,{s,t});
	if(d2[t]!=-1)res=min(res,dis+d2[t]);
	
	if(res>=INF)res=-1;
	// cerr<<"final\n";
	cout<<res<<"\n";
	
	return 0;
}
