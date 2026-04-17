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
const ll C=700;

long long count_triples(vector<int> __h) {
	ll n=SZ(__h);
	vv h;
	fore(i,0,n)h.pb(__h[i]);
	
	ll fg=1;
	fore(i,0,n-1)fg&=h[i]<=h[i+1];
	
	set<vv> all;
	
	auto israre=[&](ll i, ll j, ll k){
		return h[i]==abs(j-k)&&h[j]==abs(i-k)&&h[k]==abs(i-j);
	};
	
	auto good=[&](vv s){
		assert(SZ(s)==3);
		vector<ll> ds,hs;
		fore(i,0,3)fore(j,i+1,3)ds.pb(abs(s[i]-s[j]));
		fore(i,0,3)hs.pb(h[s[i]]);
		sort(ALL(hs));
		sort(ALL(ds));
		return ds==hs;
	};
	
	auto eval=[&](ll i, ll j, ll k, bool allow=0){
		vv s={i,j,k}; sort(ALL(s));
		if(s[0]==s[1]||s[1]==s[2])return;
		if(s[0]<0||s[2]>=n)return;
		if(good(s)&&(allow||!israre(i,j,k)))all.insert(s);
	};
	
	auto doit=[&](ll i, ll j){
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
	
	auto hayk=[&](ll i, ll j){
		assert(h[i]-i==h[j]-j);
		ll k=i+h[j];
		return k<n&&h[k]==j-i;
	};
	
	auto hayi=[&](ll j, ll k){
		assert(h[j]+j==h[k]+k);
		ll i=k-h[j];
		return i>=0&&h[i]==k-j;
	};

	auto getj=[&](ll diag, ll k)->ll{ // -1 if none
		ll num=diag-h[k]+k;
		if(num&1)return -1;
		ll x=num/2,j=k-x;
		if(j<0||j>=k||h[j]!=h[k]+x)return -1;
		assert(h[j]-j==diag);
		return j;
	};
	
	// rares
	map<ll,vv> buc;
	fore(i,0,n){
		buc[h[i]-i].pb(i);
	}
	ll res=0;
	for(auto &[diag,vec]:buc){
		ll m=SZ(vec),c=0;
		if(m<C){
			fore(ind0,0,m)fore(ind1,ind0+1,m){
				ll i=vec[ind0],j=vec[ind1];
				c+=hayk(i,j);
			}
		}
		else {
			fore(k,0,n){
				ll j=getj(diag,k);
				if(j!=-1)c+=hayi(j,k);
			}
		}
		res+=c;
	}
	
	return SZ(all)+res;
}

vector<int> construct_range(int M, int K) {
	ll n=M;
	vector<int> a={};
    while(SZ(a)<n){
        ll v=SZ(a)+1;
        fore(i,0,v)a.pb(v-i);
    }
    while(SZ(a)>n||a.back()>=n)a.pop_back();
    return a;
}