#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];
ll we[MAXN];
ll n;
vv d;
void dfs(ll x){
	for(auto [y,i]:g[x])if(d[y]==-1){
		d[y]=d[x]+we[i];
		dfs(y);
	}
}
ll get(){
	d=vv(n,-1);
	d[0]=0; dfs(0);
	auto mx=max_element(ALL(d))-d.begin();
	// cout<<mx<<": "<<d[mx]<<"\n";
	d=vv(n,-1);
	d[mx]=0; dfs(mx);
	return *max_element(ALL(d));
}

int main(){
	JET
	cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		we[i]=w;
	}
	// cout<<get()<<"\n";
	ll q; cin>>q;
	while(q--){
		ll x,k; cin>>x>>k; x--;
		for(auto [y,i]:g[x])we[i]*=k;
		cout<<get()<<"\n";
		for(auto [y,i]:g[x])we[i]/=k;
	}
	return 0;
}