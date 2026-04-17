// #include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define inp(v) {for(auto &i:v)cin>>i;}
#define menos1(v) {for(auto &i:v)i--;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

ll vised[MAXN];

set<ll> vis;
map<ll,vector<ii>> g;
array<ll,3> ult;
void dfs(ll x){
	vis.insert(x);
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		ult={x,y,i};
		if(!vis.count(y))dfs(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		g.clear();
		vis.clear();
		set<ll> nods;
		vector<ii> ed;
		ll m; cin>>m;
		fore(i,0,m)vised[i]=0;
		fore(i,0,m){
			ll u,v; cin>>u>>v; //u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
			ed.pb({u,v});
			nods.insert(u);
			nods.insert(v);
		}
		vector<array<ll,3>> us;
		for(auto i:nods)if(!vis.count(i)){
			ult[0]=-1;
			dfs(i);
			assert(ult[0]!=-1);
			us.pb(ult);
		}
		vector<array<ll,3>> res;
		fore(i,1,SZ(us)){
			res.pb({us[i][2],us[i][1],us[i-1][0]});
		}
		cout<<SZ(res)<<"\n";
		for(auto [i,a,b]:res){
			cout<<i+1<<" "<<a<<" "<<b<<"\n";
		}
	}
	return 0;
}
