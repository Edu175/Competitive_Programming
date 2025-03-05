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
		vv c(2);
		ll n; cin>>n;
		fore(i,0,n){
			ll x; cin>>x;
			c[x&1]++;
		}
		ll res=c[1];
		if(!c[0])res--;
		else res++;
		cout<<res<<"\n";
		// cout<<c[0]+max(0ll,c[1]-1)<<"\n";
	}
	return 0;
}
