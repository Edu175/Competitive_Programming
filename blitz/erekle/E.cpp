#include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <array>
// #include <priority_queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

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
#define pres cout<<res<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=3e5+5;
ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll sum[MAXN];
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	assert(x!=y);
	if(uf[x]>uf[y])swap(x,y);
	sum[x]+=sum[y];
	uf[x]+=uf[y];
	uf[y]=x;
}
int main(){FIN;
	// freopen("","r",stdin);
	// freopen("","w",stdout);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<ii> sa;
		priority_queue<ii,vector<ii>, greater<ii>> pq;
		vector<vector<ii>> g(n);
		fore(i,0,n){
			cin>>a[i],sum[i]=a[i];
			uf[i]=-1;
			pq.push({a[i],i});
		}
		fore(i,0,n-1){
			ll u,v,w; cin>>u>>v>>w;
			u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		while(SZ(pq)){
			auto [asd,x]=pq.top(); pq.pop();
			for(auto [y,w]:g[x]){
				
			}
		}
		for(auto [w,u,v]:ed){
			u=uf_find(u);
			v=uf_find(v);
			if(w>=min(sum[u],sum[v]))continue;
			uf_join(u,v);
			ll p=uf_find(u);
			sum[p]-=w;
			res=max(res,sum[p]);
		}
		ll res=0;
		// fore(x,0,n){
		// 	if(uf_find(x)==x){
		// 		res=max(res,sum[x]);
		// 	}
		// }
		cout<<res<<"\n";
	}
	return 0;
}
