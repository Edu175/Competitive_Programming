#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e10;

vector<vv> mxs;
vv vergaps(set<ll> v, set<ll> r){
	if(!SZ(v))return {};
	vv ret;
	for(auto p=v.begin();p!=prev(v.end());p++){
		ll mx=0;
		auto q=next(p);
		vector<ll>in;
		in.pb(*p);
		for(auto it=r.lower_bound(*p);it!=r.end()&&*it<*q;it++){
			in.pb(*it);
		}
		in.pb(*q);
		fore(i,0,SZ(in)-1)mx=max(mx,in[i+1]-in[i]);
		mxs.back().pb(mx);
		ret.pb(*q-*p);
		// cerr<<mx<<" "<<*q-*p<<" gap\n";
	}
	return ret;
}

int main(){
	JET
	ll n; cin>>n;
	map<char,set<ll>>mp;
	fore(i,0,n){
		ll x; char c; cin>>x>>c;
		mp[c].insert(x);
	}
	ll res=0;
	ll s=INF,e=-INF;
	if(SZ(mp['G'])){
		s=*mp['G'].begin();
		e=*mp['G'].rbegin();
	}
	vv gaps;
	for(auto c:{'R','B'}){
		auto &st=mp[c];
		if(SZ(st)){
			ll l=*st.begin(),r=*st.rbegin();
			ll extra=max(s-l,0ll)+max(r-e,0ll);
			if(!SZ(mp['G']))extra=r-l;
			res+=extra;
			// cerr<<"extra "<<extra<<"\n";
		}
		mxs.pb({});
		gaps=vergaps(mp['G'],st);
	}
	fore(i,0,SZ(gaps)){
		res+=min(2*gaps[i],3*gaps[i]-mxs[0][i]-mxs[1][i]);
	}
	cout<<res<<"\n";
	return 0;
}