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

#define ppc __builtin_popcountll
bool ispot(ll n){return ppc(n)==1;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv res={n};
		while(1){
			ll k=n&-n;
			if(k==n)break;
			n-=k;
			res.pb(n);
		}
		ll k=n&-n; k/=2;
		// cerr<<"pot "<<n<<": "<<k<<"\n";
		while(n>1){
			n-=k; k>>=1;
			res.pb(n);
		}
		// assert(n==1);
		cout<<SZ(res)<<"\n";
		imp(res)
		
	}
	return 0;
}
