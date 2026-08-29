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
	ll n,m; cin>>n>>m;
	vv oc(m);
	fore(i,0,n){
		ll x; cin>>x; x--;
		oc[x]++;
	}
	vv res;
	ll sum=0;
	for(ll i=m-1;i>=0;i--){
		sum+=oc[i]*(i+1);
		res.pb(sum);
	}
	reverse(ALL(res));
	show(res)
	return 0;
}
