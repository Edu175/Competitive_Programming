#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<cv(i)<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3*3e4+5;

ll val[MAXN];

const int N_DEL = 0, N_VAL = MAXN-1; //delta, value
inline int mOp(int x, int y){return x+y;}//modify
inline int qOp(int lval, int rval){//query
	return val[lval]>val[rval]?lval:rval;
}
inline int dOnSeg(int d, int len){return d==N_DEL ? N_DEL : d*len;}
//mostly generic
inline int joinD(int d1, int d2){
  if(d1==N_DEL)return d2;if(d2==N_DEL)return d1;return mOp(d1, d2);}
inline int joinVD(int v, int d){return d==N_DEL ? v : mOp(v, d);}
struct Node_t{
  int sz, nVal, tVal, d;
  bool rev;
  Node_t *c[2], *p;
  Node_t(int v) : sz(1), nVal(v), tVal(v), d(N_DEL), rev(0), p(0){
    c[0]=c[1]=0;
  }
  bool isRoot(){return !p || (p->c[0] != this && p->c[1] != this);}
  void push(){
    if(rev){
      rev=0; swap(c[0], c[1]);
      fore(x,0,2)if(c[x])c[x]->rev^=1;
    }
    nVal=joinVD(nVal, d); tVal=joinVD(tVal, dOnSeg(d, sz));
    fore(x,0,2)if(c[x])c[x]->d=joinD(c[x]->d, d);
    d=N_DEL;
  }
  void upd();
};
typedef Node_t* Node;

string cv(Node a){
	string s=to_string(ll(a));
	
	return SZ(s)<2?s:s.substr(SZ(s)-2);
}

int getSize(Node r){return r ? r->sz : 0;}
int getPV(Node r){
  return r ? joinVD(r->tVal, dOnSeg(r->d,r->sz)) : N_VAL;}
void Node_t::upd(){
  tVal = qOp(qOp(getPV(c[0]), joinVD(nVal, d)), getPV(c[1]));
  sz = 1 + getSize(c[0]) + getSize(c[1]);
}
void conn(Node c, Node p, int il){if(c)c->p=p;if(il>=0)p->c[!il]=c;}
void rotate(Node x){
  Node p = x->p, g = p->p;
  bool gCh=p->isRoot(), isl = x==p->c[0];
  conn(x->c[isl],p,isl); conn(p,x,!isl);
  conn(x,g,gCh?-1:(p==g->c[0])); p->upd();
}
void spa(Node x){//splay
  while(!x->isRoot()){
    Node p = x->p, g = p->p;
    if(!p->isRoot())g->push();
    p->push(); x->push();
    if(!p->isRoot())rotate((x==p->c[0])==(p==g->c[0])? p : x);
    rotate(x);
  }
  x->push(); x->upd();
}
Node exv(Node x){//expose
  Node last=0;
  for(Node y=x; y; y=y->p)spa(y),y->c[0]=last,y->upd(),last=y;
  spa(x);
  return last;
}
void mkR(Node x){exv(x);x->rev^=1;}//makeRoot
Node getR(Node x){exv(x);while(x->c[1])x=x->c[1];spa(x);return x;}
Node lca(Node x, Node y){exv(x); return exv(y);}
bool connected(Node x, Node y){exv(x);exv(y); return x==y?1:x->p!=0;}
void cut(Node x, Node y){mkR(x); exv(y); y->c[1]->p=0; y->c[1]=0;}
Node father(Node x){
	exv(x);
	Node r=x->c[1];
	if(!r)return 0;
	while(r->c[0])r=r->c[0];
	return r;
}
void cut(Node x){ // cuts x from father keeping tree root
	exv(father(x));x->p=0;}
int query(Node x, Node y){mkR(x); exv(y); return getPV(y);}
void modify(Node x, Node y, int d){mkR(x);exv(y);y->d=joinD(y->d,d);}
Node lift_rec(Node x, int t){
	if(!x)return 0;
	if(t==getSize(x->c[0])){spa(x);return x;}
	if(t<getSize(x->c[0]))return lift_rec(x->c[0],t);
	return lift_rec(x->c[1],t-getSize(x->c[0])-1);
}
Node lift(Node x, int t){ // t-th ancestor of x (lift(x,1) is x's father)
	exv(x);
	auto ret=lift_rec(x,t);
	// cout<<"lift "<<cv(x)<<" "<<t<<": "<<cv(ret)<<"\n";
	return ret;}
int depth(Node x){ // distance from x to its tree root
	exv(x);return getSize(x)-1;}

void link(Node x, Node y){
	// cout<<"link "<<cv(x)<<" "<<cv(y)<<endl;
	mkR(x);
	// lift(x,1);
	x->p=y;
}

int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){
	JET
	ll NEUT=0;
	val[MAXN-1]=NEUT;
	ll t; cin>>t;
	while(t--){
		ll n,m,q; cin>>n>>m>>q;
		uf_init();
		vector<pair<ll,ii>>ed;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({w,{u,v}});
		}
		sort(ALL(ed));
		fore(i,0,n)val[i]=NEUT;
		vector<Node> xs(n+m+q);
		fore(i,0,n+m+q)xs[i]=new Node_t(i);
		// imp(xs);
		fore(i,0,m)val[n+i]=ed[i].fst;
		ll res=0;
		fore(i,0,m){
			auto [w,ar]=ed[i];
			auto [x,y]=ar;
			if(uf_join(x,y)){
				link(xs[x],xs[n+i]);
				link(xs[n+i],xs[y]);
				res+=w;
				// cout<<x<<" "<<y<<" "<<i<<" linked"<<endl;
			}
		}
		auto unlink=[&](Node a, Node b){
			// cout<<"unlink "<<cv(a)<<" "<<cv(b)<<endl;
			// cout<<"padre de a: "<<cv(lift(a,1))<<endl;
			// cout<<"padre de b: "<<cv(lift(b,1))<<endl;
			mkR(a);
			cut(b);
			// if(lift(a,1)==b)cut(a);
			// else {
			// 	cout<<"padre de a: "<<cv(lift(a,1))<<endl;
			// 	cout<<"padre de b: "<<cv(lift(b,1))<<endl;
			// 	auto pingo=lift(b,1);
			// 	while(pingo!=a);
			// 	cut(b);
			// }
		};
		fore(i,0,q){
			ll x,y,w; cin>>x>>y>>w; x--,y--;
			assert(x!=y);
			ed.pb({w,{x,y}});
			val[n+m+i]=w;
			ll idx=query(xs[x],xs[y]);
			if(w<ed[idx-n].fst){
				auto [u,v]=ed[idx-n].snd;
				// cout<<x<<" "<<y<<" "<<m+i<<" linked, sacando "<<idx-n<<" osea "<<u<<" "<<v<<endl;
				unlink(xs[idx],xs[u]);
				unlink(xs[idx],xs[v]);
				
				link(xs[x],xs[n+m+i]);
				link(xs[n+m+i],xs[y]);
				res+=w-ed[idx-n].fst;
			}
			cout<<res<<"\n";
		}
		fore(i,0,n+m+q)delete xs[i];
	}
	return 0;
}