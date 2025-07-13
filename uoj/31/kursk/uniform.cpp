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
#pragma GCC optimize("Ofast") // may lead to precision errors
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnts,popcnt")
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		a.resize(unique(ALL(a))-a.begin());
		n=SZ(a);
		ll res=0;
		if(n<=5005){
			fore(i,0,n)fore(j,i+1,n){
				res=max(res,a[j]%a[i]);
			}
			cout<<res<<"\n";
			continue;
		}
		ll v;
		auto f=[&](ll s, ll e, ll l, ll r, auto &&f){
			ll m=(s+e)/2,val=v*m;
			ll p=lower_bound(a.begin()+l,a.begin()+r,val)-a.begin();
			if(e-s==1){
				res=max(res,a[p-1]%v);
				return;
			}
			f(s,m,l,p,f);
			f(m,e,p,r,f);
		};
		for(ll i=n-1;i>=0;i--){
			if(res>=a[i]-1)break;
			ll mx=a.back()/a[i]+1;
			v=a[i];
			f(2,mx+1,i+1,n,f);
		}
		cout<<res<<"\n";
	}
	return 0;
}
