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
const ll MAXN=2e5+5;

ll to2(ll a){return a*(a-1)/2;}

struct node{
	map<ll,ll> mp;
	ll par=0;
	ll cant=0;
	ll res=0;
	node(ll d){par=0;cant=1;res=0;mp[d]++;}
	void merge(node b){
		for(auto [k,v]:b.mp){
			par+=mp[k]*v;
			mp[k]+=v;
		}
		par+=b.par;
		cant+=b.cant;
		res+=b.res;
	}
};
vv g[MAXN];
ll D[MAXN];
node dfs(ll x, ll d){
	D[x]=d;
	node ans(d);
	for(auto y:g[x]){
		node cur=dfs(y,d+1);
		if(SZ(ans.mp)<SZ(cur.mp))swap(ans,cur);
		ans.merge(cur);
	}
	ll now=to2(ans.cant)+ans.par;
	if(d)ans.res+=now;
	// cerr<<"sub "<<x<<": "<<now<<"\n";
	return ans;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
		}
		vv to(n); iota(ALL(to),1); to[n-1]=-1;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			to[u]=max(to[u],v);
		}
		fore(i,0,n-1)g[to[i]].pb(i);
		
		ll rt=n-1;
		auto got=dfs(rt,0);
		ll sub=got.res;
		
		// cerr<<"sub "<<sub<<"\n";
		vv all;
		fore(i,0,n)all.pb(D[i]);
		sort(ALL(all));
		
		ll res=0;
		fore(i,0,n){
			ll cant=all.end()-lower_bound(ALL(all),D[i]);
			cant--; // yo
			ll cur=D[i]*cant;
			// cerr<<i<<": "<<cur<<"\n";
			res+=cur;
		}
		// cerr<<"res "<<res<<"\n";
		res-=sub;
		
		cout<<res<<"\n";
	}
	return 0;
}
