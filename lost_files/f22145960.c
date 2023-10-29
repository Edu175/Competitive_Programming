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
const ll INF=1e10; 
struct node{
	ll l=0,r=0,res=0,is=0,sz=0; // is = all 1?
	node(ll v):l(0),r(0),res(0),is(0),sz(1){
		if(v==1){
			l=1,r=1,res=1,is=1;
		}
	}
	node(){}
};
node operc(node a, node b){
	if(a.is==-1)return b;
	if(b.is==-1)return a;
	node c;
	if(a.is)c.l=a.sz+b.l;
	else c.l=a.l;
	if(b.is)c.r=a.r+b.sz;
	else c.r=b.r;
	c.res=max({c.l,c.r,a.res,b.res,a.r+b.l});
	c.is=(a.is&&b.is);
	c.sz=a.sz+b.sz;
	return c;
}
node NEUT(0);
struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1){
			p^=p&1;
			t[p>>1]=operc(t[p],t[p^1]);
		}
	}
	node query(ll l, ll r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=operc(izq,t[l++]);
			if(r&1)der=operc(t[--r],der);
		}
		return operc(izq,der);
	}
};

int main(){FIN;
	NEUT.is=-1;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<ll>a(n);
		fore(i,0,n)a[i]=s[i]-'0';
		vector<ll>sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		STree st(n);
		fore(i,0,n)st.upd(i,a[i]);
		vector<ll>mxd(n+1);
		mxd[0]=st.query(0,n).res;
		fore(l0,1,n+1){
			ll &res=mxd[l0];
			res=-INF;
			fore(s,0,n){
				ll e=s+l0;
				if(e>n)break;
				if(sp[e]-sp[s]>k)continue;
				res=max(st.query(0,s).res,st.query(e,n).res);
			}
		}
		imp(mxd);
		fore(j,1,n+1){
			ll res=0;
			fore(l0,0,n+1)res=max(res,l0*j+mxd[l0]);
			cout<<res<<" ";
		}
		cout<<"\n";
		
	}
	return 0;
}
