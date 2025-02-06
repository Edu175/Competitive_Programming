#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e17;

struct node{
	ll sum,maxp;
	node(ll v):sum(v),maxp(v){}
};
node oper(node a, node b){
	node c=a;
	c.maxp=max(a.maxp,a.sum+b.maxp);
	c.sum=a.sum+b.sum;
	return c;
}
node NEUT(0);
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=node(v);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
	ll get(){return query(0,n).maxp;}
};
void compose(vv &a, vv b){
	vv c(SZ(a));
	fore(i,0,SZ(c))c[i]=a[b[i]];
	a=c;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		ll fij=0;
		ll suma=0,sumb=0;
		fore(i,0,n)cin>>a[i]>>b[i],fij+=a[i],suma+=a[i],sumb+=b[i];
		vv per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){
			ll di=a[i]-b[i],dj=a[j]-b[j];
			if(di<0&&dj<0)return a[i]<a[j];
			if(di>=0&&dj>=0)return b[i]>b[j];
			return (di>=0)<(dj>=0);
		});
		// imp(per)
		compose(a,per);
		compose(b,per);
		// imp(a);
		// imp(b);
		STree st(2*n);
		fore(i,0,n)st.upd(2*i,a[i]),st.upd(2*i+1,-b[i]);
		ll res=INF;
		fore(i,0,n){
			ll can=sumb-b[i]>=suma;
			if(can){
				st.upd(2*i,0);
				st.upd(2*i+1,0);
				res=min(res,st.get());
				st.upd(2*i,a[i]),st.upd(2*i+1,-b[i]);
			}
		}
		if(res>=INF)cout<<"-1\n";
		else cout<<res+fij<<"\n";
	}
	return 0;
}
