#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll a[MAXN];
#define NEUT2 0
#define oper2(a,b) ((a)+(b))
struct STree2{
	int n; vector<ll>t;
	STree2(int n):n(n),t(2*n+5,NEUT2){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper2(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT2;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper2(res,t[l++]);
			if(r&1)res=oper2(res,t[--r]);
		}
		return res;
	}
};
STree2 sum(0);

struct node{
	ll res,s,e; vector<ll>l,r;
	node(ll i):res(-1),s(i),e(i+1),l(1,i),r(1,i){}
};
node NEUT(-1);
node oper(node a, node b){
	if(a.s==-1)return b;
	if(b.s==-1)return a;
	node c=a;
	c.res=max(c.res,b.res);
	c.r=b.r; c.e=b.e;
	// a.r 
}

struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p){ // update array a first
		for(p+=n;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n)cin>>a[i];
		sum=STree2(n);
		fore(i,0,n)sum.upd(i,a[i]);
		
		while(q--){
			ll ty,l,r; cin>>ty>>l>>r; l--;
			if(ty==1){
				cout<<f(l,r,f)<<"\n";
			}
			else {
				a[l]=r;
				sts.upd(l,r);
				stm.upd(l,l);
			}
			
		}
	}
	return 0;
}