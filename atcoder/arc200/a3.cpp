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
const ll MX=1e8;
bool good(ii a, ii b){
	return (a.fst!=b.fst) &&
			(a.snd!=b.snd) &&
			((a.fst<b.fst)^(a.snd<b.snd));
}
ii getm(ii a, ii b){ // a < b en ratio
	b.fst*=MX; b.snd*=MX;
	ll k=b.fst/a.fst+1;
	return {k,MX};
}
ii getmV2(ii a, ii b){ // a < b en ratio
	a.fst*=MX; a.snd*=MX;
	ll k=a.snd/b.snd+1;
	return {MX,k};
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
			ll m0,m1;
			auto get=[&](auto f){
				auto [m0_,m1_]=f(a,b);
				m0=m0_,m1=m1_;
				auto _a=a,_b=b;
				a.fst*=m0; a.snd*=m0;
				b.fst*=m1; b.snd*=m1;
				cout<<"attempt\n";
				cout<<"a: "<<a.fst<<","<<a.snd<<"\n";
				cout<<"b: "<<b.fst<<","<<b.snd<<"\n";
				cout<<endl;
				if(!good(a,b)){
					cout<<"failed\n";
					a=_a,b=_b;
					return 0;
				}
				return 1;
			};
			if(!get(getm))get(getmV2);
			assert(good(a,b));
			ll i=per[0];
			ll j=per.back();
			if(a.fst<b.fst)m0*=-1;
			else m1*=-1;
			res[i]=m0; res[j]=m1;
			imp(res)
		}
	}
	return 0;
}
