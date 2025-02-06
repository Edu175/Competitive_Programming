#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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
const ll INF=1e7;
#define oper min
#define NEUT INF
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

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv bal(n+1);
	vv vals;
	fore(i,1,n+1)bal[i]=bal[i-1]+a[i-1],vals.pb(bal[i]);
	if(bal.back()<0){cout<<"-1\n";return 0;}
	sort(ALL(vals));
	auto get_idx=[&](ll v){return lower_bound(ALL(vals),v)-vals.begin();};
	STree st(SZ(vals));
	st.upd(get_idx(bal.back()),n);
	ll res=0;
	for(ll i=n-1;i>=0;i--){
		res=-i-1;
		auto r=st.query(get_idx(bal[i]),st.n);
		res+=r;
		// cout<<i<<": "<<r<<" = "<<res<<"\n";
		st.upd(get_idx(bal[i]),i+res);
	}
	cout<<res<<"\n";
	return 0;
}