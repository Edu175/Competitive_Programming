#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 3e5;
vv g[maxn];
ll cmp[maxn], mxcmp[maxn];
vv vcmp[maxn];
ll qcmp = 0;


void dfs(ll x){
	cmp[x] = qcmp;
	vcmp[qcmp].pb(x);
	mxcmp[qcmp] = max(mxcmp[qcmp],x);
	for(auto y:g[x])if(cmp[y] == -1)dfs(y);
}

void merge(ll x, ll y){
	for(auto v : vcmp[y]){
		vcmp[x].pb(v);
		cmp[v] = x;
		mxcmp[x] = max(mxcmp[x],v);
	}
	vcmp[y].clear();
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	mset(cmp,-1);
	fore(i,0,n) if(cmp[i] == -1){
		dfs(i);
		qcmp++;
	}
	ll act = cmp[0];
	ll res = 0;
	fore(i,0,n){
		if(i>mxcmp[act]) act = cmp[i];
		if(cmp[i] != act) merge(act,cmp[i]),res++;
	}
	cout<<res<<"\n";
	
	
	return 0;
}
