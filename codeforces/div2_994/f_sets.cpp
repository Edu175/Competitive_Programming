#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
struct item{
	priority_queue<ll>pq;
	set<ll>no;
	ll mex=0;
	item(ll v){
		// for(auto i:v)pq.push(i);
		pq.push(v);
		go();
	};
	void go(){while(pq.top()==mex)pq.pop(),mex++;}
	ll get(){return SZ(no)?*no.begin():mex;}
};
typedef item* pitem;
pitem merge(pitem a, pitem b){
	if(!b)return a;
	if(!a)return b;
	if(SZ(a->pq)<SZ(b->pq))swap(a,b);
	while(SZ(b->pq))a->pq.push(b->pq.top()),b->pq.pop();
	a->go();
	return a;
}
ll n;
struct dat{
	set<ll>st;
	pitem h[MAXN];
	ll k,cum[MAXN];
	dat(vv a, ll k):k(k){
		pitem p=0;
		fore(i,0,n)cum[i]=a[i]>=(1ll<<k);
		fore(i,0,n){
			if(!cum[i]){
				p=merge(p,new item(a[i]));
				if(i==n-1||cum[i+1])st.insert(i),h[i]=p;
			}
			else p=0;
		}
	}
	void upd(ll p, ll v){
		if(cum[p]&&)
	}
};


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
