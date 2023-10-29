#include "deliveries.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll n;
vector<ii>g[MAXN];
ll tot=1; //extra zero (return)

ll t[MAXN],c[MAXN];

void init(int N, std::vector<int> u, std::vector<int> v, std::vector<int> w, std::vector<int> T) {
	n=N;
	fore(i,0,SZ(u)){
		g[u[i]].pb({v[i],w[i]});
		g[v[i]].pb({u[i],w[i]});
	}
	fore(i,0,n)t[i]=T[i],tot+=t[i];
}

long long max_time(int s, int x) {
	tot+=-t[s]+x;
	t[s]=x;
	res=0;
	
	return 0;
}
