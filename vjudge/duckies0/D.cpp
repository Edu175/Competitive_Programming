#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ll> g[MAXN];
ll p[MAXN],c[MAXN],d[MAXN],h[MAXN],dn[MAXN];

void dfs(ll x){
	for(auto y:g[x])if(y!=p[x]){
		p[y]=x;
		d[y]=d[x]+1;
		h[x]++;
		dfs(y);
		c[x]+=c[y]+1;
	}
}

int main(){FIN;
	mset(h,0); mset(dn,0);
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	p[0]=-1; d[0]=0;
	dfs(0);
	priority_queue<ii>pq;
	fore(i,0,n)if(dn[i]==h[i])pq.push({d[i]-c[i],i});
	ll res=0;
	fore(i,0,k){
		auto mx=pq.top(); pq.pop();
		res+=mx.fst;
		ll x=p[mx.snd];
		dn[x]++;
		if(dn[x]==h[x])pq.push({d[x]-c[x],x});
	}
	cout<<res<<"\n";
	return 0;
}
