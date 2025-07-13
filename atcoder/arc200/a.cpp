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
random_device rd;
mt19937 rng(rd());
bool good(ii a, ii b){
	return (a.fst!=b.fst) &&
			(a.snd!=b.snd) &&
			((a.fst<b.fst)^(a.snd<b.snd));
}
ii operator*(ll t, ii a){return {a.fst*t,a.snd*t};}

ii getm(ii a, ii b){ // a < b en ratio
	ll m=rng()%MX+1;
	b=m*b;
	ll k=b.fst/a.fst+1;
	return {k,m};
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
			ll i=per[0],j=per.back();
			ll dbg=0;
			while(1){
				auto [m0,m1]=getm(a,b);
				auto a_=a;
				auto b_=b;
				a_=m0*a;
				b_=m1*b;
				++dbg;
				// cerr<<"attempt "<<++dbg<<"\n";
				// cerr<<a_.fst<<","<<a_.snd<<"\n";
				// cerr<<b_.fst<<","<<b_.snd<<"\n";
				if(good(a_,b_)){
					m1*=-1;
					res[i]=m0; res[j]=m1;
					break;
				}
			}
			cerr<<"attempts: "<<dbg<<"\n";
			imp(res)
		}
	}
	return 0;
}
