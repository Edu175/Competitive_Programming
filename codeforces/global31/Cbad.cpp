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
		ll n,k; cin>>n>>k;
		if(k&1){
			fore(i,0,k)cout<<n<<" ";
			cout<<"\n";
			continue;
		}
		vv res(k,n);
		ll &a=res[k-2];
		ll &b=res[k-1];
		a=b=0;
		a=1ll<<__lg(n);
		ll _n=n;
		n-=a;
		if(n)b=(2ll<<__lg(n))-1;
		a=_n^b;
		imp(res)
	}
	return 0;
}
