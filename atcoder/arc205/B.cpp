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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv deg(n);
	ll tot=n*(n-1)/2;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		deg[u]++;
		deg[v]++;
	}
	ll q=0;
	fore(i,0,n){
		ll c=n-1-deg[i];
		q+=c&1;
	}
	assert(q%2==0);
	cout<<tot-q/2<<"\n";
	return 0;
}
