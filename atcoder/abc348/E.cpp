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
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll c[MAXN],a[MAXN],D[MAXN],s[MAXN];
ll n;
void dfs1(ll x, ll f){
	c[x]=1;
	s[x]=a[x];
	for(auto y:g[x])if(y!=f){
		D[y]=D[x]+1;
		dfs1(y,x);
		c[x]+=c[y];
		s[x]+=s[y];
	}
}
ll sum=0,res=0,tot=0;
void dfs2(ll x, ll f){
	res=min(res,sum);
	//cout<<x<<": "<<sum<<"*"<<a[x]<<" = "<<sum*a[x]<<"\n";
	for(auto y:g[x])if(y!=f){
		sum+=tot-2*s[y];
		dfs2(y,x);
		sum-=tot-2*s[y];
	}
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)cin>>a[i];
	dfs1(0,-1);
	fore(i,0,n)sum+=D[i]*a[i],tot+=a[i];
	res=sum;
	dfs2(0,-1);
	cout<<res<<"\n";
	return 0;
}
