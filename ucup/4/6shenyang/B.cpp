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
		ll n,m,a,b; cin>>n>>m>>a>>b;
		vv c(n*m+1);
		fore(i,0,n*m){
			ll x; cin>>x;
			c[x]++;
		}
		ll z=c[0];
		c.erase(c.begin()); // sin el 0
		sort(ALL(c)); reverse(ALL(c));
		while(SZ(c)&&!c.back())c.pop_back();
		ll res=0; // k=0
		fore(i,0,SZ(c))res+=a*c[i];
		ll ans=res;
		fore(k,1,SZ(c)+1){
			res+=z*b;
			ll p=k-1;
			res-=a*c[p];
			res+=p*b*c[p];
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
