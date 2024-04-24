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
	ll l,r,q;
};
node oper(node a, node b){
	if(a.l==-1)return b;
	if(b.l==-1)return a;
	node c=a;
	c.r=b.r;
	c.q+=b.q-(a.r&&b.l);
	return c;
}
node NEUT=node({-1,-1,-1});
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
	ll n; cin>>n;
	vector<ll>a(n);
	vector<vector<ll>>pos(100005);
	ll v=0;
	fore(i,0,n)cin>>a[i],v=max(a[i],v),pos[a[i]].pb(i);
	v++;
	vector<ll>qs(v);
	STree st(n);
	fore(i,0,n)st.upd(i,node({1,1,1}));
	fore(i,0,v){
		for(auto j:pos[i])st.upd(j,node({0,0,0}));
		qs[i]=st.query(0,n).q;
	}
	vector<ll>res(v);
	fore(k,1,v){
		for(ll j=0;j<v;j+=k)res[k]+=qs[j];
	}
	fore(i,1,v)cout<<res[i]<<" ";;cout<<"\n";
	return 0;
}

