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

ll k;
vv a;
ll f(ll i, ll d){
	while(i!=SZ(a)&&d>=a[i])i++;
	if(i==SZ(a))return 0;
	return 1+min(f(i,d+k),f(i,a[i]));
}

ll solve(vv _a){
	a=_a;
	sort(ALL(a));
	return f(0,0);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		vv a;
		fore(i,0,n){
			ll x; cin>>x;
			a.pb(x);
			cout<<solve(a)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
