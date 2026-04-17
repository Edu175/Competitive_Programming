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
const ll MAXV=1e9+100;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll mn=*min_element(ALL(a));
		ll mx=*max_element(ALL(a));
		vv d(n);
		fore(i,0,n)d[i]=max(a[i]-mn,mx-a[i]);
		auto can=[&](ll k){
			vv b(n,-1);
			vv c;
			fore(i,0,n){
				if(k>d[i])b[i]=a[i];
				else c.pb(a[i]);
			}
			sort(ALL(c));
			ll po=0;
			fore(i,0,n)if(b[i]==-1){
				b[i]=c[po++];
			}
			auto bs=b; sort(ALL(bs));
			return bs==b;
		};
		ll l=0,r=MAXV;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))l=m;
			else r=m;
		}
		ll res=l;
		if(res>=MAXV-3)res=-1;
		cout<<res<<"\n";

	}
	return 0;
}
