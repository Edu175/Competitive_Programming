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
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll h[MAXN],ch[MAXN],tot[MAXN];
ll cut(ll a){return a<MOD?a:a-MOD;}
ll merge(ll a, ll b){
	return cut(a+b);
}
ll sub(ll a, ll b){
	return cut(a-b+MOD);
}
ll up(ll a){return fpow(P,a);}
void dfs1(ll x, ll f=-1){
	h[x]=0;
	for(auto y:g[x])if(y!=f){
		dfs1(y,x);
		h[x]=merge(h[x],up(h[y]));
	}
}
void dfs2(ll x, ll f=-1){
	tot[x]=merge(tot[x],h[x]);
	for(auto y:g[x])if(y!=f){
		ch[y]=up(merge(ch[x],sub(h[x],up(h[y]))));
		tot[y]=ch[y];
		dfs2(y,x);
	}
}
ll vis[MAXN];
ll dfs(ll x){
	vis[x]=1;
	vector<ll>v,dbg;
	for(auto y:g[x])if(!vis[y])v.pb(up(dfs(y)));//dbg.pb(v);}
	ll res=0;
	for(auto i:v)res=merge(res,i);
	//cout<<x<<": "<<g[x]<<" "<<dbg<<" "<<v<<" "<<res<<"\n";
	return res;
}
void reroot(ll rt=0){
	dfs1(rt);
	ch[0]=0;
	tot[0]=0;
	dfs2(rt);
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
		reroot();
		set<ll>st;
		fore(i,0,n)st.insert(tot[i]);
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
		if(st.count(t1))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
