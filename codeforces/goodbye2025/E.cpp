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

ll ask(ll l, ll r){
	cout<<"? "<<l+1<<" "<<r<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		auto getcut=[&](ll L, ll R, ll sum){
			ll l=L,r=R;
			while(r-l>1){
				ll m=(l+r)/2;
				ll sl=ask(L,m),sr=sum-sl;
				if(sl<sr)l=m;
				else r=m;
			}
			return r;
		};
		ll l=0,r=n,sum=ask(0,n);
		while(r-l>1){
			// cerr<<l<<","<<r<<" "<<sum<<"\n";
			ll m=getcut(l,r,sum);
			if(m-l<r-m)r=m;
			else l=m;
			assert(sum%2==0);
			sum/=2;
		}
		assert(r-l==1);
		cout<<"! "<<sum<<endl;
	}
	return 0;
}
