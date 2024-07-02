#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=1e6+5,MAXN=2005;
vector<ii> g[MAXN];

ll dfs(ll x, ll d, ll dist, ll fa){
	ll res=d*dist;
	// cout<<x<<": "<<d<<"*"<<dist<<" = "<<d*dist<<"\n";
	for(auto [y,w]:g[x])if(y!=fa){
		res=max(res,dfs(y,__gcd(d,w),dist+1,x));
	}
	return res;
}

long long int Arbolstian(int n, vector<int> u,
vector<int> v, vector<int> w) {
	fore(i,0,n){
		g[i].clear();
	}
	fore(i,0,SZ(u))
		g[u[i]].pb({v[i],w[i]}),
		g[v[i]].pb({u[i],w[i]});
	ll res=0;
	fore(x,0,n){
		// cout<<"root "<<x<<"\n";
		res=max(res,dfs(x,0,0,-1));
	}
	return res;
}