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
		ll res=0;
		for(ll i=2;i<n;i+=2){
			ll s=a[i-2]+a[i];
			ll c=max(s-a[i-1],0ll);
			ll q=min(a[i],c);
			res+=q,a[i]-=q;
		}
		a.pb(0);
		// cout<<res<<": ";
		// imp(a) cout<<endl;
		for(ll i=0;i+1<n;i+=2){ // arreglo el de la derecha
			ll s=a[i]+a[i+2];
			ll c=max(s-a[i+1],0ll);
			if(!c)continue;
			assert(!a[i+2]); // no lo pude ayudar con ese
			ll q=min(a[i],c);
			res+=q,a[i]-=q;
		}
		cout<<res<<"\n";

	}
	return 0;
}