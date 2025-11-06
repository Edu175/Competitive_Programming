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
		auto get=[&](ll u)->pair<vv,ll> {
			vv a;
			a.pb(u);
			ll res=0;
			while(SZ(a)<n){
				ll v=u/2+1;
				res+=u-v;
				a.pb(v);
				u=v;
			}
			return {a,res};
		};
		ll l=0,r=5*k+100;
		while(r-l>1){
			ll m=(l+r)/2;
			if(get(m).snd>=k)r=m;
			else l=m;
		}
		ll u=r;
		auto [a,c]=get(u);
		assert(c>=k);
		assert(c==k);
		// fore(i,0,n)if(c>k){
		// 	ll q=min(c-k,a[i]-a[i+1]);
		// 	a[i]-=q;
		// 	c-=q;
		// }
		reverse(ALL(a));
		imp(a)
	}
	return 0;
}
