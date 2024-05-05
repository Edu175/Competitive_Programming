#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;
typedef ll node;
#define oper min
#define NEUT MAXN
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
#define BLOCKSZ sqrt(n)+5
struct BL{ // O(1) upd, O(sqrt(n)) sum queries
	ll n,sq,q; vector<ll>a,sum;
	//sq=block size, q=number of blocks
	BH(ll n):n(n),sq(BLOCKSZ),q((n+sq-1)/sq),a(n),sum(q){}
	void clear(){
		fore(i,0,n)a[i]=sum[i/sq]=0;
	}
	void upd(ll p, ll v){//add v
		a[p]+=v;
		sum[p/sq]+=v;
	}
	ll query(ll l, ll r){
		ll res=0;
		if(l/sq==r/sq){
			fore(i,l,r)res+=a[i];
			return res;
		}
		fore(i,l,l/sq*sq+sq)res+=a[i];
		fore(i,r/sq*sq,r)res+=a[i];
		fore(i,l/sq+1,r/sq)res+=sum[i];
		return res;
	}
};
ll exl[MAXN];
struct qu{ll l,r,idx;}
ll n,sq,nq;
qu qs[MAXN];
bool cmp(const qu &a, const qu &b){
	return (a.l/sq==b.l/sq?a.r<b.r:a.l<b.l);
}
void mos(){
	sort(qs,qs+nq,cmp);
	ll l=0,r=0;
	BL b(n);
	fore(i,0,nq){
		auto q=qs[i];
		if(q.r<r)b.clear(),l=r=0;
		while(r<q.r)b.upd(exl[])
	}
}
int main(){FIN;
	cin>>n>>nq;
	vector<ll>a(n),h(n),b;
	fore(i,0,n)cin>>a[i]>>h[i];
	STree st(n);
	fore(i,0,n){
		ll p=upper_bound(a,a+n,a[i]-h[i])-a;
		ll res=min(i,st.query(p,i));
		exl[i]=res;
		st.upd(i,res);
	}
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		qs[i]={l,r,i};
	}
	
	return 0;
}
