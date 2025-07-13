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
		sort(ALL(a));
		ll mx=a.back();
		ll res=0;
		fore(i,0,n){
			ll l=n-1,r=0; // (,)
			fore(j,i+1,n){
				ll s=mx-a[i]-a[j];
				ll e=a[i]+a[j];
				while(l>=0&&a[l]>s)l--;
				while(r<n&&(r<=j||a[r]<e))r++;
				ll li=max(l,j);
				res+=max(r-li-1,0ll);
				// cout<<i<<" "<<j<<": "<<li<<","<<r<<"\n";
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
