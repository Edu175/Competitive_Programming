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
		a.resize(unique(ALL(a))-a.begin());
		n=SZ(a);
		auto get=[&](ll i){
			if(a[i])
		};
		ll res=0;
		fore(i,0,n){
			ll m=2*a[i];
			while(1){
				ll p=lower_bound(ALL(a),m)-a.begin();
				if(p>i)res=max(res,a[p-1]%a[i]);
				m+=a[i];
				if(p==n)break;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
