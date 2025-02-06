#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vv g[2555];
#define dfs(x) for(auto y:g[x])dfs(y);

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ld res=0;
	dfs(0);
	vv coef(n);
	// fore(i,n-m+1,n)res+=s[i]
	return 0;
}
