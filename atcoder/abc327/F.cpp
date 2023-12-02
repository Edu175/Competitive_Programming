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
const ll MAXN=2e5+5;

#define NEUT 0
#define CLEAR 0 // cleared lazy node
#define oper max
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+v;
} 

struct STree{
	vector<ll>st,lazy; ll n;
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
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};
ll h,w;
STree st(MAXN);

void upd(ll y, ll v){
	st.upd(max((ll)0,y-h+1),y+1,v);
	//cout<<(v==1?"add ":"rem ")<<y<<"\n";
}

int main(){FIN;
	ll n; cin>>n>>h>>w;// h++,w++;
	vector<vector<ll>>a(MAXN);
	fore(i,0,n){
		ll x,y; cin>>y>>x;
		a[x].pb(y);
	}
	ll res=0;
	//cout<<0<<":\n";
	fore(i,0,w)for(auto j:a[i])upd(j,1);
	res=st.query(0,MAXN);
	//cout<<res<<"\n\n";
	fore(i,w,MAXN){
		//if(i<20)cout<<i<<":\n";
		for(auto j:a[i])upd(j,1);
		for(auto j:a[i-w])upd(j,-1);
		res=max(res,st.query(0,MAXN));
		//if(i<20)cout<<st.query(0,MAXN)<<"\n\n";
	}
	cout<<res<<"\n";
	return 0;
}
