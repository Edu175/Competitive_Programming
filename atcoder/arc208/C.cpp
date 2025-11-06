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
		ll c,x; cin>>c>>x;
		ll res=-1;
		auto cand=[&](ll n){
			if(n<=0)return;
			if((n^c)%n==x)res=n;
		};
		cand(c^x);
		cand((1ll<<(__lg(c)+1))+(c-x)/2);
		cout<<res<<"\n";
	}
	return 0;
}
