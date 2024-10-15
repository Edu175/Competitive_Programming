#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct node{
	ll val,pre;
	node(ll v):val(v),pre(v){}
};
node NEUT(0);
node oper(node a, node b){
	node c=a;
	c.val+=b.val;
	c.pre=min(c.pre,a.val+b.pre);
	return c;
}
struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)
			p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

int main(){
	JET
	ll n,q; cin>>n>>q;
	vector<ll>b(n),c(n);
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)cin>>c[i];
	STree st(2*n);
	auto upd=[&](ll i){
		st.upd(i,b[i]-c[i]);
		st.upd(i+n,b[i]-c[i]);
	};
	fore(i,0,n)upd(i);
	while(q--){
		ll ty,p; cin>>ty>>p; p--;
		if(ty==1){
			ll l=p,r=n+p;
			while(l<=r){
				ll m=(l+r)/2;
				if(st.query(p,m+1).pre<0)r=m-1;
				else l=m+1;
			}
			if(l>=n+p)l=-2;
			if(l>=n)l-=n;
			cout<<l+1<<"\n";
		}
		else {
			ll v; cin>>v;
			if(ty==2)b[p]=v;
			else c[p]=v;
			upd(p);
		}
	}
	return 0;
}