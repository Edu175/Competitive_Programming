#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
vector<ii> g[MAXN];

ll done=0;
vv cyc;
ll vis[MAXN];
void dfs(ll x){
	done|=x==1;
	if(done)return;
	for(auto [y,i]:g[x])if(!done&&!vis[y]){
		cyc.pb(i);
		vis[x]=1;
		dfs(y);
		if(done)return;
		cyc.pop_back();
	}
}
vector<ii>ed;
ll go(ll x, ll i, ll pr=0){
	ll ret=ed[i].fst;
	if(ret==x)ret=ed[i].snd;
	if(pr)cout<<"MOVE "<<ret<<"\n";
	return ret;
}
ll esta[MAXN];
vv p;

void dfs2(ll x){
	done|=esta[x];
	if(done)return;
	vis[x]=1;
	for(auto [y,i]:g[x])if(!done&&!vis[y]){
		p.pb(i);
		dfs2(y);
		if(done)return;
		p.pop_back();
	}
}
ll apa(ll x, ll i){
	return ed[i].fst==x||ed[i].snd==x;
}
int main(){JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed.pb({u,v});
	}
	dfs(1);
	for(auto i:cyc)esta[ed[i].fst]=esta[ed[i].snd]=1;
	mset(vis,0);
	done=0;
	dfs2(0);
	ll x=0;
	vv ka,kb;
	for(auto i:p)x=go(x,i),ka.pb(i);
	ll t=x,pos=-1;
	if(apa(t,cyc[0])&&apa(t,cyc.back()))
		rotate(cyc.begin(),cyc.begin()+1,cyc.end());
	
	fore(i,0,SZ(cyc))if(apa(t,cyc[i]))pos=i;
	ll did=0;
	do{
		did|=x==1;
		ll i=cyc[pos];
		if(did)kb.pb(i);
		else ka.pb(i);
		x=go(x,i);
		pos=(pos+1)%SZ(cyc);
	}while(x!=t);
	
	imp(ka);
	imp(kb);
	
	x=0;
	for(auto i:ka){
		if(x==t){
			cout<<"DROP ";
			for(auto i:p)cout<<i<<" ";;cout<<"\n";
		}
		x=go(x,i,1);
		
	}
    return 0;
}