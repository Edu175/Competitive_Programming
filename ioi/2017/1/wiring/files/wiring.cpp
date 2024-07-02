#include "wiring.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define forr(i,a,b) for(ll i=b-1,ioi=a;i>=ioi;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e15;

#define NEUT INF
#define oper min

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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

ll n,is[MAXN],d[MAXN];

long long min_total_length(vector<int> a, vector<int> b){
	vector<ii>h;
	for(auto i:a)h.pb({i,0});
	for(auto i:b)h.pb({i,1});
	sort(ALL(h));
	n=SZ(h);
	fore(i,0,n)is[i]=h[i].snd,d[i]=h[i].fst;
	vector<ll>l(n+1),r(n+1); r[n]=n;
	fore(i,0,n){
		if(!i||is[i]!=is[i-1])l[i]=i;
		else l[i]=l[i-1];
	}
	forr(i,0,n){
		if(i==n-1||is[i]!=is[i+1])r[i]=i+1;
		else r[i]=r[i+1];
	}
	vector<ll>sp(n+1);//,ps(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+d[i-1];
	// forr(i,0,n)ps[i]=ps[i+1]+d[i];
	STree small(n),big(n);
	vector<ll>abr(n+5,INF),cer(n+5,INF);
	abr[n]=0;
	// fore(i,0,n)cout<<i<<": "<<is[i]<<" "<<d[i]<<": "<<l[i]<<" "<<r[i]<<"\n";
	// imp(sp);
	forr(i,0,n){
		ll c=r[i]-i;
		ll sl=sp[r[i]]-sp[i]-(r[i]-i)*d[i];
		sl=(d[r[i]-1]-d[i])*c-sl;
		// ll sl=ps[i]-ps[r[i]]-
		ll dis=d[r[i]]-d[r[i]-1];
		ll s=r[i],m=r[i]+c,e=r[r[i]];
		m=min(m,e);
		
		ll go0=sl+dis*c+small.query(s,m);
		ll go1=sl-dis*r[i]+big.query(m,e);
		abr[i]=min(go0,go1);
		
		ll sr=sp[i+1]-sp[l[i]]-(i+1-l[i])*d[l[i]];
		cer[i]=sr+min(abr[i],abr[i+1]);
		
		small.upd(i,cer[i]);
		
		ll disl=d[l[i]]-(l[i]?d[l[i]-1]:0);
		big.upd(i,disl*(i+1)+cer[i]);
		
		// cout<<i<<":\n";
		// cout<<s<<" "<<m<<" "<<e<<" sme\n";
		// cout<<sl<<" "<<sr<<" sl,sr\n"<<go0<<" "<<go1<<" go\n"<<disl<<" "<<dis<<" dis\n"<<abr[i]<<" "<<cer[i]<<" abr,cer\n\n";
	}
	return abr[0];
}
