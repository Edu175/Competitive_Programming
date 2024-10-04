#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll INF=1e5+5;
typedef ll tn; // node type
typedef ii tl; // lazy type
// tn unit(ll v){return v;}
#define NEUT 0
tl CLEAR={-1,INF}; // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	auto [l,r]=a;
	auto [l2,r2]=v;
	if(l2>=r)a={l2,l2};
	else if(r2<=l)a={r2,r2};
	else a={max(l,l2),min(r,r2)};
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	a=max(a,v.fst);
	a=min(a,v.snd);
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
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
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){ // range update
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
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
};
void buildWall(int n, int q, int op[], int l[], int r[], int h[], int ret[]){
	STree st(n);
	fore(i,0,q){
		r[i]++,op[i]--;
		tl v;
		if(op[i]==0)v={h[i],INF};
		else v={-1,h[i]};
		st.upd(l[i],r[i],v);
	}
	// fore(i,0,q){
	// 	fore(j,l[i],r[i]){
	// 		if(op[i]==1)a[j]=max(a[j],h[i]);
	// 		else a[j]=min(a[j],h[i]);
	// 	}
	// }
	fore(i,0,n)ret[i]=st.query(i,i+1);
}
