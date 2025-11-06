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
random_device rd;
mt19937 rng(rd());

const ll MAXN=1e5+5,LIMIT=20000;

vv g[MAXN];
ll vis[MAXN];
ll cmp[MAXN];
vv nod;
void dfs(ll x){
	nod.pb(x);
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}


const ll REP=200;
ll d[REP][MAXN];
ll id=0;
void bfs(ll s){
	d[id][s]=0;
	queue<ll> q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[id][y]==-1){
			d[id][y]=d[id][x]+1;
			q.push(y);
		}
	}
}
ll cnt=0;
void doit(vv nod){
	for(auto i:nod)cmp[i]=cnt;
	cnt++;
	id=0;
	fore(_,0,REP){
		for(auto i:nod)d[id][i]=-1;
		auto s=nod[rng()%SZ(nod)];
		bfs(s);
		id++;
	}
}

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(x,0,n)if(!vis[x]){
		nod.clear();
		dfs(x);
		doit(nod);
	}
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		ll good=0;
		fore(id,0,REP)good|=d[id][x]+d[id][y]<=LIMIT;
		good&=cmp[x]==cmp[y];
		if(good)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
