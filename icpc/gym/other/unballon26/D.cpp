#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll tl;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
struct tn{ll r,s;};
tn NEUT({0,0});
#define CLEAR 0
tn oper(tn a, tn b){
	return {add(a.r,b.r),add(a.s,b.s)};
}
void acum(tl &a, tl v){
	a=add(a,v);
}
tn calc(tn a, tl v){
	a.r=add(a.r,mul(a.s,v));
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<array<ll,5>> qs(q);
	vv ts;
	fore(i,0,q){
		ll ty,l,r; cin>>ty>>l>>r; r++;
		ll k=-1,x=-1;
		if(ty==2)cin>>k>>x;
		qs[i]={ty,l,r,k,x};
		ts.pb(l);
		ts.pb(r);
	}
	fore(i,1,sqrt(n)+5){
		ts.pb(i);
		ts.pb(n/i+1);
	}
	sort(ALL(ts)); ts.resize(unique(ALL(ts))-ts.begin());
	ll k=SZ(ts);
	vv cant(k);
	fore(i,0,k)cant[i]=-n/ts[i];
	STree st(k);
	vector<tn> ini(k);
	fore(i,0,k)ini[i]={0,(i<k-1?(ts[i+1]-ts[i])%MOD:1)};
	st.init(ini);
	// show(ts)
	// show(cant)
	// for(auto i:ini)cout<<i.s<<" ";;cout<<"\n";
	for(auto [ty,l,r,k,x]:qs){
		// cerr<<ty<<" "<<l<<","<<r<<": ";
		ll s=lower_bound(ALL(ts),l)-ts.begin();
		ll e=lower_bound(ALL(ts),r)-ts.begin();
		if(ty==1){
			// cerr<<"query "<<s<<","<<e<<"\n";
			ll res=st.query(s,e).r;
			cout<<res<<"\n";
		}
		else {
			ll s2=lower_bound(ALL(cant),-k)-cant.begin();
			ll e2=upper_bound(ALL(cant),-k)-cant.begin();
			s=max(s,s2);
			e=min(e,e2);
			e=max(e,s);
			// cerr<<"upd "<<s<<","<<e<<" "<<x<<"\n";
			st.upd(s,e,x);
		}
	}
	return 0;
}
