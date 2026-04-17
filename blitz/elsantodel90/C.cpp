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
const ll MAXN=1e5+5,MOD=1e9+7;

vv g[MAXN];

ll vis[MAXN];
ll tam=0;
void dfs(ll x){
	vis[x]=1;
	tam++;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		vv a(n),b(n),c(n);
		inp(a);
		inp(b);
		inp(c);
		fore(i,0,n){
			a[i]--;
			b[i]--;
			c[i]--;
			g[a[i]].pb(b[i]);
			g[b[i]].pb(a[i]);
		}
		fore(i,0,n)if(c[i]!=-1){
			ll x=c[i];
			if(!vis[x]){
				tam=0;
				dfs(x);
			}
		}
		ll cant=0;
		fore(i,0,n)if(!vis[i]){
			cant++;
			tam=0;
			dfs(i);
			if(tam==1)cant--;
		}
		ll res=1;
		fore(i,0,cant){
			res=res*2%MOD;
		}
		cout<<res<<"\n";
	}
	return 0;
}
