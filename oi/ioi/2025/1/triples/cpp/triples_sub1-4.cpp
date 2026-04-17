#include "triples.h"
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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

long long count_triples(vector<int> __h) {
	ll n=SZ(__h);
	vv h;
	fore(i,0,n)h.pb(__h[i]);
	
	ll fg=1;
	fore(i,0,n-1)fg&=h[i]<=h[i+1];
	
	// imp(h)
	set<vv> all;
	
	auto good=[&](vv s){
		assert(SZ(s)==3);
		vector<ll> ds,hs;
		fore(i,0,3)fore(j,i+1,3)ds.pb(abs(s[i]-s[j]));
		fore(i,0,3)hs.pb(h[s[i]]);
		sort(ALL(hs));
		sort(ALL(ds));
		// cerr<<"good?\n";
		// imp(ds)
		// imp(hs)
		// cerr<<"\n";
		return ds==hs;
	};
	
	auto eval=[&](ll i, ll j, ll k){
		// cerr<<"eval "<<i<<" "<<j<<" "<<k<<"\n";
		vv s={i,j,k}; sort(ALL(s));
		if(s[0]==s[1]||s[1]==s[2])return;
		if(s[0]<0||s[2]>=n)return;
		// cerr<<"passed "<<i<<" "<<j<<" "<<k<<"\n";
		if(good(s))all.insert(s);
	};
	
	auto doit=[&](ll i, ll j){
		// cerr<<"\n\ndoit "<<i<<" "<<j<<"\n";
		if(j<0||j>=n)return;
		vv ind={i,j};
		fore(wd,0,2)fore(wf,0,2)fore(ws,0,2){
			ll d=h[ind[wd]];
			ll f=ind[wf];
			ll s=ws?1:-1;
			ll k=f+s*d;
			eval(i,j,k);
		}
	};
	
	fore(i,0,n)doit(i,i+h[i]),doit(i,i-h[i]);
	if(fg)return SZ(all);
	
	// faltan las otras
	
	fore(i,0,n){
		ll b=h[i];
		fore(j,max(0ll,i-b+1),i){
			eval(j,i,j+b);
		}
	}
	
	return SZ(all);
}

vector<int> construct_range(int M, int K) {
  return {1, 1, 1};
}
