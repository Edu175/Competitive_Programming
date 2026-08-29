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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

vv operator+(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(a))c[i]+=a[i];
	fore(i,0,SZ(b))c[i]+=b[i];
	return c;
}

vv operator*(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]+=a[i]*b[j];
	return c;
}
const ll MAXN=2005;

vv g[MAXN];
ll res=0;
ll k;
vv vx={0,1};
pair<vv,vv> dfs(ll x, ll fa){
	vv a1={1},a2={0};
	for(auto y:g[x])if(y!=fa){
		// cout<<"in loop "<<x<<","<<y<<": "<<a1<<" "<<a2<<"\n";
		auto [b1,b2]=dfs(y,x);
		b1=b1*vx;
		b2=b2*vx;
		fore(w,0,2){
			auto &me=(!w?b1:b2);
			auto &otr=(!w?a2:a1);
			fore(i,0,SZ(me)){
				ll t=k-i;
				if(t>=0&&t<SZ(otr)){
					ll cur=otr[t]*me[i];
					res+=cur;
					// cerr<<"en "<<w<<" "<<x<<","<<y<<": "<<otr[t]<<"*"<<me[i]<<": +="<<cur<<"\n";
				}
			}
		}
		a2=a2+b2+a1*b1;
		a1=a1+b1;
	}
	// cout<<"dfs "<<x<<": "<<a1<<" "<<a2<<"\n";
	return {a1,a2};
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k; k--;
		fore(i,0,n){
			g[i].clear();
		}
		res=0;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1);
		cout<<res<<"\n";
	}
	return 0;
}
