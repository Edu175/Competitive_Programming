#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct node{
	ll m, f,g;
};
node oper(node a, node b){
	return {max(a.m,b.m),max(a.f,b.f),min(a.g,b.g)};
}
const ll INF=1e18;
#define NEUT (node){-1,-1,INF}
struct STree{
	int n; vector<node> t;
	STree(int n): n(n), t(2*n+5,NEUT) {}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}
	node query(int l, int r){
		node izq=NEUT, der=NEUT;
		for(l+=n,r+=n;l<r; l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n; cin>>n;
		ll a[n]; fore(i,0,n) cin>>a[i];
		ll rt=0;
		STree ST(n);
		fore(i,0,n){
			ST.upd(i,{a[i],i,i});
		}
		fore(i,0,n){
			rt+=min(ST.query(0,i+1).m,ST.query(i,n).m)-a[i];
		}
		
		ll q; cin>>q;
		while(q--){
			ll x,v; cin>>x>>v; x--;
			node f=ST.query(0,x+1), g=ST.query(x,n);
			if(f.m>f.g) swap(f,g);
			ll del=min(f.f-a[x],v);
			rt-=del;
			a[x]+=v;
			if(v>del){
				rt+=max(0ll,abs(g.g-x)-1)*(min(a[x],g.m)-f.m);
			}
			ST.upd(x,{a[x],x,x});
			cout<<rt<<"\n";
		}
	}
	return 0;
}