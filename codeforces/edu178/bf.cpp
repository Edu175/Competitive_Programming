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

int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vv Vis(n);
	auto reach=[&](ll x, ll t, auto &&reach){
		if(Vis[x]){
			Vis=vv(n);
			return 0;
		}
		Vis[x]=1;
		if(x==t){
			Vis=vv(n);
			return 1;
		}
		return reach(a[x],t,reach);
	};
	auto get=[&](){
		// imp(a)
		vv vis(n),cyc(n);
		ll z=0;
		fore(x,0,n){
			cyc[x]=reach(a[x],x,reach);
			z+=cyc[x];
		}
		ll k=0;
		fore(x,0,n)if(!vis[x]){
			// cout<<x<<": "; imp	(vis)
			bool hay=0;
			for(ll y=x;!vis[y];y=a[y])vis[y]=1,hay|=cyc[y];
			k+=hay;
		}
		// cout<<z<<" "<<k<<" z k\n";
		return n-z+k;
	};
	fore(i,0,q){
		ll x,y,k; cin>>x>>y>>k; x--,y--;
		a[x]=y;
		ll e=get();
		ll res=1;
		// cout<<e<<" e\n";
		fore(i,0,e)res=res*k%3;
		cout<<res<<"\n";
	}
	return 0;
}