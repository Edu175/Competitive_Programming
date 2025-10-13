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

ll get(ll x, ll l, ll r){ // [l,r]
	ll m=(r/x)*x;
	if(m>=l)return m;
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll sum=0,mx=0;
		fore(i,0,n){
			ll x; cin>>x;
			sum+=x;
			mx=max(mx,x);
		}
		ll res=1;
		// cout<<sum<<" "<<sum+k<<"\n";
		fore(c,1,n+1){
			ll m=get(c,sum,sum+k);
			// cout<<k<<": "<<m<<"\n";
			if(m==-1)continue;
			ll d=m/c;
			if(d>=mx){
				res=c;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
