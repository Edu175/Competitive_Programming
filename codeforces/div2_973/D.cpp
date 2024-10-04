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
const ll INF=5e17;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll mn=INF,mx=-1,s=0,z=0;
		fore(i,0,n){
			s+=a[i]; z++;
			mn=min(mn,s/z);
		}
		s=0,z=0;
		for(ll i=n-1;i>=0;i--){
			s+=a[i]; z++;
			mx=max(mx,(s+z-1)/z);
		}
		cout<<mx-mn<<"\n";
	}
	return 0;
}
