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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		fore(s,0,n){
			vv b(n);
			ll mx=0;
			for(ll i=(s-1+n)%n;i!=s;i=(i-1+n)%n){
				mx=max(mx,a[i]);
				b[i]=mx;
			}
			mx=0;
			for(ll i=(s+1)%n;i!=s;i=(i+1)%n){
				mx=max(mx,a[(i-1+n)%n]);
				b[i]=min(b[i],mx);
			}
			ll res=accumulate(ALL(b),0ll);
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
