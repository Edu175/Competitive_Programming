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
typedef pair<ll,ll> ii;

struct node{
	ll pre,suf,l,r,all,res;
	node(ll v):pre(1),suf(1),l(v),r(v),all(1),res(1){}
	node(){}
};
//void prnt(node a){cout<<"["<<a.pre<<","<<a.suf<<"|"<<a.l<<","<<a.r<<"|"<<a.all<<"="<<a.res<<"] ";}
node oper(node a, node b){
	if(a.l==-1)return b;
	if(b.l==-1)return a;
	node c;
	c.res=max(a.res,b.res);
	ll ig=a.r==b.l;
	if(ig)c.res=max(c.res,a.suf+b.pre);
	c.l=a.l; c.r=b.r;
	c.pre=a.pre; c.suf=b.suf;
	if(a.all&&ig)c.pre+=b.pre;
	if(b.all&&ig)c.suf+=a.suf;
	c.all=ig&&a.all&&b.all;
	//cout<<"oper "; prnt(a); prnt(b); cout<<"= "; prnt(c); cout<<"\n";
	return c;
	
}
node NEUT(-1);
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
	string s; cin>>s;
	ll n=SZ(s);
	STree st(n);
	vector<ll>a(n);
	fore(i,0,n)a[i]=s[i]-'0',st.upd(i,a[i]);
	ll q; cin>>q;
	while(q--){
		ll p; cin>>p; p--;
		a[p]^=1;
		st.upd(p,a[p]);
		//imp(a);
		cout<<st.query(0,n).res<<" ";
	}
	cout<<"\n";
	return 0;
}
