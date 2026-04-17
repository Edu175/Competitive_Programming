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

bool can(ll n, ll s, ll m){
	for(ll j=61;j>=0;j--)if(m>>j&1){
		ll pot=1ll<<j;
		ll q=s/pot;
		q=min(q,n);
		s-=q*pot;
	}
	return s==0;
}
ll R=5e18;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll s,m; cin>>s>>m;
		ll l=0,r=R;
		while(r-l>1){
			ll h=(l+r)/2;
			if(can(h,s,m))r=h;
			else l=h;
		}
		ll res=r;
		if(res>=R)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
