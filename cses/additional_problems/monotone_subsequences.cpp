#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if((n+k-1)/k>k){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		vector<ll>a;
		fore(i,0,n)a.pb(i+1);
		for(ll i=0;i<n;i+=k){
			ll e=min(n,i+k);
			reverse(a.begin()+i,a.begin()+e);
		}
		imp(a);
	}
	return 0;
}
