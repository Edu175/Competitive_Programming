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
const ll INF=1e18;
struct node{
	ll sum,suf;
	node(ll p, ll v):sum(v),suf(p){}
};
node oper(node a, node b){
	a.suf+=b.sum;
	a.suf=min(a.suf,b.suf);
	a.sum+=b.sum;
	return a;
}
node NEUT(INF,0);
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){ // +=
		ll _p=p; p+=n;
		t[p]=node(_p,t[p].sum+v);
		for(;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
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
	ll n; cin>>n;
	STree st(n+1);
	fore(i,0,n)st.upd(i,0);
	fore(i,0,n){
		ll p; cin>>p;
		st.upd(min(abs(p),n),p/abs(p));
		auto rq=st.query(0,n+1);
		cout<<rq.suf<<" ";
	}
	cout<<"\n";
	return 0;
}