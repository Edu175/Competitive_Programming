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
const ll INF=(1e9+5)*2;
struct node{
	ll mx,mn,res;
	node(ll v):mx(v),mn(v),res(0){}
};
node oper(node a, node b){
	node c=a;
	c.res=max({a.res,b.res,a.mx-b.mn});
	c.mx=max(a.mx,b.mx);
	c.mn=min(a.mn,b.mn);
	return c;
}
node NEUT(0);
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
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
	NEUT.mx=-INF,NEUT.mn=INF;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		vector<STree> st(2,STree(n));
		auto upd=[&](ll i){
			fore(w,0,2)st[w].upd(i,(w?-1:1)*a[i]+i);
		};
		auto query=[&](){
			ll res=0;
			fore(w,0,2)res=max(res,st[w].query(0,n).res);
			cout<<res<<"\n";
		};
		fore(i,0,n)cin>>a[i],upd(i);
		query();
		while(q--){
			ll p,v; cin>>p>>v; p--;
			a[p]=v;
			upd(p);
			query();
		}
	}
	return 0;
}
