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
#define DBG(x)cerr<<#x<<": "<<x<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
ll n,m;
vv a;
ll res=0;
ll romb=0,est=0,dob=0,ari=0,uno=0,esp=0,other=0;
ll ppc(ll x){return __builtin_popcountll(x);}
set<set<ll>>esps;
void doit(){
	res++;
	set<ll>st;
	for(auto i:a)st.insert(i);
	if(SZ(st)==1)uno++;
	if(SZ(st)==2){
		auto a=*st.begin();
		auto b=*st.rbegin();
		if(ppc(a^b)==2)dob++;
		else ari++;
	}
	ll did=0;
	if(SZ(st)==4){
		set<ll>mks;
		for(auto i:st)for(auto j:st)mks.insert(i^j);
		ll mk=*mks.rbegin();
		ll fg=ppc(mk)==2;
		for(auto i:mks)fg&=(i|mk)==mk;
		if(fg)did=1,romb++;
	}
	ll did2=0;
	fore(i,0,1ll<<m){ // i es el centro
		ll fg=1;
		for(auto j:st)fg&=ppc(i^j)<=1;
		if(fg)assert(!did),est++,did2=1;
	}
	ll did3=0;
	if(SZ(st)==4){
		ll fg=1;
		set<set<ll>>sts;
		for(auto i:st){
			set<ll>s;
			for(auto j:st)s.insert(i^j),fg&=ppc(i^j)==2||ppc(i^j)==0;
			sts.insert(s);
		}
		fg&=SZ(sts)==1;
		if(fg){
			if(did||did2){
				cerr<<did<<" "<<did2<<"\n";
				imp(*sts.begin());
				imp(a);
				imp(st);
				cout<<endl;
			}
			assert(!did&&!did2),esp++,did3=1;
			esps.insert(st);
		}
		// ll fg=1;
		// for(auto i:st)for(auto j:st)if(i!=j)fg&=ppc(i^j)==2;
		// if(fg){
		// 	if(did||did2){
		// 		cerr<<did<<" "<<did2<<"\n";
		// 		imp(a);
		// 		imp(st);
		// 		cout<<endl;
		// 	}
		// 	assert(!did&&!did2),esp++,did3=1;
		// }
	}
	if(!did&&!did2&&!did3){
		imp(a);
		imp(st);
		cout<<endl;
		other++;
	}
	assert(did||did2||did3);
}
void f(){
	if(SZ(a)==n){doit();return;}
	fore(v,0,1ll<<m){
		ll fg=1;
		for(auto i:a)fg&=ppc(i^v)<=2;
		if(fg){
			a.pb(v);
			f();
			a.pop_back();
		}
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		f();
		DBG(romb)
		DBG(est)
		DBG(dob)
		DBG(ari)
		DBG(uno)
		DBG(esp)
		DBG(other)
		DBG(SZ(esps))
		cout<<res<<"\n";
	}
	return 0;
}
