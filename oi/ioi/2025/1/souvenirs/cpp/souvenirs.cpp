#include "souvenirs.h"
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

vv a;
struct conju{
	ll sum=0,l=-1;
	vector<int> ind;
	conju(vector<int> v, ll sum):sum(sum),ind(v){l=ind[0];}
	bool operator<(const conju& rhs) const {
		return l<rhs.l;
	}
	ll get() const {
		ll k=SZ(ind);
		return (sum+k-1)/k - 1;
	}
	ll back(){return ind.back();}
	void pop(){sum-=a[ind.back()],ind.pop_back();}
};

vv hist;
conju llama(ll s){
	auto [v,r]=transaction(s);
	for(auto i:v)hist[i]++;
	return conju(v,s-r);
}

priority_queue<conju> mata(priority_queue<conju> _pq, ll p){
	priority_queue<conju> pq;
	while(SZ(_pq)){
		auto c=_pq.top(); _pq.pop();
		if(c.back()==p)c.pop();
		if(SZ(c.ind))pq.push(c);
	}
	return pq;
}

void buy_souvenirs(int N, long long P0) {
	ll n=N;
	hist.resize(n);
	priority_queue<conju> pq;
	ll R=n-1;
	a=vv(n,-1);
	
	auto cut=[&](conju &c){
		while(c.back()>R)c.pop();
	};
	
	pq.push(llama(P0-1));
	while(R>=1){
		assert(SZ(pq));
		auto c=pq.top();
		if(c.l==R){
			a[R]=c.sum;
			pq=mata(pq,R);
			R--;
		}
		else {
			ll x=c.get();
			auto ci=llama(x);
			assert(c.l<ci.l&&ci.l<=R);
			cut(ci);
			pq.push(ci);
		}
	}
	
	fore(i,0,n){
		fore(_,0,i-hist[i])llama(a[i]);
	}
	
	return;
}
