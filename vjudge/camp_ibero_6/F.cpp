#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll INF=1e5;

struct node{
	ll res,pre,suf,sum;
	node(ll a):res(a),pre(a),suf(a),sum(a){}
	node(){}
};
node oper(node a, node b){ // a left, b right
	node p;
	p.res=max({a.res,b.res,a.suf+b.pre});
	p.pre=max(a.pre,a.sum+b.pre);
	p.suf=max(b.suf,a.suf+b.sum);
	p.sum=a.sum+b.sum;
	return p;
}
node NEUT=node(-INF);
struct STree{
	vector<node>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=node(v);return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	node query(ll a, ll b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	
 
int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	STree st(n);
	fore(i,0,n)cin>>a[i],st.upd(i,a[i]);
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty;
		if(!ty){
			ll k,v; cin>>k>>v; k--;
			st.upd(k,v);
		}
		else{
			ll l,r; cin>>l>>r; l--;
			cout<<st.query(l,r).res<<"\n";
		}
	}
	return 0;
}
