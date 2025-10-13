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
const ll MAXN=250005;
const ll B=500;

vv g[MAXN];
ll cnt[MAXN],is[MAXN],toc[MAXN],sum[MAXN];
ll sure=0,cur=0;
ll fat[MAXN];

ll a[MAXN];

vv dfs(ll x, ll fa){
	cnt[x]=toc[x]=sum[x]=0;
	vv nod;
	for(auto y:g[x])if(y!=fa){
		for(auto i:dfs(y,x))nod.pb(i);
		cnt[x]+=cnt[y];
		toc[x]+=toc[y];
	}
	if(!is[x]&&a[x] && !toc[x]&&!cnt[x])sure++;
	else if(!cnt[x] && (is[x]||a[x])){ // node of interest
		cur+=!sum[x]&&a[x]; // dsp es sum==1
		for(auto i:nod)fat[i]=x;
		nod={x};
	}
	cnt[x]+=!is[x]&&a[x];
	toc[x]+=is[x];
	sum[x]+=a[x];
	return nod;
}

void doit(ll n, vv &bag){
	fore(i,0,n)is[i]=0,fat[i]=-1;
	for(auto i:bag)is[i]=1;
	dfs(0,-1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll q; cin>>q;
		vv bag;
		
	}
	return 0;
}
