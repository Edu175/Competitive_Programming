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
bint MOD=212345678987654321LL,P[5]={1444441,1777771,1234567,1242421,1010003};
ll Hash(vector<ll>a, ll d){
	sort(ALL(a));
	bint res=1;
	bint p=1;
	fore(i,0,SZ(a)){
		res=(res+p*a[i])%MOD;
		p=p*P[d%5]%MOD;
	}
	return res;
}
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll vis[MAXN];
ll dfs(ll x, ll d){
	vis[x]=1;
	vector<ll>v;//,dbg;
	for(auto y:g[x])if(!vis[y])v.pb(dfs(y,d+1));
	//cout<<x<<": "<<g[x]<<" "<<dbg<<" "<<v<<" "<<Hash(v)<<"\n";
	return Hash(v,d);
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
		ll t0=dfs(0,0);
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll t1=dfs(0,0);
		//cout<<t0<<" "<<t1<<"\n";
		if(t0==t1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
