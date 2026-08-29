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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv dos={1,2,1,1,2,2,1,2};
vv tres={1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3};

int main(){FIN;
	for(auto &i:dos)i--;
	for(auto &i:tres)i--;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv res;
		for(ll i=0;i<n;){
			ll ty=i+3==n;
			for(auto j:(ty?tres:dos))res.pb(1+i+j);
			i+=2+ty;
		}
		show(res)
	}
	return 0;
}
