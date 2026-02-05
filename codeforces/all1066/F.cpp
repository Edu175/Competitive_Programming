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

const ll B=63;

int main(){FIN;
	ll n; cin>>n;
	vv all(n-1); iota(ALL(all),1);
	vector<ii> ops;
	ll cost=0;
	auto agr=[&](ll y, ll l){
		if(SZ(ops)&&y>ops.back().fst)cost+=1000;
		cost+=l;
		ops.pb({y,l});
	};
	for(ll m=1;m<=n;m*=B){
		ll mi=m*B; // /m%B
		vector<ii> ids;
		vv prox;
		for(auto i:all){
			ll p=i/m%B;
			if(p==B-1)prox.pb(i);
			else ids.pb({p,-i});
		}
		sort(ALL(ids));
		for(auto [p,i]:ids){
			i=-i;
			agr(i,m);
		}
		swap(prox,all);
	}
	cerr<<"cost: "<<cost<<"\n";
	cout<<SZ(ops)<<"\n";
	for(auto [y,l]:ops)cout<<y<<" "<<l<<"\n";
	// cout<<endl;
	assert(cost<=1e6);
	return 0;
}
