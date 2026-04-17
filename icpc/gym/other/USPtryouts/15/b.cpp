#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv res;
		fore(b,2,17){
			vv v;
			ll x=n;
			while(x)v.pb(x%b),x/=b;
			auto rv=v;
			reverse(ALL(rv));
			if(v==rv)res.pb(b);
		}
		if(!SZ(res))cout<<"-1\n";
		else {
			for(auto i:res)cout<<i<<" ";;cout<<"\n";
		}
	}
	return 0;
}