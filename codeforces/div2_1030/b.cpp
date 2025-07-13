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
		vector<array<ll,3>>res;
		fore(i,0,n){
			ll m=i;
			if(0<m)res.pb({i,0,m});
			res.pb({i,m,n});
		}
		cout<<SZ(res)<<"\n";
		for(auto [i,l,r]:res){
			cout<<i+1<<" "<<l+1<<" "<<r<<"\n";
		}
	}
	return 0;
}
