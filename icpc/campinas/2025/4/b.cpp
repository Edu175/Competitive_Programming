#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;

ii unit(ll od, ll v){
	if(od)return {0,v};
	return {v,0};
}
ii oper(ii a, ii b){return {(a.fst+b.fst)%MOD,(a.snd+b.snd)%MOD};}
struct STree{
	vector<ii>t; ll n;
	STree(ll n):t(2*n+5,{0,0}),n(n){}
	void upd(ll p, ii v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1){
			t[p>>1]=oper(t[p],t[p^1]);
		}
	}
	ii query(ll l, ll r){
		ii res={0,0};
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
ll dame(ii a, ll b){
	if(b)return a.snd;
	return a.fst;
}
int main(){
	JET
	ll n; cin>>n;
	vv r(n+1),d(n+1);
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		if(a[i]&1)a[i]+=MOD;
	}
	vv sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	vv vals;
	fore(i,0,n+1){
		r[i]=sp[i]%MOD;
		d[i]=sp[i]/MOD;
		vals.pb(r[i]);
	}
	sort(ALL(vals));
	auto get_idx=[&](ll v){
		return lower_bound(ALL(vals),v)-vals.begin();
	};
	STree st(SZ(vals));
	ll res=0;
	for(ll i=n;i>=0;i--){
		ll p=get_idx(r[i]);
		ll fg=d[i]&1;
		if(i==n)res=1;
		else {
			res=dame(st.query(p,st.n),fg)+dame(st.query(0,p),fg^1);
			res%=MOD;
		}
		st.upd(p,unit(fg,res));
	}
	cout<<res<<"\n";
	return 0;
}