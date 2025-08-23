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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=320;
// const ll B=2;
string cv(ll v){
	string s;
	s=to_string(v);
	s.insert(SZ(s)-2,1,'.');
	return s;
}
ll cv(string s){
	return 100*(s[0]-'0')+10*(s[2]-'0')+(s[3]-'0');
}
int main(){
	JET
	ll n; cin>>n;
	ll psum=0;
	vector<ll>np(n),p(n);
	vector<vv> g(n),gsq(n);
	vv is(n);
	fore(i,0,n){
		string s; cin>>s;
		p[i]=cv(s);
		np[i]=100-p[i];
		psum+=p[i];
	}
	vector<ll> sum(n);
	ll tot=0;
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
		ll s=0;
		for(auto y:g[x])s+=np[y];
		return s;
	};
	auto upd=[&](ll x, ll v){ // sumar v
		for(auto y:gsq[x])sum[y]+=v;
		np[x]+=v;
	};
	auto val=[&](ll u){return np[u]*getsum(u);};
	ll q; cin>>q;
	while(q--){
		ll i; string s; cin>>i>>s;
		ll v=cv(s);
		psum-=p[i];
		p[i]=v;
		psum+=p[i];
		// cout<<q<<": "<<i<<" "<<v<<endl;
		tot-=val(i);
		v=100-v;
		ll dif=v-np[i];
		upd(i,dif);
		tot+=val(i);
		// recalc();
		// cout<<fixed<<setprecision(15);
		// fore(i,0,n)cout<<p[i]<<","<<np[i]<<" ";;cout<<": ";
		cout<<cv(n*100-tot/100-psum)<<"\n";
	}
	return 0;
}