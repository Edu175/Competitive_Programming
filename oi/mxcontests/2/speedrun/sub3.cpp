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
const ll C=31;
void assignHints(int subtask, int n, int U[], int V[]) { /* your solution here */
	vector<ll> g[n];
	fore(i,1,n){
		U[i]--,V[i]--;
		g[U[i]].pb(V[i]);
		g[V[i]].pb(U[i]);
	}
	fore(i,0,n)sort(ALL(g[i]));
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
	}*/
	setHintLen(316);
	fore(i,0,n){
		g[i].pb(1023);
		fore(j,0,min(C,(ll)SZ(g[i]))){
			fore(k,0,10)sethint(i,j*10+k,g[i][j]>>k&1);
		}
		sethint(i,315,(SZ(g[i])>C));
	}
}

void speedrun(int subtask, int n, int s) { /* your solution here */
	vector<ll>vis(n); s--;
	auto getset=[&](ll x){
		vector<ll>ret;
		fore(i,0,C){
			ll mk=0;
			fore(j,0,10)mk|=ll(gethint(i*10+j))<<j;
			if(mk==1023)break;
			ret.pb(mk);
		}
		if(gethint(315))fore(y,ret.back()+1,n)ret.pb(y);
		
		
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

