#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,cuca=b;i<cuca;i++)
#define SZ(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
mt19937 rng(175);
struct node{ll res,sum;};
node oper(node a, node b){
	a.res=max(a.res,a.sum+b.res);
	a.sum+=b.sum;
	return a;
}
node NEUT({0,0});

typedef struct item *pitem;
struct item {
	int pr,cnt; pitem l,r,f;
	ll a,b; node val;
	item(ll a, ll b): pr(rng()),cnt(1),l(0),r(0),f(0),a(a),b(b),val({a,b}) {}
};
int cnt(pitem t){return t?t->cnt:0;}
node val(pitem t){return t?t->val:NEUT;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		t->val=oper(val(t->l), node({t->a,t->b}));
		t->val=oper(t->val, val(t->r));
	}
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),l->r->f=t=l;
	else merge(r->l,l,r->l),r->l->f=t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){
	if(!t){l=r=0;return;}
	if(sz<=cnt(t->l)){
		split(t->l,l,t->l,sz);r=t;
		if(l)l->f=0;
		if(t->l)t->l->f=t;
	}
	else {
		split(t->r,t->r,r,sz-1-cnt(t->l));l=t;
		if(r)r->f=0;
		if(t->r)t->r->f=t;
	}
	upd_cnt(t);
}
vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN],len[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y); wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN],E[MAXN];
void hld(int x, int c){
	if(c<0)c=x,len[c]=0;
	pos[x]=curpos++;head[x]=c; int mx=-1; len[c]++;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
	E[x]=curpos;
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}

enum {ASSIGN_A_IF,ADD_B};
bool bypass;
void upd_sing(pitem t, int sz, ll val, ll wh){
	pitem l,m,r;
	split(t,l,m,sz);
	split(m,m,r,1);
	if(wh==ADD_B)m->b+=val;
	else if(wh==ASSIGN_A_IF){
		if(bypass||m->a)m->a=val;
	}
	else assert(0);
	merge(m,m,r); // it's updating here anyway
	merge(t,l,m);
}
node query_sing(pitem t, int sz){
	pitem l,m,r;
	split(t,l,m,sz);
	split(m,m,r,1);
	node ret=m->val;
	merge(m,m,r);
	merge(t,l,m);
	return ret;
}
struct Arbol{
	pitem rt;
	Arbol(ll n){
		rt=0;
		fore(i,0,n){
			pitem cur= new item(0,0);
			merge(rt,rt,cur);
		}
	}
	void recalc(ll x, ll sig){
		ll del=0; // le cambio al b[x]
		while(x!=-1){
			ll h=head[x];
			ll p=dad[h];
			
			pitem l,m,r;
			split(rt,l,m,pos[h]);
			split(m,m,r,len[h]);
			
			ll prox=0;
			if(sig == -1)prox=m->val.res;
			upd_sing(m,pos[x]-pos[h],del,ADD_B);
			if(sig == +1)prox=m->val.res;
			
			merge(m,m,r);
			merge(rt,l,m);
			
			x=p; del=prox*sig;
		}
	}
	void upd_if(ll x, ll v){ // if it turned out that a[x] was positive, change it to v. bypass if flag is on
		recalc(x,-1);
		upd_sing(rt,pos[x],v,ASSIGN_A_IF);
		recalc(x,+1);
	}
	void swap_range(Arbol &a, ll x, ll s, ll e){
		recalc(x,-1);
		a.recalc(x,-1);
		
		pitem l1,m1,r1;
		split(rt,l1,m1,s);
		split(m1,m1,r1,e-s);
		
		pitem l2,m2,r2;
		split(a.rt,l2,m2,s);
		split(m2,m2,r2,e-s);
		
		swap(m1,m2);
		
		merge(m1,m1,r1);
		merge(rt,l1,m1);
		
		merge(m2,m2,r2);
		merge(a.rt,l2,m2);
		
		recalc(x,+1);
		a.recalc(x,+1);
	}
	ll query(){
		pitem l,r;
		split(rt,l,r,len[0]);
		auto val=l->val;
		merge(rt,l,r);
		return val.res;
	}
};

int main(){
	FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	string col; cin>>col;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	hld_init();
	Arbol white(n),black(n);
	bypass=1;
	fore(i,0,n){
		auto &arb=(col[i]=='W'?white:black);
		arb.upd_if(i,a[i]);
	}
	bypass=0;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,v; cin>>x>>v; x--;
			white.upd_if(x,v);
			black.upd_if(x,v);
			// I have no idea where it is, so I upd_if both
		}
		else if(ty==2){
			ll x; cin>>x; x--;
			ll s=pos[x],e=E[x];
			white.swap_range(black,x,s,e);
		}
		else if(ty==3){
			cout<<white.query()<<"\n";
		}
		else assert(0);
	}
}