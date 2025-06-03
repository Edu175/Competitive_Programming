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
ll lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge || back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(ll n){
	fore(i,0,n)idx[i]=0,cmp[i]=-1;
	qidx=0; qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}
typedef vector<ll> vv;
vv myg[MAXN];
ll col[MAXN];
ll gc=0;
void dfs(ll x, ll c){
	col[x]=c;
	for(auto y:myg[x]){
		ll ci=c+1;
		if(col[y]==-1)dfs(y,ci);
		else gc=gcd(gc,abs(ci-col[y]));
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			myg[i].clear();
			col[i]=-1;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
		}
		scc(n);
		fore(x,0,n)if(cmp[x]==cmp[0])for(auto y:g[x])if(cmp[y]==cmp[0])myg[x].pb(y);
		gc=0;
		dfs(0,0);
		while(gc&&gc%2==0)gc/=2;
		while(gc&&gc%5==0)gc/=5;
		if(gc!=1)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
