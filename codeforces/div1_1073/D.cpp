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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=2e5+5;

vv g[MAXN];
ll vis[MAXN],has[MAXN];
ll z[MAXN];
ll n;
vv nod;

void dfs(ll x){
	nod.pb(x);
	z[x]=vis[x]=1;
	has[x]=x==n-2;
	for(auto y:g[x])if(!vis[y]){
		dfs(y);
		z[x]+=z[y];
		has[x]|=has[y];
	}
}
ll inv(ll a){return fpow(a,MOD-2);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		set<ll> vec(ALL(g[n-1]));
		dfs(n-1);
		for(auto i:nod)if(i!=n-1&&!vec.count(i))z[i]=0;
		nod.clear();
		vv zs;
		ll k=1;
		fore(i,0,n)if(!vis[i]){
			dfs(i);
			zs.pb(z[i]);
			for(auto j:nod)z[j]=z[i],has[j]=has[i];
			k++;
			nod.clear();
		}
		ll prod=1;
		for(auto z:zs)prod=mul(prod,z);
		vv ans(n-1,-1);
		if(has[n-1]){
			ll w=-1;
			for(auto y:g[n-1])if(has[y])w=y;
			fill(ALL(ans),0);
			ans[w]=mul(mul(prod,z[n-1]),fpow(n,k-2));
			if(k==1)ans[w]=1;
			imp(ans)
			continue;
		}
		assert(k>1);
		for(auto y:g[n-1]){
			ans[y]=mul(prod,mul(z[y],fpow(n,k-2)));
		}
		fore(x,0,n-1)if(ans[x]==-1){
			// k==2 or z==0
			auto &cur=ans[x];
			if(z[x]==0){cur=0;continue;}
			if(k==2)cur=1;
			else {
				assert(k>=3);
				cur=mul(prod,fpow(n,k-3));
				if(has[x]){
					cur=mul(cur,inv(z[x]));
					cur=mul(cur,z[x]+z[n-1]);
				}
			}
		}
		// fore(i,0,n)cout<<z[i]<<" ";;cout<<" z\n";
		imp(ans)
	}
	return 0;
}
