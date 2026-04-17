#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v).sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

#define NEUT 0
#define oper max

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)
			t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){ET;
	ll n; cin>>n;
	vv ys;
	map<ii,ll>mp;
	fore(i,0,n){
		ll x,y,d; cin>>x>>y>>d;
		mp[{x,-y}]+=d;
		ys.pb(y);
	}
	auto zip=[&](vv &a){
		sort(ALL(a));
		auto ai=a;
		a.clear();
		for(auto i:ai)if(!SZ(a)||i!=a.back())a.pb(i);
	};
	auto idx=[&](vv &a, ll x){
		return lower_bound(ALL(a),x)-a.begin();
	};
	zip(ys);
	vector<ii> a;
	for(auto [ar,v]:mp){
		a.pb({idx(ys,-ar.snd),v});
	}
	ll res=NEUT;
	STree st(SZ(ys));
	for(auto [x,v]:a){
		ll resi=st.query(0,x)+v;
		st.upd(x,resi);
		res=max(res,resi);
	}
	cout<<res<<"\n";
}