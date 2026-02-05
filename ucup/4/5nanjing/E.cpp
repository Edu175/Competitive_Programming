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
typedef ll node;
typedef ll tn; // node type
typedef ll tl; // lazy type
#define NEUT 0
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a+=v;
	return a;
}
struct STree{
	int n,N;
	vector<tn>st; vector<tl>lazy;
	ll ty;
	STree(){}
	STree(int n, ll ty):n(n),N(2<<__lg(n)),st(2*N+5,NEUT),lazy(2*N+5,CLEAR),ty(ty){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1){
			if(s<n)st[k]=a[s];
		}
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void get(int k, int s, int e, vector<tn> &a){
		push(k,s,e);
		if(e-s==1){
			a.pb(st[k]);
			return;
		}
		int m=(s+e)/2;
		get(2*k,s,m,a); get(2*k+1,m,e,a);
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,N,p,v);}
	void upd(int a, int b, tl v){upd(1,0,N,a,b,v);}
	tn query(int a, int b){return query(1,0,N,a,b);}
	void init(vector<tn>&a){init(1,0,N,a);}
	void pos(ll l, ll r, ll v){upd(l,r,v*ty);} // suma 1 al pos
	void fij(ll l, ll r){upd(l,r,1);} // suma 1 al fij
	void append(tn v){
		if(n==N){
			vector<tn> a;
			get(1,0,N,a);
			N+=N;
			st=vector<tn>(2*N+5,NEUT);
			lazy=vector<tl>(2*N+5,CLEAR);
			init(a);
		}
		assert(n<N);
		upd(n++,v);
	}
};

struct node{
	vector<STree> st;
	ll z;
	node(){}
};

const ll MAXN=4e5+5;
vv g[MAXN];
ll col[MAXN],ans[MAXN];
ll cnt=0;

node dfs(ll x, ll fa){
	
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			ans[i]=-1;
		}
		fore(i,0,n){
			char c; cin>>c;
			col[i]=c-'0';
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		st[0]=STree(n,1);
		st[1]=STree(n,-1);
		st[2]=STree(n,3);
		st[3]=STree(n,-3);
		cnt=0;
		
	}
	return 0;
}
