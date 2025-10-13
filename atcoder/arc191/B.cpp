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
		ll n,k; cin>>n>>k; k--;
		ll m=__lg(n)+1;
		ll z=m-__builtin_popcountll(n);
		if(k>=(1ll<<z)){
			cout<<"-1\n";
			continue;
		}
		vv pos;
		fore(j,0,m)if(!(n>>j&1))pos.pb(j);
		assert(SZ(pos)==z);
		ll res=n;
		fore(j,0,SZ(pos)){
			if(k>>j&1)res|=1ll<<pos[j];
		}
		cout<<res<<"\n";
	}
	return 0;
}
