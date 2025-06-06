#include "deliveries.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll n,tot=1; //extra zero (return)
ll w[MAXN],t[MAXN];
ll sp[MAXN];
ll getw(ll s, ll e){return sp[e]-sp[s];}

void range(ll &pv, ll v, ll s, ll e, ll t){
	if(t==0)pv+=(e-s)*v;
	else pv+=getw(s,e)*v;
}

struct STree{
	vector<ll>st,lazy; ll n,t;
	STree(){}
	void init(ll ni, ll ti){
		st.resize(4*ni+5),lazy.resize(4*ni+5),n=ni,t=ti;
	}
	void push(ll k, ll s, ll e){
		//st[k]+=(e-s)*lazy[k];
		range(st[k],lazy[k],s,e,t);
		if(s+1!=e){
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			lazy[k]+=v;
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);
		upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1];
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return 0;
		ll m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

STree c,cw;

void init(int N, std::vector<int> u, std::vector<int> v, std::vector<int> W, std::vector<int> T) {
	n=N;
	fore(i,0,SZ(u)){
		w[v[i]]=W[i];
	}
	fore(i,0,n)t[i]=T[i],tot+=t[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+w[i-1];
	c.init(n,0),cw.init(n,1);
	fore(i,0,n)c.upd(0,i+1,t[i]),cw.upd(0,i+1,t[i]);
	/*fore(i,0,n)cout<<c.query(i,i+1)<<" ";
	cout<<"\n";*/
}

long long max_time(int x, int v) {
	ll d=v-t[x];
	tot+=d;
	t[x]+=d;
	c.upd(0,x+1,d);
	cw.upd(0,x+1,d);
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(c.query(m,m+1)*2>tot)l=m+1;
		else r=m-1;
	}
	ll izq=0,der=0;
	if(r<n-1)der=cw.query(r+1,n);
	if(r>0)izq=tot*getw(1,r+1)-cw.query(1,r+1);
	cout<<x<<" "<<v<<"\n"<<r<<"\n"<<izq<<" "<<der<<": "<<izq+der<<"\n\n";
	return izq+der;
}
