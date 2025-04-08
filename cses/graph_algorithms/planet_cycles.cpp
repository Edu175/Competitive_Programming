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
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vv vis(n),d(n,-1);
	fore(x,0,n)if(!vis[x]){
		vv p;
		ll y=x;
		for(;!vis[y];y=a[y])p.pb(y),vis[y]=1;
		// cout<<x<<": "<<y<<" | ";imp(p)
		ll es=0;
		vv cyc;
		while(SZ(p)){
			ll u=p.back(); p.pop_back();
			cyc.pb(u);
			es|=u==y;
			if(es)break;
		}
		// cout<<es<<": ";imp(cyc)
		// cout<<"\n";
		if(es){for(auto i:cyc)d[i]=SZ(cyc);}
	}
	// imp(d)
	// cout<<endl;
	vis=vv(n);
	auto dfs=[&](ll x, auto &&dfs)->void{
		if(d[x]!=-1)return;
		dfs(a[x],dfs);
		d[x]=d[a[x]]+1;
	};
	fore(i,0,n)if(d[i]==-1)dfs(i,dfs);
	imp(d)
	return 0;
}