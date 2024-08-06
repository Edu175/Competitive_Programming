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
	vector<ll> g[n];
	fore(i,1,n){
		U[i]--,V[i]--;
		g[U[i]].pb(V[i]);
		g[V[i]].pb(U[i]);
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
	}*/
	setHintLen(n);
	fore(i,0,n){
		for(auto j:g[i])sethint(i,j,1);
	}
}

void speedrun(int subtask, int n, int s) { /* your solution here */
	vector<ll>vis(n);
	s--;
	auto getset=[&](ll x){
		vector<ll>ret;
		fore(i,0,n)if(gethint(i))ret.pb(i);
		// cout<<"getset "<<x<<": "; imp(ret);
		return ret;
	};
	auto dfs=[&](ll x, auto &&dfs)->void{
		// if(!goTo(x))return 0;
		vis[x]=1;
		// cout<<"dfs "<<x<<"\n";
		for(auto y:getset(x))if(!vis[y]){
			if(go(y)){
				dfs(y,dfs);
				go(x);
			}
		}
	};
	dfs(s,dfs);
}

