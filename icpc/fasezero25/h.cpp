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
	ll num; cin>>num;
	ll n=__lg(num)+1;
	vv vis(n);
	ll x=0;
	// cerr<<n<<"\n";
	ll did=0;
	for(ll i=n-1;i>=0;i--)if(!vis[i]){
		if(!did)n=i+1;
		ll xi=x|(1ll<<i)|(1ll<<(n-1-i));
		if(xi<=num)x=xi,did=1;
		if(did)vis[i]=vis[n-1-i]=1;
	}
	cout<<x<<"\n";
	return 0;
}
