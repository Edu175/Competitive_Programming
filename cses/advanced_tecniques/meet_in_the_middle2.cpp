#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll C=min((ll)20,n);
	vector<ll>v;
	fore(mk,0,1ll<<C){
		ll sum=0;
		fore(i,0,C)if((1ll<<i)&mk)sum+=a[i];
		v.pb(sum);
	}
	sort(ALL(v));
	ll res=0;
	fore(mk,0,1ll<<(n-C)){
		ll sum=0;
		fore(i,0,n-C)if((1ll<<i)&mk)sum+=a[i+C];
		sum=k-sum;
		res+=(lower_bound(ALL(v),sum+1)-v.begin())-
		(lower_bound(ALL(v),sum)-v.begin());
	}
	cout<<res<<"\n";
	return 0;
}
