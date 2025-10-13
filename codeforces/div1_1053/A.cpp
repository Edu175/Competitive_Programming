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
		ll n,m; cin>>n>>m;
		string op; cin>>op;
		set<ll>bl,wh; // wh s.t. i-1 is bl
		auto agr=[&](ll i){ // bl
			wh.erase(i);
			if(!bl.count(i+1))wh.insert(i+1);
			bl.insert(i);
		};
		auto go=[&](ll s, ll i){
			if(op[i]=='A'||!bl.count(s+1))return s+1;
			return *wh.upper_bound(s);
		};
		fore(i,0,m){
			ll p; cin>>p;
			agr(p);
		}
		ll au;
		fore(i,0,n){
			ll nu=(i?go(au,i-1):1);
			ll now=go(nu,i);
			agr(now);
			au=nu;
		}
		cout<<SZ(bl)<<"\n";
		for(auto i:bl)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}
