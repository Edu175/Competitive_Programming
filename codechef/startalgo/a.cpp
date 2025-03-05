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
		vv a(n),sp(n+1);
		fore(i,0,n)cin>>a[i];
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll res=0;
		fore(i,0,n){
			ll resi=a[i];
			ll l=0,r=0;
			if(i==1)l=a[i-1];
			if(i==n-2)r=a[i+1];
			// if(i==1)l=max(0ll,a[i-1]-sp[i-1]);
			// if(i<n-1)r=max(0ll,a[i+1]-(sp[n]-sp[i+2]));
			resi=max(0ll,a[i]-r-l);
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
