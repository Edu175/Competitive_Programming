#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=1e5+5;

ll n;
vv a,b;

bool can(ll k){
	vector<ll> c;
	fore(i,0,n){
		ll ac=0;
		ac+=a[i]>=k?1:-1;
		ac+=b[i]>=k?1:-1;
		if(ac){
			if(!(ac<0&&SZ(c)&&c.back()<0))c.pb(ac);
		}
	}
	ll sum=0;
	for(auto i:c)sum+=i;
	return sum>0;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a=b=vv(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll l=-1,r=2*n+5;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))l=m;
			else r=m;
		}
		ll res=l;
		cout<<res<<"\n";
	}
	return 0;
}
