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
		vv a(n),b;
		fore(i,0,n)cin>>a[i],b.pb(a[i]);
		sort(ALL(b));
		ll res=n+5;
		fore(i,0,n){
			ll p=upper_bound(ALL(b),a[i])-b.begin();
			res=min(res,n-p+i);
		}
		cout<<res<<"\n";
	}
	return 0;
}
