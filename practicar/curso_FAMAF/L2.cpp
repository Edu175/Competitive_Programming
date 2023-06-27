#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct node{
	ll g,q;
	node(ll g, ll q):g(g),q(q){}
	node(ll v):g(v),q(1){}
};
node oper(node a, node b){
	ll g=gcd(a.g,b.g);
	ll q=0;
	if(g==a.g)q+=a.q;
	if(g==b.g)q+=b.q;
	return node(g,q);
}
node NEUT=node(0,0);
struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=node(v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	STree st(n);
	fore(i,0,n)st.upd(i,a[i]);
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		node ans=st.query(l,r);
		ll res=(r-l)-ans.q;
		cout<<res<<"\n";
	}
	return 0;
}
