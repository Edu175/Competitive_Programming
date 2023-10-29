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

vector<ll>g[MAXN];
ll p[MAXN],n;
void bfstra(){
	priority_queue<ii>pq;
	fore(i,0,n)pq.push({p[i],i});
	while(SZ(pq)){
		auto f=pq.top(); pq.pop();
		ll x=f.snd,pi=f.fst;
		if(p[x]>pi||pi==0)continue;
		for(auto y:g[x]){
			if(pi-1>p[y])p[y]=pi-1,pq.push({p[y],y});
		}
	}
}

int main(){FIN;
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,k){
		ll x,v; cin>>x>>v; x--,v++;
		p[x]=v;
	}
	bfstra();
	vector<ll>res;
	fore(i,0,n)if(p[i])res.pb(i);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
