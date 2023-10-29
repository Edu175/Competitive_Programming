#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll M=1e9+7;

#define oper min
struct ST{
	ll K,n; vector<vector<ll>>st; vector<ll>a;
	ST(ll n):K(64-__builtin_clzll(n)),n(n),st(K,vector<ll>(1ll<<K));
	ll oper(ll i, ll j){
		if(a[j]==a[i]){
			return min(i,j);
		}
		if(a[i]>a[j])return i;
		return j;
	}
	void init(vector<ll> _a){
		a=_a;
		ll n=SZ(a);
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
	}
	ll query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
		return oper(st[k][s],st[k][e-(1<<k)]);
	}
};
ST spa[2];
vector<vector<ll>>a;
ii NEUT={0,0};
#define CLEAR 0 // cleared lazy node
ii oper(ii i, ii j){
	if(a[i.snd][i.fst]==a[j.snd][j.fst]){
		return min(i,j);
	}
	if(a[i.snd][i.fst]>a[j.snd][j.fst])return i;
	return j;
}
void acum(ll &a, ll v){a^=v;} // accumulate lazy node
ll calc(ll s, ll e, ii a, ll v){
	ll w=a.snd^v;
	return {spa[w].query(s,e),w};
}
// calculate STree range, a=previous value

struct STree{
	vector<ii>st; vector<ll> lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ii query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ii query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		fore(i,0,2)spa[i]=ST(n);
		a.clear();
		a.resize(2,vector<ll>(n));
		fore(i,0,n)cin>>a[0][i],a[1][i]=M-a[0][i];
		fore(i,0,2)spa[i].init(a[i]);
		STree st(n);
		ll res=0;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			st.upd(l,r,1);
			ll resi=st.query(0,n);
			
		}
	}
	return 0;
}
