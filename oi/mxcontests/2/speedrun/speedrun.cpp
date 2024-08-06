#include "speedrun.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcont=b;i<mxcont;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jfhg:v)cout<<jfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void sethint(ll i, ll j, ll b){
	setHint(i+1,j+1,b);
}
bool gethint(ll j){
	return getHint(j+1);
}
bool go(ll x){
	return goTo(x+1);
}
void assignHints(int subtask, int n, int U[], int V[]) { /* your solution here */
	vector<vector<ll>> g(n);
	fore(i,1,n){
		U[i]--,V[i]--;
		g[U[i]].pb(V[i]);
		g[V[i]].pb(U[i]);
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
	}*/
	vector<ll>ord,vis(n),fa(n);
	auto dfs=[&](ll x, auto &&dfs)->void{
		vis[x]=1; ord.pb(x);
		for(auto y:g[x])if(!vis[y]){
			fa[y]=x;
			dfs(y,dfs);
		}
	};
	dfs(0,dfs);
	// imp(ord);
	setHintLen(20);
	fore(i,0,n){
		ll x=ord[i],y=(i==n-1?1023:ord[i+1]);
		fore(j,0,10)sethint(x,j,fa[x]>>j&1);
		fore(j,0,10)sethint(x,j+10,y>>j&1);
	}
}

void speedrun(int subtask, int n, int s) { /* your solution here */
	s--;
	ll x=s;
	auto get=[&](ll b){
		ll mk=0;
		fore(i,0,10)mk|=ll(gethint(i+10*b))<<i;
		// cout<<"get "<<b<<": "<<mk<<"\n";
		return mk;
	}; 
	// cout<<x<<endl;
	auto up=[&](ll &x){
		x=get(0);
		// cout<<"up "<<x<<endl;
		assert(go(x));
	};
	while(x){
		up(x);
	}
	// raiz
	queue<ll>q;
	while(x<n){
		q.push(get(1));
		while(q.front()<n&&!go(q.front()))up(x);
		x=q.front(); q.pop();
	}
}

