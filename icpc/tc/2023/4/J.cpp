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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m,r,k; cin>>n>>m>>r>>k;
	vv a,b;
	fore(_,0,2){
		auto &v=(_?b:a);
		ll z=(_?m:n);
		ll mn=min(r,z+1-r);
		fore(__,0,2)fore(i,1,mn)v.pb(i);
		assert(SZ(v)<z);
		v.resize(z,mn);
		sort(ALL(v));
	}
	assert(SZ(a)==n&&SZ(b)==m);
	// show(a)
	// show(b)
	vv sp(m+1);
	fore(i,0,m)sp[i+1]=sp[i]+b[i];
	auto get=[&](ll v)->ii { // returns {cant,sum}, looks >= v
		ll cant=0,sum=0;
		for(auto x:a){
			ll y=(v+x-1)/x;
			ll p=lower_bound(ALL(b),y)-b.begin();
			cant+=m-p,sum+=(sp[m]-sp[p])*x;
		}
		// cerr<<"get "<<v<<": "<<cant<<"\n";
		return {cant,sum};
	};
	ll lo=-1,hi=1e12;
	while(hi-lo>1){
		ll h=(lo+hi)/2;
		if(get(h).fst>=k)lo=h;
		else hi=h;
	}
	ll v=lo;
	auto [cant,sum]=get(v);
	// cerr<<v<<" "<<cant<<" "<<sum<<"\n"<<"k "<<k<<"\n";
	sum-=v*(cant-k);
	// cerr<<"sum "<<sum<<"\n";
	ld res=sum/ld((n+1-r)*(m+1-r));
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
