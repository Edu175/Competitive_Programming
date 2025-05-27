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

ll lgt(ll n){
	ll res=0;
	while(n>1)res++,n=(n+1)/2;
	return res;
}

ll solve(ll n, ll m){
	return lgt(n)+lgt(m);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a,b; cin>>a>>b; a--,b--;
		ll res=1+min({
			solve(a+1,m),
			solve(n-a,m),
			solve(n,b+1),
			solve(n,m-b),
		});
		cout<<res<<"\n";
	}
	return 0;
}
