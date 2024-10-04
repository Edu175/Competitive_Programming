#include "sphinx.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=255;
ll ask(vector<ll> E){
	ll ret=perform_experiment(E);
	// cout<<"ask { ";
	// for(auto i:E)cout<<i<<" ";
	// cout<<"} "<<ret<<"\n";
	return ret;
}
vector<ll> g[MAXN];
ll n;
vv c;
ll vis[MAXN];
void dfs0(ll x, vv &c){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]&&c[y]==c[x])dfs0(y,c);
}
ll cont(vector<ll>c){ //only red
	mset(vis,0);
	ll res=0;
	fore(i,0,n)if(!vis[i]){
		res+=c[i]==n;
		dfs0(i,c);
	}
	return res;
}

bool hay(ll x, vv h){
	vector<ll>is(n);
	for(auto i:h)is[i]=1;
	vv E(n,-1);
	vv no;
	for(auto y:g[x])if(!is[y]){
		no.pb(y);
		E[y]=n;
	}
	ll og=ask(E);
	ll c=cont(E);
	E[x]=n;
	ll roj=ask(E);
	// if(!SZ(no))roj--,cout<<"-- ";
	roj+=c-1;
	ll ret=og!=roj+1;
	// cout<<"hay "<<x<<" | "; imp(h);
	// cout<<og<<" "<<roj<<"\n";
	// cout<<"= "<<ret<<"\n\n";
	return ret;
}
void bfs(ll s){
	queue<ll>q;
	q.push(s);
	// cout<<"bfs "<<s<<"\n";
	while(SZ(q)){
		auto x=q.front(); q.pop();
		vv nxt;
		for(auto y:g[x])if(c[y]==-1)nxt.pb(y);
		// if(!SZ(nxt))continue;
		// cout<<x<<": "; imp(nxt)
		if(!hay(x,nxt))continue;
		ll p=0;
		while(p<SZ(nxt)){
			auto get=[&](ll m){
				vv h;
				fore(i,p,m+1)h.pb(nxt[i]);
				return h;
			};
			// if(!hay(x,get(SZ(nxt)-1)))continue;
			ll l=p,r=SZ(nxt)-1;
			// cout<<p<<" p\n";
			while(l<=r){
				// cout<<l<<","<<r<<"\n";
				ll m=(l+r)/2;
				if(hay(x,get(m)))r=m-1;
				else l=m+1;
			}
			if(l<SZ(nxt)){
				c[nxt[l]]=c[x];
				q.push(nxt[l]);
			}
			p=l+1;
		}
	}
}

vector<int> find_colours(int N, vector<int> U, vector<int> V){
	n=N;
	fore(i,0,SZ(U)){
		g[U[i]].pb(V[i]);
		g[V[i]].pb(U[i]);
	}
	c=vv(n,-1);
	ll cnt=0;
	fore(i,0,n)if(c[i]==-1){
		c[i]=cnt++;
		bfs(i);
	}
	return c;
}
