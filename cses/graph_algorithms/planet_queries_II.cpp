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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5,K=18;

ll F[K][MAXN];

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--,F[0][i]=a[i];
	// cerr<<"done input\n";
	fore(k,1,K)fore(x,0,n)F[k][x]=F[k-1][F[k-1][x]];
	// cerr<<"pinga\n";
	vector<ll> vis(n),d(n,-1),pos(n,-1),sz(n),idx(n,-1),rt(n);
	ll cnt=0;
	fore(x,0,n)if(!vis[x]){
		vector<ll>p,c;
		for(ll y=x;!vis[y];y=a[y])vis[y]=1,p.pb(y);
		ll did=0;
		for(auto i:p){
			did|=i==a[p.back()];
			if(did)c.pb(i);
		}
		fore(i,0,SZ(c))pos[c[i]]=i,sz[c[i]]=SZ(c),idx[c[i]]=cnt;
		cnt++;
	}
	// cerr<<"found cycles\n";
	auto dfs=[&](ll x, auto &&dfs){
		if(d[x]!=-1)return;
		if(pos[x]!=-1){d[x]=0;rt[x]=x;return;}
		dfs(a[x],dfs);
		rt[x]=rt[a[x]];
		d[x]=d[a[x]]+1;
	};
	fore(i,0,n)dfs(i,dfs);
	// cerr<<"dfs\n";
	auto go=[&](ll x, ll v){
		for(ll k=K-1;k>=0;k--)if(v>=(1<<k))x=F[k][x],v-=1ll<<k;
		return x;
	};
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		if(d[y]){
			ll v=d[x]-d[y];
			if(v>=0&&go(x,v)==y)cout<<v<<"\n";
			else cout<<"-1\n";
		}
		else {
			ll res=d[x];
			x=rt[x];
			ll z=sz[x];
			ll v=(pos[y]-pos[x]+z)%z;
			if(idx[x]==idx[y])cout<<res+v<<"\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}
