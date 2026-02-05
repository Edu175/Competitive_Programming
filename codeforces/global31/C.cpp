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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if(k&1){
			fore(i,0,k)cout<<n<<" ";
			cout<<"\n";
			continue;
		}
		vv pos;
		fore(i,0,__lg(n)+1)if(n>>i&1)pos.pb(i);
		reverse(ALL(pos));
		pos.pb(-1);
		vv res(k,n);
		fore(i,0,min((ll)SZ(pos)-1,k)){
			ll j=pos[i];
			ll pot=1ll<<j;
			res[i]^=pot;
			if(i%2==0)pot=1ll<<(pos[i+1]+1);
			pot--;
			res[i]|=pot;
		}
		ll x=0;
		for(auto i:res)x^=i;
		res.back()^=n^x;
		assert(res.back()<=n);
		// cerr<<accumulate(ALL(res),0ll)<<" suma\n";
		imp(res)
	}
	return 0;
}
