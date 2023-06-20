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
typedef int ll;
typedef pair<ll,ll> ii;

struct node{
	ll sum,pre,suf,all;
	ll sum1,pre1,suf1;
	node(ll a):sum(a),pre(a),suf(a),all(a),sum1(a),pre1(a),suf1(a){}
	node(){}
};
node oper(node a, node b){ // a left, b right
	node p;
	p.all=a.all+b.all;
	p.sum=max({a.sum,b.sum,a.suf+b.pre});
	p.pre=max(a.pre,a.all+b.pre);
	p.suf=max(b.suf,a.suf+b.all);
	
	p.sum1=min({a.sum1,b.sum1,a.suf1+b.pre1});
	p.pre1=min(a.pre1,a.all+b.pre1);
	p.suf1=min(b.suf1,a.suf1+b.all);
	return p;
}
node rev(node a){
	swap(a.pre,a.suf);
	swap(a.pre1,a.suf1);
	return a;
}
node NEUT=node(0);
/*struct STree{
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
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	*/
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=node(a[i]);
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
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
};
const ll MAXN=2e5+5;
vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
node query(int x, int y, STree& rmq){
	node l=NEUT,r=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]]){
			l=oper(rmq.query(pos[head[x]],pos[x]+1),l);
			x=dad[head[x]];
		}
		else {
			r=oper(rmq.query(pos[head[y]],pos[y]+1),r);
			y=dad[head[y]];
		}
	}
	if(dep[x]>dep[y]){
		l=oper(rmq.query(pos[y],pos[x]+1),l);
	}
	else {
		r=oper(rmq.query(pos[x],pos[y]+1),r);	// *
	}
	return oper(rev(l),r);
}
struct qu{
	ll u,v,k;
	qu(ll u, ll v, ll k):u(u),v(v),k(k){}
	qu(){}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>q;
		vector<ll> a={1};
		vector<qu> qs;
		fore(i,0,q){
			char ty; cin>>ty;
			if(ty=='+'){
				ll p,w; cin>>p>>w; p--;
				g[p].pb(SZ(a));
				g[SZ(a)].pb(p);
				a.pb(w);
			}
			else {
				ll u,v,k; cin>>u>>v>>k; u--,v--;
				qs.pb(qu(u,v,k));
			}
		}
		hld_init();
		ll n=SZ(a);
		STree st(n);
		vector<ll>v(n);
		fore(i,0,n)v[pos[i]]=a[i];
		st.init(v);
		//fore(i,0,n)st.upd(pos[i],a[i]);
		fore(i,0,SZ(qs)){
			ll u=qs[i].u,v=qs[i].v,k=qs[i].k;
			ll r=query(u,v,st).sum;
			ll l=query(u,v,st).sum1;
			if(l<=k&&k<=r)cout<<"YES\n";
			else cout<<"NO\n";
		}
		fore(i,0,n){
			g[i].clear();
		}
	}
	return 0;
}
