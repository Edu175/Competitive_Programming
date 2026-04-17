#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET 
	ll n,k; cin>>n>>k;
	vv a(n);
	vv vals;
	fore(i,0,n){
		cin>>a[i];
		vals.pb(a[i]);
		vals.pb(a[i]+k);
	}
	sort(ALL(vals));
	vals.resize(unique(ALL(vals))-vals.begin());
	auto get_idx=[&](ll v){
		ll p=lower_bound(ALL(vals),v)-vals.begin();
		assert(p<SZ(vals)&&vals[p]==v);
		return p;
	};
	vv curs(SZ(vals)),mns=curs,oc=curs;
	
	for(auto v:a)oc[get_idx(v)]++;
	
	ll ans=0;
	fore(i,0,n){
		ll v=a[i];
		fore(ty,0,2-(k==0)){
			ll p=ty?get_idx(v+k):get_idx(v);
			auto &cur=curs[p];
			auto &mn=mns[p];
			auto fij=oc[p];
			cur+=ty?1:-1;
			mn=min(mn,cur);
			ans=max(ans,fij+cur-mn);
			// cerr<<i<<": "<<cur<<" "<<mn<<" "<<fij<<"\n";
		}
	}
	cout<<ans<<"\n";
	return 0;
}