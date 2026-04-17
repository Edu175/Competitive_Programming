#include "railroad.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkfjhg:v)cout<<dkfjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=4e5+5,INF=1e15;
vector<ll> g[MAXN];
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

long long plan_roller_coaster(std::vector<int> A, std::vector<int> B) {
    vector<ll>a,b;
	for(auto i:A)a.pb(i);
	for(auto i:B)b.pb(i);
	if(SZ(a)<=16){
		ll n=SZ(a);
		vector<vector<ll>>dp(1ll<<n,vector<ll>(n));
		fore(mk,1,1ll<<n)fore(x,0,n){
			ll &res=dp[mk][x];
			res=INF;
			// if(!mk){res=0;continue;}
			fore(y,0,n)if(mk>>y&1){
				res=min(res,max(b[x]-a[y],0ll)+dp[mk^(1ll<<y)][y]);
			}
			// cout<<bin(mk)<<" "<<x<<": "<<res<<"\n\n";
		}
		ll res=INF,u=(1ll<<n)-1;
		fore(i,0,n)res=min(res,dp[u^(1ll<<i)][i]);
		return res;
	}
	a.pb(INF); b.pb(1);
	ll n=SZ(a);
	vector<ii>ev;
	fore(i,0,n){
		ev.pb({a[i],1});
		ev.pb({b[i],-1});
	}
	sort(ALL(ev));
	vector<ii>ed;
	fore(i,0,n)ed.pb({a[i],b[i]});
	ll s=0,flag=1;
	fore(i,0,SZ(ev)){
		s+=ev[i].snd;
		if(s)ed.pb({ev[i].fst,ev[i+1].fst});
		if(i==SZ(ev)-1||ev[i].fst!=ev[i+1].fst)flag&=s<=0;
	}
	
	//compress
	vector<ll>com;
	fore(i,0,n)com.pb(a[i]),com.pb(b[i]);
	sort(ALL(com));
	auto _com=com; com.clear();
	for(auto i:_com)if(!SZ(com)||i!=com.back())com.pb(i);
	auto getid=[&](ll v){
		return lower_bound(ALL(com),v)-com.begin();
	};
	
	for(auto [u,v]:ed){
		u=getid(u),v=getid(v);
		g[u].pb(v);
		g[v].pb(u);
	}
	ll q=0;
	fore(i,0,SZ(com))if(!vis[i]){
		dfs(i);
		q++;
	}
	// cout<<val<<" "<<q<<"\n";
	flag&=q==1;
    return !flag;
}
