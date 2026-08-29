#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n; n<<=1;
	ll fij=0;
	vv a(n),c(n);
	map<ll,deque<ll>> mp;
	fore(i,0,n){
		ll ai,bi,ci; cin>>ai>>bi>>ci;
		fij+=ai;
		a[i]=bi-ai;
		c[i]=ci;
		mp[c[i]].pb
	}
	return 0;
}
