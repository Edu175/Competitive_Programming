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

ll cf(ll n){return __builtin_ctzll(n);}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r; r++;
		ll k=min(cf(l),cf(r));
		if((r-l)%2==0){
			ll lg=__lg(r);
			ll m=0,did=0;
			for(ll j=lg;j>=0;j--){
				ll bl=l>>j&1;
				ll br=r>>j&1;
				if(bl==br)m|=bl<<j;
				else {
					m|=1ll<<j;
					did=1;
					// if()
					break;
				}
			}
			assert(did);
			if(m-l==r-m)k++;
		}
		ll res=(1ll<<k)-1;
		cout<<res<<"\n";
	}
	return 0;
}
