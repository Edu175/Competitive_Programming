#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=320;

int main(){
	JET
	ll n; cin>>n;
	vector<ii>ed;
	vector<ld> p(n);
	fore(i,0,n)cin>>p[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v;
		ed.pb({u,v});
	}
	ll q; cin>>q;
	while(q--){
		ll i; ld v; cin>>i>>v;
		p[i]=v;
		ld psum=0;
		fore(i,0,n)psum+=p[i];
		ld res=-psum+n;
		for(auto [u,v]:ed){
			res+=-(1-p[u])*(1-p[v]);
			// res+=p[u]+p[v]-p[u]*p[v];
		}
		cout<<res<<"\n";
	}
	return 0;
}