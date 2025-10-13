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
const ll INF=2e9+5;
ll n;
vv zon(ll i, ll j){
	ll h=n/2;
	vv r;
	if(i<=h&&j<=h)r.pb(0);
	if(i<=h&&j>=h)r.pb(1);
	if(i>=h&&j>=h)r.pb(2);
	if(i>=h&&j<=h)r.pb(3);
	
	if(i<=h&&j==h)r.pb(4);
	if(i==h&&j>=h)r.pb(5);
	if(i>=h&&j==h)r.pb(6);
	if(i==h&&j<=h)r.pb(7);
	
	if(i==h&&j==h)r.pb(8);
	
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<vv>a(n,vv(n));
		
		vv b(9,INF);
		fore(i,0,n)fore(j,0,n){
			cin>>a[i][j];
			auto v=zon(i,j);
			for(auto z:v)b[z]=min(b[z],a[i][j]);
		}
		ll res=b[8];
		res=min(res,accumulate(b.begin(),b.begin()+4,0ll));
		fore(i,4,8){
			ll j=(i+2)%4,k=(i+3)%4;
			res=min(res,b[i]+b[j]+b[k]);
		}
		fore(i,4,6)res=min(res,b[i]+b[i^2]);
		cout<<res<<"\n";
	}
	return 0;
}
