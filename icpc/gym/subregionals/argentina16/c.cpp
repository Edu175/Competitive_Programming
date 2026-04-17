#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ll MAXN=5e4+5;

vector<ll> g[MAXN];
ll is[MAXN],ned[MAXN];
ll res=0;
void prop(ll x){
	if(is[x]&&!ned[x]){
		res++;
		for(auto y:g[x])ned[y]--,prop(y);
	}
}
int main(){JET
    ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		ned[v]++;
	}
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	for(auto i:a){
		is[i]=1;
		prop(i);
		cout<<res<<"\n";
	}
    return 0;
}