#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef float ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=320;
// const ll B=2;

int main(){
	JET
	ll n; cin>>n;
	ld psum=0;
	vector<ld>np(n),p(n);
	vector<vv> g(n),gsq(n);
	vv is(n);
	fore(i,0,n){
		cin>>p[i];
		np[i]=1-p[i];
		psum+=p[i];
	}
	vector<ld> sum(n);
	ld tot=0;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		tot+=np[u]*np[v];
	}
	// auto recalc=[&](){ // debugging purposes
	// 	tot=0;
	// 	fore(x,0,n)for(auto y:g[x]){
	// 		tot+=np[x]*np[y];
	// 	}
	// 	tot/=2;
	// };
	fore(i,0,n)is[i]=SZ(g[i])>=B;
	fore(x,0,n)for(auto y:g[x])if(is[y])gsq[x].pb(y),sum[x]+=np[y];
	auto getsum=[&](ll x){
		if(is[x])return sum[x];
		ld s=0;
		for(auto y:g[x])s+=np[y];
		return s;
	};
	auto upd=[&](ll x, ld v){ // sumar v
		for(auto y:gsq[x])sum[y]+=v;
		np[x]+=v;
	};
	auto val=[&](ll u){return np[u]*getsum(u);};
	ll q; cin>>q;
	while(q--){
		ll i; ld v; cin>>i>>v;
		psum-=p[i];
		p[i]=v;
		psum+=p[i];
		// cout<<q<<": "<<i<<" "<<v<<endl;
		tot-=val(i);
		v=1-v;
		ld dif=v-np[i];
		upd(i,dif);
		tot+=val(i);
		// recalc();
		cout<<fixed<<setprecision(15);
		cout<<n-tot-psum<<"\n";
	}
	return 0;
}