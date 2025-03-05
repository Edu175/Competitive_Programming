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
	// ll t; cin>>t;
	// while(t--){
		ll n; cin>>n;
		vv c(2),od(2);
		fore(i,0,n){
			ll x; cin>>x; c[x]++;
			if(x)od[i&1]++;
		}
		ll res=0;
		if(n%4==0)res=1;
		else if(n&1)res=c[1]>=1;
		else res=od[0]&&od[1];
		if(res)cout<<"Yes\n";
		else cout<<"No\n";
	// }
	return 0;
}
