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
const ll MAXN=105;
vector<ll> g[MAXN];

vector<ll> ret[MAXN];
ll c[MAXN],vis[MAXN];
vector<ll>p;

void doit(ll x){
	ll did=0;
	vector<ll>cyc;
	for(auto i:p){
		if(i==x)did=1;
		if(did)cyc.pb(i);
	}
	cout<<"doit "<<x<<": ";imp(p); imp(cyc);
	for(auto i:cyc)if(!SZ(ret[i]))ret[i]=cyc;
}

void dfs(ll x){
	vis[x]=1;
	p.pb(x);
	cout<<"dfs "<<x<<" "<<c[x]<<": "; imp(p);
	for(auto y:g[x]){
		if(!vis[y]){
			c[y]=c[x]^1;
			dfs(y);
		}
		else if(c[y]==c[x])doit(y);
	}
	p.pop_back();
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		if(c=='Y')g[i].pb(j),g[j].pb(i);
	}
	dfs(0);
	fore(i,0,n){
		for(auto x:ret[i])cout<<x<<" ";;cout<<"-1\n";
	}
	return 0;
}
