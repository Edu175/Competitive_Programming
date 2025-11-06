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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv xp(n+1);
		fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
		vv canl(n+1),canr(n+1);
		vv l0(n+1),r0(n+1);
		vv res(n);
		// ll all=(1ll<<B)-1;
		for(ll z=n;z>0;z--)fore(l,0,n-z+1){
			ll r=l+z;
			assert(r<=n);
			ll x=xp[r]^xp[l];
			if(z==n||(canl[l]&x)||(canr[r]&x)||l0[l]||r0[r]){
				// cout<<l<<","<<r<<" "<<x<<"\n";
				if(x){
					ll mk=1ll<<__lg(x);
					canl[l]|=mk;
					canr[r]|=mk;
				}
				else l0[l]=r0[r]=1;
				if(z==1)res[l]=1;
			}
		}
		fore(i,0,n)cout<<res[i];;cout<<"\n";
	}
	return 0;
}
