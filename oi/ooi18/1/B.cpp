#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,rus=b;i<rus;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdkjg:v)cout<<sdkjg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ii> g[MAXN];
ii ed[MAXN];
ll w[MAXN],vis[MAXN];
vector<ll>c[MAXN];
void fail(){
	cout<<"No\n";
	exit(0);
}
vector<ll>g2[MAXN];

ll dfs(ll x, ll idx){
	vis[x]=1;
	set<ii>st;
	ll m=SZ(g[x]);
	fore(i,0,m)st.insert({c[x][i],i});
	vector<ll>h(m);
	for(auto [y,i]:g[x])if(!vis[y]){
		ll k=dfs(y,i);
		auto lwb=st.lower_bound(ii({w[i]-k,-1}));
		if(lwb==st.end())fail();
		h[lwb->snd]=i;
		st.erase(lwb);
	}
	if(SZ(st))h[st.begin()->snd]=idx;
	fore(i,0,m-1)g2[h[i]].pb(h[i+1]);
	if(SZ(st))return st.begin()->fst;
	return -1;
}
vector<ll>ord;
void dfs2(ll x){
	vis[x]=1;
	for(auto y:g2[x])if(!vis[y])dfs2(y);
	ord.pb(x);
}

int main(){FIN;
	ll n,grupo; cin>>n>>grupo;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v>>w[i]; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed[i]={u,v};
	}
	fore(i,0,n){
		fore(j,0,SZ(g[i])){
			ll ci; cin>>ci;
			c[i].pb(ci);
		}
	}
	dfs(0,-1);
	mset(vis,0);
	fore(i,0,n-1)if(!vis[i])dfs2(i);
	//reverse(ALL(ord));
	cout<<"Yes\n";
	for(auto i:ord)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
