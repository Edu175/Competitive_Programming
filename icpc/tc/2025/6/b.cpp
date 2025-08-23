#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int N_DEL = 0, N_VAL = 0; //delta, value
inline int mOp(int x, int y){return x+y;}//modify
inline int qOp(int lval, int rval){return lval + rval;}//query
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
// ll dbg=0;
// string cv(Node t){
// 	string s=;
// }
void link(Node x, Node y){
	// if(dbg)cerr<<"link "<<x<<" "<<y<<"\n";
	mkR(x); x->p=y;}
void cut(Node x, Node y){
	// if(dbg)cerr<<"cut "<<x<<" "<<y<<"\n";
	mkR(x); exv(y); y->c[1]->p=0; y->c[1]=0;}
Node father(Node x){
	exv(x);
	Node r=x->c[1];
	if(!r)return 0;
	r->push();
	while(r->c[0])r=r->c[0],r->push();
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
	exv(x);return lift_rec(x,t);}
int depth(Node x){ // distance from x to its tree root
	exv(x);return getSize(x)-1;}

// a contains b?
bool cont(ii a, ii b){return a.fst<=b.fst&&b.snd<=a.snd;}
struct Cmp{
	bool operator()(const ii &a, const ii &b)const{
		auto c=a; c.snd*=-1;
		auto d=b; d.snd*=-1;
		return c<d;
	}
};
const ll V=6e5+100;
int main(){
	JET
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].snd++;
	set<ii,Cmp>st;
	vector<Node> u(V),d(V);
	fore(i,0,V)u[i]=new Node_t(1);
	fore(i,0,V)d[i]=new Node_t(0);
	
	fore(i,0,V-1)link(u[i],d[i+1]);
	fore(i,0,V-1)link(d[i],d[i+1]);
	
	// no hay ranges con mismo l o r
	auto agr=[&](ii a){
		auto [l,r]=a;
		st.insert(a);
		
		cut(u[l],d[l+1]);
		link(u[l],d[r]);
		
		cut(d[l],d[l+1]);
		link(d[l],u[l]);
	};
	
	// no hay ranges con mismo l o r
	auto rem=[&](ii a){
		auto [l,r]=a;
		st.erase(a);
		
		cut(u[l],d[r]);
		link(u[l],d[l+1]);
		
		cut(d[l],u[l]);
		link(d[l],d[l+1]);
	};
	
	ll ant;
	for(auto i:a){
		auto it=st.lower_bound(i);
		if(it!=st.end()&&cont(i,*it)){
			cout<<ant<<"\n";continue;
		}
		
		while(it!=st.begin()&&cont(*prev(it),i))rem(*prev(it));
		
		agr(i);
		
		ant=query(u[0],d[V-1]);
		ant--;
		cout<<ant<<"\n";
		
	}
	return 0;
}