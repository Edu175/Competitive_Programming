#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef ii tn;
typedef ll tl;

const ll inf  = 1e17;
#define NEUT {inf,0}
#define CLEAR 0

tn oper(tn a, tn b){
	if(a.fst == b.fst)return{a.fst,a.snd+b.snd};
	if(a.fst < b.fst) return a;
	return b;
}
void acum(tl &a, tl v){a+=v;}
tn calc(tn a, tl v){
	a.fst+=v;
	return a;
}
struct STree{
	vector<tn> st; vector<tl> lazy; int n;
	STree(int n):st(4*n+5,NEUT), lazy(4*n+5,CLEAR), n(n){}
	void init(int k, int s, int e){
		if(e-s == 1)st[k] = {0,1};
		else{
			int m = (s+e)/2;
			init(2*k,s,m); init(2*k+1,m,e);
			st[k] = oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k , int s, int e){
		if(lazy[k] == CLEAR) return;
		st[k] = calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k] = CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){
		push(k,s,e);
		if(e<=a||b<=s) return;
		if(a<=s && e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m = (s+e)/2;
		upd(2*k,s,m,a,b,v), upd(2*k+1,m,e,a,b,v);
		st[k] = oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a || b<=s)return NEUT;
		push(k,s,e);
		if(a<=s && e<=b) return st[k];
		int m = (s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(){init(1,0,n);}
};

map<ll,vv> mp;
ll ng;
void f(int x, int k, STree &st, int v){
	ll n = SZ(mp[x]);
	if(n < k) return;
	ll l = mp[x][n-k], r = n>k ? mp[x][n-k-1] : ng;
	// cout<<x<<" "<<l<<" "<<r<<endl;
	assert(l<=r);	
	st.upd(l,r,v);
}


int main(){
	JET
	ll n,k; cin>>n>>k;
	ng = n;
	vv a;
	fore(i,0,n){
		ll x; cin>>x;
		mp[x].pb(i);
		a.pb(x);
	}
	STree st(n);
	st.init();
	// fore(i,0,n)cout<<st.query(i,i+1).fst<<" "<<st.query(i,i+1).snd<<"\n";
	// cout<<"-------------------\n";
	for(auto &[x,v]:mp){
		reverse(ALL(v));
		f(x,k,st,1);
	}
	// for(auto [x,v]:mp){
		// cout<<x<<": ";
		// show(v);
	// }
	// cout<<endl;
	ll res = 0;
	fore(i,0,n){
		ll x = a[i];
		auto [m,cnt] = st.query(i,n);
		// cout<<m<<" "<<cnt<<"\n";
		res += (!m)*cnt;
		f(x,k,st,-1);
		mp[x].pop_back();
		f(x,k,st,1);	
		// cout<<res<<"\n";		
	}
	cout<<res<<"\n";
	return 0;
}