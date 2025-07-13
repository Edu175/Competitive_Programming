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
const ll C=1e8;
bool good(ii a, ii b){
	return 	(a.fst!=b.fst) &&
			(a.snd!=b.snd) &&
			((a.fst<b.fst)^(a.snd<b.snd));
}
bool dom(ii a, ii b){
	return a.fst>=b.fst&&a.snd>=b.snd;
}
// ii getm(ii a, ii b){ // != ratio
// 	ll m=lcm(a.fst,b.fst);
// 	if(m<C)m=(C/m+1)*m;
// 	ll m0=m/a.fst;
// 	ll m1=m/b.fst;
// 	a.fst*=m0; a.snd*=m0;
// 	b.fst*=m1; b.snd*=m1;
// 	assert(b.snd!=a.snd);
// 	// cout<<"getm\n";
// 	// cout<<"a: "<<a.fst<<","<<a.snd<<"\n";
// 	// cout<<"b: "<<b.fst<<","<<b.snd<<"\n";

// 	if(b.snd<a.snd)return {m0,m1+1};
// 	return {m0+1,m1};
// }
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator*(ll t, ii a){return {a.fst*t,a.snd*t};}
ii getm(ii a, ii b){
	auto _a=a,_b=b;
	ll m0=1,m1=1;
	ll dbg=0;
	while(!good(a,b)){
		++dbg;
		if(dom(b,a)){
			ll k=b.fst/_a.fst+1;
			m0=k;
			a=m0*_a;
		}
		else {
			ll k=a.snd/_b.snd+1;
			m1=k;
			b=m1*_b;
		}
	}
	cerr<<"attempts: "<<dbg<<"\n";
	return {m0,m1};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>h(n);
		fore(i,0,n)cin>>h[i].fst;
		fore(i,0,n)cin>>h[i].snd;
		auto _h=h;
		auto cmp=[&](ii a, ii b){
			return a.fst*b.snd<b.fst*a.snd;
		};
		sort(ALL(h),cmp);
		auto a=h[0],b=h.back();
		if(!cmp(a,b))cout<<"No\n";
		else {
			cout<<"Yes\n";
			vv res(n);
			vv per(n); iota(ALL(per),0);
			sort(ALL(per),[&](ll i, ll j){
				return cmp(_h[i],_h[j]);
			});
			auto [m0,m1]=getm(a,b);
			ll i=per[0];
			ll j=per.back();
			a.fst*=m0; a.snd*=m0;
			b.fst*=m1; b.snd*=m1;
			cout<<"a: "<<a.fst<<","<<a.snd<<"\n";
			cout<<"b: "<<b.fst<<","<<b.snd<<"\n";
			cout<<endl;
			assert(a.fst!=b.fst);
			assert(a.snd!=b.snd);
			assert((a.fst<b.fst)^(a.snd<b.snd));
			if(a.fst<b.fst)m0*=-1;
			else m1*=-1;
			res[i]=m0; res[j]=m1;
			imp(res)
		}
	}
	return 0;
}
