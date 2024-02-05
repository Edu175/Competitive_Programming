#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

#define bint __int128
bint MOD=212345678987654321LL,P=1777771;
ll fpow(bint b, ll e){
	bint res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e/=2;
	}
	return res;
}
ll Hash(vector<ll>a){
	bint res=0;
	fore(i,0,SZ(a)){
		res=(res+fpow(P,a[i]))%MOD;
	}
	res=res*P%MOD;
	return res;
}
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll vis[MAXN];
ll dfs(ll x){
	vis[x]=1;
	vector<ll>v,dbg;
	for(auto y:g[x])if(!vis[y])v.pb(dfs(y));//dbg.pb(v);}
	//cout<<x<<": "<<g[x]<<" "<<dbg<<" "<<v<<" "<<Hash(v,d)<<"\n";
	return Hash(v);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll t0=dfs(0);
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll t1=dfs(0);
		//cout<<t0<<" "<<t1<<"\n";
		if(t0==t1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
