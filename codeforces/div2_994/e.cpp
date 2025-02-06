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

// ll n=1ll<<30;
// ll k=n-1;
// ll p=n-1;

// ll qs=0;
// void final(ll ans){
// 	if(ans==k)cerr<<"OK\n";
// 	else cerr<<"WA\n";
// 	cerr<<"answered "<<ans<<"\n";
// 	cerr<<"Made "<<qs<<" queries\n";
// }
// ll ask(ll l, ll r){
// 	qs++;
// 	ll ret=(r-l)>=k;
// 	if(l<=p&&p<r)ret^=1;
// 	return ret;
// }

ll ask(ll l, ll r){
	cout<<"? "<<l+1<<" "<<r<<endl;
	// cerr<<"asked "<<l+1<<" "<<r<<"\n";
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll z=n/4;
		vv v;
		fore(i,0,3)v.pb(ask(z*i,z*i+z));
		ll may=0;
		if(count(ALL(v),1)>1)may=1;
		if(count(ALL(v),may)==3)v.pb(may^1);
		else v.pb(may);
		ll s=-1,t=-1;
		fore(i,0,4){
			if(v[i]==may)s=i*z;
			else t=i*z;
		}
		// imp(v)
		// cout<<may<<" "<<s<<" "<<t<<"\n";
		// 30 left
		ll l=2,r=n-1;
		if(may)r=z-1;
		else l=z+1;
		auto get=[&](ll m){
			if(may)return ask(s,s+m);
			else {
				ll l=t,r=l+m;
				if(r>n)l-=r-n;
				r=l+m;
				ll ret=ask(l,r)^1;
				// cout<<"get "<<m<<": "<<l<<","<<r<<": "<<ret<<"\n";
				return ret;
			}
		};
		while(l<=r){
			ll m=(l+r)/2;
			if(get(m))r=m-1;
			else l=m+1;
		}
		cout<<"! "<<l<<endl;
		// final(l);
	}
	return 0;
}
