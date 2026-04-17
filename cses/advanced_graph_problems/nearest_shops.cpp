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

const ll MAXN=1e5+5;

vv g[MAXN];
ll D[MAXN],wh[MAXN];

void bfs(vv s){
	mset(D,-1);
	queue<ll> q;
	for(auto x:s){
		D[x]=0,wh[x]=x;
		q.push(x);
	}
	while(SZ(q)){
		auto x=q.front(); q.pop();
		// cerr<<"bfs "<<x+1<<"\n";
		for(auto y:g[x])if(D[y]==-1){
			D[y]=D[x]+1;
			wh[y]=wh[x];
			q.push(y);
		}
	}
}
const ll INF=1e18;
int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vv s(k);
	vv is(n);
	fore(i,0,k)cin>>s[i],s[i]--,is[s[i]]=1;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs(s);
	vv mn(n,INF);
	fore(x,0,n)if(D[x]!=-1){
		for(auto y:g[x])if(wh[y]!=wh[x]){
			mn[wh[x]]=min(mn[wh[x]],D[x]+1+D[y]);
		}
	}
	// fore(x,0,n)cout<<D[x]<<" ";;cout<<"\n";
	fore(x,0,n){
		ll res=D[x];
		if(is[x])res=mn[x];
		if(res>=INF)res=-1;
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}