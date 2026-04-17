#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=3e5+5,MOD=112345687;

vector<pair<ll,ll>> g[MAXN];
bool vis[MAXN], p[MAXN];
vector<ll>ord,h;
void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i.fst])dfs(i.fst);
	}
	ord.pb(x);
}
ll fpow(ll b, ll e){
	if(e<0)return 1;
	ll ret=1;
	while(e){
		if(e&1)ret=(ret*b)%MOD;
		b=(b*b)%MOD,e>>=1;
	}
	return ret;
}
ll dp[2][MAXN];
int toriis(int n, vector<int> &inicio, vector<int> &fin, vector<long long> &cantidad){
	fore(i,0,n){
    	g[i].clear();
    	vis[i]=0;
    }
    ord.clear(),h.clear();
    fore(i,0,SZ(inicio)){
    	fin[i]--,inicio[i]--;
    	p[fin[i]]=1;
    	g[inicio[i]].pb({fin[i],cantidad[i]});
    }
    /*fore(i,0,n){
    	cout<<i<<": ";
    	for(auto j:g[i])cout<<j.fst<<","<<j.snd<<" ";
    	cout<<"\n";
    }*/
    fore(i,0,n){
    	if(!vis[i])dfs(i);
    	if(SZ(g[i])==0)h.pb(i);
    }
    reverse(ALL(ord));
    for(auto u:ord){
    	if(!p[u])dp[0][u]=1;
    	for(auto v:g[u]){
    		//dp[0][v.fst]=(dp[0][v.fst]+dp[0][u])%MOD;
    		ll cp=fpow(2,v.snd-1),ci=(v.snd?fpow(2,v.snd-1):0);
    		//cout<<u+1<<"->"<<v.fst+1<<": "<<cp<<" "<<ci<<"\n";
    		dp[0][v.fst]=(dp[0][v.fst]+(dp[0][u]*cp))%MOD;
    		dp[0][v.fst]=(dp[0][v.fst]+(dp[1][u]*ci))%MOD;
    		dp[1][v.fst]=(dp[1][v.fst]+(dp[1][u]*cp))%MOD;
    		dp[1][v.fst]=(dp[1][v.fst]+(dp[0][u]*ci))%MOD;
    	}
    }
    /*for(auto i:ord){
    	cout<<i+1<<": 0="<<dp[0][i]<<" 1="<<dp[1][i]<<"\n";
    }*/
    ll res=0;
    for(auto i:h)res=(res+dp[0][i])%MOD;
    return res;
}
