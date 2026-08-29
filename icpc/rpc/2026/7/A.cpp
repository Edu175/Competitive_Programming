#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	map<ll,vv> mp;
	fore(i,0,n){
		ll a,b; cin>>a>>b;
		mp[a].pb(b);
	}
	ld res=0;
	for(auto [asd,v]:mp){
		sort(ALL(v));
		ll n=SZ(v);
		fore(i,0,n/2){
			res+=log(v[n-1-i])-log(v[i]);
		}
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
