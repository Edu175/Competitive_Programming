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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree
<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)

pair<pair<ld,ld>,ll> solve(ll a, ll b, ll c){
	ll del=b*b-4*a*c;
	if(del<=0)return {{-1,-1},0};
	ld x1=(-b-sqrtl(del))/(2.*a);
	ld x2=(-b+sqrtl(del))/(2.*a);
	return {{x1,x2},1};
}

pair<pair<ld,ld>,ll> inter(ll a, ll b, ll m, ll c){
	return solve(a,-m,b-c);
}

const ld EPS=1e-13;

int main(){FIN;
	ll n,A,B; cin>>n>>A>>B;
	vector<ii> ps(n);
	fore(i,0,n)cin>>ps[i].fst>>ps[i].snd;
	vector<pair<ld,ld>> da;
	fore(i,0,n){
		auto [par,good]=inter(A,B,ps[i].fst,ps[i].snd);
		if(good)da.pb(par);
	}
	
	//compress
	vector<ld> vals;
	for(auto [a,b]:da)vals.pb(a),vals.pb(b);
	sort(ALL(vals));
	auto _vals=vals; vals.clear();
	for(auto i:_vals)if(!SZ(vals)||abs(vals.back()-i)>EPS)vals.pb(i);
	auto get_idx=[&](ld x){
		return lower_bound(ALL(vals),x-EPS)-vals.begin();
	};
	vector<ii> a;
	for(auto [l,r]:da){
		// cout<<l<<","<<r<<": ";
		l=get_idx(l);
		r=get_idx(r);
		a.pb({l,r});
		// cout<<l<<","<<r<<"\n";
	}
	// done
	
	ll m=SZ(vals);
	vector<vv> pon(m),sac(m);
	fore(i,0,SZ(a)){
		auto [l,r]=a[i];
		pon[l].pb(i);
		sac[r].pb(i);
	}
	indexed_set<ii> st;
	ll res=0;
	fore(t,0,m){
		for(auto i:sac[t])st.erase({a[i].fst,i});
		for(auto i:sac[t]){
			ll cur=SZ(st)-st.order_of_key({a[i].fst,SZ(a)+5});
			res+=cur;
			// cout<<i<<": "<<cur<<"\n";
		}
		for(auto i:pon[t])st.insert({a[i].fst,i});
	}
	cout<<res<<"\n";
	return 0;
}