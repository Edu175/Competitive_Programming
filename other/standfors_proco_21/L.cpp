#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

ll cnt;
ll vis[MAXN];
vv g[MAXN],gt[MAXN];
ll pos[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
	pos[x]=--cnt;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		gt[v].pb(u);
	}
	cnt=n;
	fore(i,0,n)if(!vis[i])dfs(i);
	set<ll> st;
	fore(i,0,n)st.insert(i);
	vv ord(n);
	fore(i,0,n)ord[pos[i]]=i;
	auto clear_range=[&](ll l, ll r){
		for(auto it=st.lower_bound(l);it!=st.end()&&*it<r;it=st.erase(it));
	};
	fore(x,0,n){
		ll mn=n+5,mx=-5;
		for(auto y:g[x])mn=min(mn,pos[y]);
		for(auto y:gt[x])mx=max(mx,pos[y]);
		assert(mn>pos[x]);
		assert(mx<pos[x]);
		clear_range(mx+1,pos[x]);
		clear_range(pos[x]+1,mn);
	}
	cout<<SZ(st)<<"\n";
	return 0;
}
