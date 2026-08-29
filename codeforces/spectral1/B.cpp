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

ll solve(vv a, ll k){
	for(auto &i:a)i=-i;
	sort(ALL(a));
	ll sum=accumulate(ALL(a),0ll);
	fore(i,0,min(k,(ll)SZ(a))){
		if(i&&a[i]>=0)break;
		sum-=a[i];
	}
	return -sum;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> a(2);
		fore(i,0,n){
			ll x; cin>>x;
			a[i&1].pb(x);
		}
		vv c(2);
		fore(i,0,m){
			ll x; cin>>x; x--;
			c[x&1]++;
		}
		ll res=solve(a[0],c[0])+solve(a[1],c[1]);
		cout<<res<<"\n";
	}
	return 0;
}
