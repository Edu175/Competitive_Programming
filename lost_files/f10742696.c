#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,x; cin>>n>>x;
	ll a[n]; fore(i,0,n)cin>>a[i];
	vector<ll>v;
	fore(m,0,1ll<<(n/2)){
		ll sum=0;
		ll mi=m;
		while(mi){
			ll i=log2(mi&-mi);
			sum+=a[i];
			mi^=mi&-mi;
		}
		v.pb(sum);
	}
	ll res=0;
	sort(ALL(v));
	fore(m,0,1ll<<((n+1)/2)){
		ll sum=0;
		ll mi=m;
		while(mi){
			ll i=log2(mi&-mi);
			sum+=a[i+n/2];
			mi^=mi&-mi;
		}
		ll upp=upper_bound(ALL(v),x-sum)-v.begin();
		ll low=lower_bound(ALL(v),x-sum)-v.begin();
		res+=upp-low;
	}
	pres;
	return 0;
}
