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

struct STree{
	vector<ll>st; ll n;
	STree (ll n):st(4*n+5),n(n){}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]+=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=st[2*k]+st[2*k+1];
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return 0;
		ll m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	/*ll find(ll k, ll s, ll e, ll x){
		if(s+1==e){
			if(st[k]>=x)return s;
			return -1;
		}
		if(st[2*k])>=
	}*/
	void upd(ll p, ll v){query(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

ll n;
ll tot=1; //extra zero (return)
ll w[MAXN],t[MAXN];
ll sp[MAXN];
ll getw(ll s, ll e){return sp[e]-sp[s];}
STree st;

void init(int N, std::vector<int> u, std::vector<int> v, std::vector<int> W, std::vector<int> T) {
	n=N;
	fore(i,0,SZ(u)){
		w[v[i]]=W[i];
	}
	fore(i,0,n)t[i]=T[i],tot+=t[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+w[i-1];
	st(n);
	fore(i,0,n)st.upd(i,t[i]*w[i]);
}

long long max_time(int x, int v) {
	tot+=v-t[x];
	st.upd(x,v-t[x]);
	t[x]=v;
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st.query(m,n)*2>tot)l=m+1;
		else r=m-1;
	}
	ll izq=0,der=0;
	if(r<n-1)der=st.query(r+1,n);
	if(r>0)izq=getw
	return ;
}
