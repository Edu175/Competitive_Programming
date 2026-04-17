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
const ll MAXN=1e6+5;
ll n,m;
ii cv(ll x){return {x/m,x%m};}
ll cv(ll i, ll j){return m*i+j;}
ll f[MAXN],hay[MAXN],vis[MAXN];
ll d[MAXN],pa[MAXN],p[MAXN],t[MAXN],id[MAXN];//,g[MAXN];

//vector<ll>ord;
void dfs(ll x){
	if(d[x]!=-1)return;
	dfs(f[x]);
	d[x]=d[f[x]]+1;
	pa[x]=pa[f[x]];
	id[x]=id[f[x]];
	//ord.pb(x);
}
ll bien=1;
int main(){FIN;
	cin>>n>>m;
	ll task; cin>>task;
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		ll x=cv(i,j);
		if(c>='A'&&c<='Z')hay[x]=1;
		else hay[x]=0;
		c=tolower(c);
		if(c=='n')f[x]=x-m;
		if(c=='e')f[x]=x+1;
		if(c=='s')f[x]=x+m;
		if(c=='w')f[x]=x-1;
	}
	ll N=n*m;
	mset(d,-1);
	vector<vector<ll>>cyc;
	fore(x,0,N)if(!vis[x]){
		vector<ll>v,c;
		auto y=x;
		for(;!vis[y];y=f[y]){
			v.pb(y);
			vis[y]=1;
		}
		ll did=0;
		for(auto z:v){
			if(z==y)did=1;
			if(did){
				id[z]=SZ(cyc);
				p[z]=SZ(c);
				pa[z]=z;
				d[z]=0;
				c.pb(z);
				//ord.pb(z);
			}
		}
		if(SZ(c))cyc.pb(c);
	}
	fore(x,0,N)dfs(x);
	//fore(i,0,SZ(cyc)){imp(cyc[i]);}
	//fore(x,0,N)cout<<x<<": "<<id[x]<<" "<<d[x]<<" "<<pa[x]<<"\n";
	vector<ll>b[SZ(cyc)];
	fore(x,0,N)if(hay[x]){
		b[id[x]].pb(x);
		//g[x]=(d[x]-p[pa[x]]+k)%k;
	}
	mset(t,-1);
	vector<ll>res;
	fore(i,0,SZ(cyc)){
		ll k=SZ(cyc[i]);
		b[i].resize(min(k,(ll)SZ(b[i])));
		fore(j,0,SZ(b[i])){
			ll x=b[i][j];
			t[x]=((-d[x])%k+p[pa[x]]-j+3*k)%k+1;
			res.pb(x);
		}
	}
	cout<<SZ(res)<<"\n";
	if(task){
		for(auto x:res)cout<<cv(x).fst+1<<" "<<cv(x).snd+1<<" "<<t[x]<<"\n";
	}
	return 0;
}
