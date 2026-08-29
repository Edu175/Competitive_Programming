#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,cuca=b;i<cuca;i++)
#define SZ(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<vector<ii>> g;
ll n;
vv d;
vv nod;
void dfs(ll x, ll fa){
	nod.pb(x);
	for(auto [y,w]:g[x])if(y!=fa){
		d[y]=d[x]+w;
		dfs(y,x);
	}
}

ll get_ans(vector<array<ll,3>> ed){
	g.clear(); g.resize(n);
	for(auto [u,v,w]:ed){
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	ll res=0;
	d=vv(n,-1);
	fore(x,0,n)if(d[x]==-1){

		d[x]=0;
		dfs(x,-1);
		ll mx=-1;
		for(auto i:nod)if(mx==-1||d[i]>d[mx])mx=i;
		nod.clear();
		
		d[mx]=0;
		dfs(mx,-1);
		mx=-1;
		for(auto i:nod)if(mx==-1||d[i]>d[mx])mx=i;
		nod.clear();
		
		res=max(res,d[mx]);
	}
	// cerr<<"diam ";
	// for(auto [u,v,w]:ed)cout<<u<<","<<v<<"("<<w<<") ";
	// cout<<": "<<res<<"\n";
	return res;
}

int main(){
	FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<array<ll,3>> ed;
		fore(i,0,n-1){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({u,v,w});
		}
		vv ans(n,1e18);
		fore(mk,0,1ll<<(n-1)){
			vector<array<ll,3>> ed2;
			fore(i,0,n-1)if(mk>>i&1)ed2.pb(ed[i]);
			ll cur=get_ans(ed2);
			ll k=n-1-SZ(ed2);
			ans[k]=min(ans[k],cur);
		}
		fore(i,1,n)cout<<ans[i]<<" ";;cout<<"\n";
	}
}