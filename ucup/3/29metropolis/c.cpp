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
		ll l,r; cin>>l>>r;
		ll n=(r-l+1);
		if(l==r){
			cout<<"Alice\n";
			continue;
		}
		ll x=l+(l%2==0);
		ll win=0;
		if(l%2==0){
			if(n%2==0)win=1;
			else win=2*x<=r;
		}
		else {
			if(n&1)win=1;
			else win=2*x<=r;
		}
		// cerr<<win<<"\n";
		if(l%2==0)win^=1;
		if(win)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
