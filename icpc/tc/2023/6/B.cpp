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
	ll a,b,x; cin>>a>>b>>x;
	ll sw=0;
	if(a<b)swap(a,b),sw=1;
	vv c={a,b};
	ll p=0;
	vv res;
	ll prim=1;
	while(x>1){
		// cout<<x<<": "<<p<<" "<<c[p]<<"\n";
		res.pb(p);
		c[p]--;
		x-=!prim; prim=0;
		p^=1;
	}
	p^=1;
	while(c[p]>0)res.pb(p),c[p]--;
	p^=1;
	while(c[p]>0)res.pb(p),c[p]--;
	for(auto i:res)cout<<(i^sw);
	cout<<"\n";
	return 0;
}
