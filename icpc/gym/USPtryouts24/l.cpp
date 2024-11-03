#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct frac{
	ll n,d;
};
bool operator<(frac a, frac b){
	return a.n*b.d<b.n*a.d;
}
frac slope(ii a, ii b){ // abs
	frac r({abs(b.snd-a.snd),abs(b.fst-a.fst)});
	ll g=gcd(r.n,r.d);
	r.n/=g,r.d/=g;
	return r;
}
int main(){
	JET
	ll n,q; cin>>n>>q;
	multiset<frac>all;
	set<ii>st;
	auto add=[&](ii a){
		auto it=st.lower_bound(a);
		if(it!=st.end()&&it!=st.begin()){
			all.erase(all.find(slope(*prev(it),*it)));
		}
		if(it!=st.begin()){
			all.insert(slope(*prev(it),a));
		}
		if(it!=st.end()){
			all.insert(slope(a,*it));
		}
		st.insert(a);
	};
	auto erase=[&](ii a){
		st.erase(a);
		auto it=st.lower_bound(a);
		if(it!=st.end()&&it!=st.begin()){
			all.insert(slope(*prev(it),*it));
		}
		if(it!=st.begin()){
			all.erase(all.find(slope(*prev(it),a)));
		}
		if(it!=st.end()){
			all.erase(all.find(slope(a,*it)));
		}
	};
	fore(i,0,n){
		ii a; cin>>a.fst>>a.snd;
		add(a);
	}
	auto query=[&](){
		if(!SZ(all))cout<<"-1\n";
		else {
			auto r=*prev(all.end());
			cout<<r.n<<" "<<r.d<<"\n";
		}
	};
	query();
	while(q--){
		ll ty; cin>>ty;
		ii a; cin>>a.fst>>a.snd;
		if(ty==1)add(a);
		else erase(a);
		query();
	}
	return 0;
}