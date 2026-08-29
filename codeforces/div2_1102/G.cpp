#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct STree{
	struct node{ii mx; ll suf,pre; ll l,r;};
	node NEUT;
	node oper(node a, node b){
		if(a.l==-1)return b;
		if(b.l==-1)return a;
		// assert(a.r==b.l);
		node c;
		c.mx=max({a.mx,b.mx,ii({a.suf+b.pre,a.r-a.suf})});
		c.suf=(b.suf==b.r-b.l?b.suf+a.suf:b.suf);
		c.pre=(a.pre==a.r-a.l?a.pre+b.pre:a.pre);
		c.l=a.l;
		c.r=b.r;
		return c;
	}
	node unit(ll i, ll v){ // v is 0/1
		node c({{0,i},0,0,i,i+1});
		if(!v)c.mx.fst=c.suf=c.pre=1; // busco bloque de 0s
		return c;
	}
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5){NEUT.l=-1;}
	void upd(int p, ll v){
		int i=p;
		for(p+=n,t[p]=unit(i,v);p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		a.pb(0);
		STree st(n); // w=1
		priority_queue<ii> bars;
		fore(i,0,n)bars.push({n+1,i});
		ll isl=0;
		for(ll i=n;i>=0;i--){
			while(SZ(bars)){
				auto [mx,j]=bars.top();
				if(mx>i){ // i,j is losing in w=1
					st.upd(j,0);
					bars.pop();
				}
				else break;
			}
			while(1){
				auto [z,p]=st.query(0,n).mx;
				if(z<=a[i])break;
				// i,p is losing in w=0
				isl|=!i&&p==1;
				st.upd(p,1);
				bars.push({i-p,p});
			}
		}
		cout<<1+isl<<"\n";
	}
	return 0;
}
