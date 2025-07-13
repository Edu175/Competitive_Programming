#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast") // may lead to precision errors
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=5e5+5;

ll a[MAXN];
ll v,res;
void f(ll s, ll e, ll l, ll r){
	if(r==l){
		if(l)res=max(res,a[r-1]%v);
		return;
	}// cerr<<s<<" "<<e<<" "<<l<<" "<<r<<"\n";
	ll m=(s+e)/2,val=v*m;
	ll p=lower_bound(a+l,a+r,val)-a;
	if(e-s==1){
		res=max(res,a[p-1]%v);
		return;
	}
	f(s,m,l,p);
	f(m,e,p,r);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		n=(unique(a,a+n))-a;
		res=0;
		// if(n<=5005){
		// 	fore(i,0,n)fore(j,i+1,n){
		// 		res=max(res,a[j]%a[i]);
		// 	}
		// 	cout<<res<<"\n";
		// 	continue;
		// }
		for(ll i=n-1;i>=0;i--){
			// cerr<<i<<"\n";
			if(res>=a[i]-1)break;
			ll mx=a[n-1]/a[i]+1;
			v=a[i];
			f(2,mx+1,i+1,n);
		}
		cout<<res<<"\n";
	}
	return 0;
}
