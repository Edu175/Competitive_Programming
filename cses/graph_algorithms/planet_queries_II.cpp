#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5,K=18;

ll F[K][MAXN];

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--,F[0][i]=a[i];
	fore(k,1,K)fore(x,0,n)F[k][x]=F[k-1][F[k-1][x]];
	vector<ll> vis(n),d(n),pos(n,-1);
	fore(x,0,n)if(!vis[x]){
		vector<ll>p,c;
		for(ll y=x;!vis[y];y=a[y])vis[y]=1,p.pb(y);
		ll did=0;
		for(auto i:p){
			did|=i==a[p.back()];
			if(did)c.pb(i);
		}
		fore(i,0,SZ(c))pos[i]=i;
	}
	auto dfs=[&](ll x, auto &&dfs){
		if(pos[a[x]]==-1)dfs(a[x],dfs);
		d[x]=d[a[x]]+1;
	};
	auto go=[&](ll &x, ll &v){
		for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k))x=F[k][x],v-=1ll<<k;
	};
	
	
	// old
	while(q--){
		ll x,v; cin>>x>>v; x--;
		go(x,v);
		v%=tam[x];
		go(x,v);
		assert(!v);
		cout<<x+1<<"\n";
	}
	return 0;
}
