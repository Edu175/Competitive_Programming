#include "obstacles.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=2e5+5,MAXH=3*MAXN;

ll n,m;
// ll cv(ii a){return a.fst*m+a.snd;}
// ii cv(ll a){return {a/m,a%m};}

vv t,h;

bool allowed(ll i, ll j){
	if(i<0||i>=n)return 0;
	if(j<0||j>=m)return 0;
	return t[i]>h[j];
}

const ll K=18;
struct STable{
	ll ty;
	ii oper(ii a, ii b){
		if(ty)return max(a,b);
		return min(a,b);
	}
	ii st[K][MAXN];
	STable(){}
	STable(vv a, ll _ty){
		ll n=SZ(a); ty=_ty;
		fore(i,0,n)st[0][i]={a[i],i};
		fore(k,1,K){
			fore(i,0,n){
				ll p=i+(1ll<<(k-1));
				if(p<n)st[k][i]=oper(st[k-1][i],st[k-1][p]);
			}
		}
	};
	ii query(ll s, ll e){
		ll k=__lg(e-s);
		return oper(st[k][s],st[k][e-(1ll<<k)]);
	}
};
STable stmin,stmax;
void initialize(vector<int> T, vector<int> H) {
	n=SZ(T),m=SZ(H);
	fore(i,0,n)t.pb(T[i]);
	fore(i,0,m)h.pb(H[i]);
	ll fg=1;
	fore(i,0,n-1)fg&=t[i]<=t[i+1];
	if(fg){
		n=1;
		t={t.back()};
	}
	stmin=STable(h,0);
	stmax=STable(h,1);
	
	return;
}

bool good(ll i, ll j){return allowed(i,j);}

ll getl(ll j, auto cond){
	ll l=-1,r=j+1;
	while(r-l>1){
		ll m=(l+r)/2;
		if(cond(m,j))r=m;
		else l=m;
	}
	return r; // [
}
ll getr(ll j, auto cond){
	ll l=j-1,r=m;
	while(r-l>1){
		ll m=(l+r)/2;
		if(cond(j,m))l=m;
		else r=m;
	}
	return l; // ]
}
vector<ii> getvec(ll j){ // hj mas chico
	vector<ii> ret;
	ll s=j,e=j; // [,]
	fore(i,0,n){
		auto cond_good=[&](ll l, ll r){ // [,]
			return stmax.query(l,r+1).fst<t[i]; // todos good
		};
		auto cond_bad=[&](ll l, ll r){ // [,]
			return stmin.query(l,r+1).fst>=t[i]; // ninguno good
		};
		
		if(good(i,e))e=getr(e,cond_good);
		else e=getl(e,cond_bad)-1;
		
		if(good(i,s))s=getl(s,cond_good);
		else s=getr(s,cond_bad)+1;
		
		ret.pb({s,e});
		// cerr<<i<<": "<<s<<","<<e<<" final\n\n"; 
	}
	return ret;
}

bool can_reach(int L, int R, int S, int D) {
	if(S>D)swap(S,D);
	auto lhs=getvec(S);
	auto rhs=getvec(D);
	fore(i,0,n){
		auto [l,r]=lhs[i];
		auto [s,e]=rhs[i];
		if(l>r||s>e)break;
		// cerr<<l<<","<<r<<" "<<s<<","<<e<<"\n";
		assert(l<=s&&r<=e);
		if(s<=r)return 1;
	}
	return 0;
}
