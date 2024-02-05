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
const bint MOD=212345678987654321LL;
bint P=1777771;
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
	//vector<ll>dbg,dbh;
	for(auto y:g[x])if(y!=f){
		dfs1(y,x);
		//dbg.pb(y);dbh.pb(up(h[y]));
		h[x]=merge(h[x],up(h[y]));
	}
	//cout<<x<<": "<<dbg<<" "<<dbh<<" "<<h[x]<<"\n";
}
void dfs2(ll x, ll f=-1){
	tot[x]=merge(tot[x],h[x]);
	for(auto y:g[x])if(y!=f){
		ch[y]=up(merge(ch[x],sub(h[x],up(h[y]))));
		//cout<<"ch["<<y<<"]= "<<ch[x]<<"+"<<h[x]<<"-"<<up(h[y])<<" = "<<ch[y]<<"\n";
		tot[y]=ch[y];
		dfs2(y,x);
	}
	//cout<<x<<": "<<h[x]<<"+"<<ch[x]<<" = "<<tot[x]<<"\n";
}
ll vis[MAXN];
ll dfs(ll x){
	vis[x]=1;
	vector<ll>v;//,dbg;
	for(auto y:g[x])if(!vis[y])v.pb(up(dfs(y)));//dbg.pb(y);}
	ll res=0;
	for(auto i:v)res=merge(res,i);
	//cout<<x<<": "<<dbg<<" "<<v<<" "<<res<<"\n";
	return res;
}
void reroot(ll rt=0){
	//cout<<"dfs1\n";
	dfs1(rt);
	ch[rt]=0;
	tot[rt]=0;
	//cout<<"dfs2\n";
	dfs2(rt);
}
vector<ii>ed1,ed2;
vector<ll> get(){
	ll n=SZ(ed1)+1;
	//ll mk=(1ll<<16)-1;
	//P=((rand()&mk)<<32)|((rand()&mk)<<16);
	fore(i,0,n){
		g[i].clear();
		vis[i]=0;
	}
	for(auto [u,v]:ed1){
		g[u].pb(v);
		g[v].pb(u);
	}
	ll t1=dfs(0);
	fore(i,0,n){
		g[i].clear();
		vis[i]=0;
	}
	for(auto [u,v]:ed2){
		g[u].pb(v);
		g[v].pb(u);
	}
	reroot();
	vector<ll>ret;
	fore(i,0,n)if(tot[i]==t1)ret.pb(i);
	return ret;
}
const ll R=1;
int main(){FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		ll n; cin>>n;
		ed1.clear(),ed2.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			ed1.pb({u,v});
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			ed2.pb({u,v});
		}
		set<ll>st;
		fore(i,0,n)st.insert(i);
		fore(_,0,R){
			set<ll>sti;
			for(auto i:get())if(st.count(i))sti.insert(i);
			st=sti;
		}
		//imp(st);
		//cout<<t0<<" "<<t1<<"\n";
		if(SZ(st))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
