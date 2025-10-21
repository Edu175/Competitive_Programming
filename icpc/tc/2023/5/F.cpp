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
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto getod=[&](ll i){
		assert(0<i&&i<n-1);
		if(a[i-1]<a[i]&&a[i]>a[i+1])return max(a[i-1],a[i+1]);
		return a[i];
	};
	auto getpar=[&](ll i){
		assert(i<n-1);
		return max(a[i],a[i+1]);
	};
	ll val0=0,val1=0;
	fore(k,0,n){
		ll m=n-k;
		ll res;
		if(m==1)res=*max_element(ALL(a));
		else if(m&1){
			val1=max({val1,getod(m/2),getod(n-1-m/2)});
			res=val1;
		}
		else {
			val0=max({val0,getpar(m/2-1),getpar(n-1-m/2)});
			res=val0;
		}
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}
