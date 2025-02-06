#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// I have to direct edges (small -> big)
// and maximize # of paths
// from there we can prove that if x is not centroid, all its edges are 'rooted' towards the centroid (either all up or all down)
// knapsack dp from the centroid
// multiple centroids dont matter

const ll MAXN=1e6+5;

vv g[MAXN];
ll c[MAXN],fa[MAXN];
void dfs0(ll x, ll _fa){
	c[x]=1; fa[x]=_fa;
	for(auto y:g[x])if(y!=_fa){
		dfs0(y,x);
		c[x]+=c[y];
	}
}
ll D[MAXN];
void dfs1(ll x, ll fa){
	for(auto y:g[x])if(y!=fa){
		D[y]=D[x]+1;
		dfs1(y,x);
	}
}

ll knapsack(vv b, ll s){ // nsqrtn not possible :((((((  // bitset :)))
	vv oc(2*s+5);
	for(auto i:b)oc[i]++;
	fore(v,0,s)if(oc[v]){
		ll &c=oc[v];
		if(c&1){
			oc[2*v]+=c/2;
			c=1;
		}
		else {
			oc[2*v]+=c/2-1;
			c=2;
		}
	}
	bitset<MAXN>dp; dp[0]=1;
	fore(i,0,SZ(oc))fore(_,0,oc[i])dp|=dp<<i;
	ll res=0;
	fore(i,0,MAXN)if(dp[i])res=max(res,i*(s-i));
	return res;
}

int main(){
	FIN;
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
		g[i].pb(p);
	}
	dfs0(0,-1);
	ll rt=-1;
	vv a;
	fore(x,0,n){
		ll flag=1;
		vv v;
		for(auto y:g[x]){
			ll sz=y==fa[x]?n-c[x]:c[y];
			v.pb(sz);
			flag&=2*sz<=n;
		}
		if(flag)rt=x,a=v;
	}
	dfs1(rt,-1);
	ll fij=0;
	fore(x,0,n)fij+=D[x]+1;
	auto res=knapsack(a,n-1);
	res+=fij;
	cout<<res<<"\n";
	return 0;
}