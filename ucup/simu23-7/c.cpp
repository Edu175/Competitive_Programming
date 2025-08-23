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
void link(Node x, Node y){mkR(x); x->p=y;}
void cut(Node x, Node y){mkR(x); exv(y); y->c[1]->p=0; y->c[1]=0;}
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
	
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		n++;
		ll m=2*n+5;
		vector<Node> a(m),b(m);
		
		fore(i,0,m)a[i] = new Node_t(1);
		fore(i,0,m)b[i] = new Node_t(0);
		
		// init
		fore(i,0,m)link(a[i],b[i]);
		fore(i,0,m-1)link(b[i],b[i+1]);
		// ll mx=0;
		
		auto fle=[&](ll p){
			// cout<<"flecha "<<p<<" "<<p+k<<"\n";
			// assert(p+k<n);
			cut(a[p],b[p]);
			link(a[p],a[p+k]);
		};
		
		set<ll> st;
		fore(i,0,n)st.insert(i);
		fore(i,0,n-1){
			ll p; cin>>p;
			// mx=max(mx,p);
			
			cut(b[p-1],b[p]);
			link(b[p-1],a[p]);
			for(auto it=st.lower_bound(p);it!=st.begin();){
				ll q=*prev(it);
				if(q+k<p)break;
				fle(q);
				st.erase(prev(it));
			}
			
			ll res=query(a[0],b[m-1]);
			cout<<res-1<<" ";
			// cout<<"res\n\n";
		}
		cout<<"\n";
		
	}
	return 0;
}
