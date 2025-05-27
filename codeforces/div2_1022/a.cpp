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
		vv a(n); iota(ALL(a),0);
		ll mx=0;
		fore(_,0,n){
			ll sum=0;
			fore(i,0,n)sum+=abs(a[i]-i);
			mx=max(mx,sum);
			rotate(a.begin(),a.begin()+1,a.end());
		}
		// cout<<mx<<": ";
		assert(mx%2==0);
		cout<<mx/2+1<<"\n";
	}
	return 0;
}
