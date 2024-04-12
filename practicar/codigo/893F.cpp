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
typedef int ll;
typedef pair<ll,ll> ii;
const ll INF=1e9+5;
#define oper(a,b) min(a,b)
#define NEUT INF
struct STree { // persistent segment tree for min over integers
	vector<int> st, L, R; int n,sz,rt;
	STree(int n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	int new_node(int v, int l=0, int r=0){
		int ks=SZ(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	int init(int s, int e, vector<int>a){ // not necessary in most cases
		if(s+1==e)return new_node(a[s]);
		int m=(s+e)/2,l=init(s,m,a),r=init(m,e,a);
		return new_node(oper(st[l],st[r]),l,r);
	}
	int upd(int k, int s, int e, int p, int v){
		int ks=(k?k:new_node(st[k],L[k],R[k]));
		if(s+1==e){st[ks]=min(st[ks],v);return ks;}
		int m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	int query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	int init(vector<int>&a){return init(0,n,a);}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);} // update on last root
	int query(int k,int a, int b){return query(k,0,n,a,b);};
	ll query(int a, int b){return query(rt,0,n,a,b);};
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);
struct STree2d{
	int n; vector<STree>t;
	STree2d(int n):n(n),t(2*n+5,STree(n)){}
	void upd(int p, int q, ll v){
		for(p+=n;p;p>>=1)t[p].upd(q,v);
	}
	ll query(int l, int r, int s, int e){
		ll res=INF;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=min(res,t[l++].query(s,e));
			if(r&1)res=min(res,t[--r].query(s,e));
		}
		return res;
	}
};
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll a[MAXN],S[MAXN],E[MAXN],D[MAXN];
ll cnt=0;
void dfs(ll x, ll f){
	S[x]=cnt++;
	for(auto y:g[x])if(y!=f){
		D[y]=D[x]+1;
		dfs(y,x);
	}
	E[x]=cnt;
}
int main(){FIN;
	ll n,rt; cin>>n>>rt; rt--;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(rt,-1);
	STree2d st(n);
	fore(x,0,n)st.upd(S[x],D[x],a[x]);
	ll q,last=0; cin>>q;
	while(q--){
		ll p,q; cin>>p>>q;
		ll x=(p+last)%n,k=(q+last)%n;
		last=st.query(S[x],E[x],D[x],min(D[x]+k+1,n));
		//cout<<x<<" "<<k<<": "<<S[x]<<","<<E[x]<<" "<<D[x]<<","<<min(D[x]+k,n)<<" = ";
		cout<<last<<"\n";
	}
	return 0;
}
