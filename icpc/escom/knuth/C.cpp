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
typedef vector<int> vv;
const int MAXN=2e5+5;
mt19937 rng(175);

typedef struct item *pitem;
struct item {
	int pr,cnt; pitem l,r;
	int a; ll b; ll res,sum;
	item(ll a, ll b): pr(rng()),cnt(1),l(0),r(0),a(a),b(b),res(a),sum(b) {}
};
int cnt(pitem t){return t?t->cnt:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		ll r1=0,s1=0; if(t->l)r1=t->l->res,s1=t->l->sum;
		ll r2=t->a,s2=t->b;
		ll r3=0,s3=0; if(t->r)r3=t->r->res,s3=t->r->sum;
		t->res=max({r1,s1+r2,s1+s2+r3});
		t->sum=s1+s2+s3;
	}
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){
	if(!t){l=r=0;return;}
	if(sz<=cnt(t->l)){
		split(t->l,l,t->l,sz);r=t;
	}
	else {
		split(t->r,t->r,r,sz-1-cnt(t->l));l=t;
	}
	upd_cnt(t);
}
vector<vector<int>> g(MAXN);
int wg[MAXN],dad[MAXN],len[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dfs1(y); wg[x]+=wg[y];
	}
}
int curpos,head[MAXN],E[MAXN];
vector<int> pos(MAXN);
void hld(int x, int c){
	if(c<0)c=x,len[c]=0;
	pos[x]=curpos++;head[x]=c; int mx=-1; len[c]++;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
	E[x]=curpos;
}
void hld_init(){dad[0]=-1;dfs1(0);curpos=0;hld(0,-1);}

enum {ASSIGN_A,ADD_B,SWAP};
bool bypass;
void upd_sing(pitem t, int sz, ll val, bool wh){
	pitem l,m,r;
	split(t,l,m,sz);
	split(m,m,r,1);
	if(wh==ADD_B)m->b+=val;
	else if(wh==ASSIGN_A)m->a=val;
	else assert(0);
	merge(m,m,r); // it's updating here anyway
	merge(t,l,m);
}
int query_sing_a(pitem t, int sz){
	pitem l,m,r;
	split(t,l,m,sz);
	split(m,m,r,1);
	int ret=m->a;
	merge(m,m,r);
	merge(t,l,m);
	return ret;
}
struct Arbol{
	pitem rt;
	Arbol(int n){
		rt=0;
		fore(i,0,n){
			pitem cur= new item(0,0);
			merge(rt,rt,cur);
		}
	}
	
	void upd(int x, int val){
		ll del=val; bool wh=ASSIGN_A; // le cambio al b[x]
		while(x!=-1){
			int h=head[x];
			int p=dad[h];
			
			pitem m,r;
			split(rt,rt,r,h);
			split(r,m,r,len[h]);
			
			ll prox=-m->res;
			upd_sing(m,x-h,del,wh);
			prox+=m->res;
			
			merge(r,m,r);
			merge(rt,rt,r);
			
			x=p; del=prox; wh=ADD_B;
		}
	}
	void upd_if(int x, int v){ // if it turned out that a[x] was positive, change it to v. bypass if flag is on
		int val=1;
		if(!bypass)val=query_sing_a(rt,x);
		if(val)upd(x,v);
	}
	void swap_range(Arbol &a, int x, int s, int e){
		
		
		pitem r1;
		split(rt,rt,r1,e);
		pitem r2;
		split(a.rt,a.rt,r2,e);
		
		ll del1=0,del2=0; int wh=SWAP;
		
		while(x!=-1){
			int h=head[x];
			int p=dad[h];
			
			pitem m1,r1;
			split(rt,rt,r1,h);
			split(r1,m1,r1,len[h]);
			
			pitem m2,r2;
			split(a.rt,a.rt,r2,h);
			split(r2,m2,r2,len[h]);
			
			ll prox1=-m1->res;
			ll prox2=-m2->res;
			if(wh==SWAP){
				pitem tmp1; split(m1,m1,tmp1,x-h);
				pitem tmp2; split(m2,m2,tmp2,x-h);
				swap(tmp1,tmp2); swap(r1,r2);
				merge(m1,m1,tmp1);
				merge(m2,m2,tmp2);
			}
			else {
				upd_sing(m1,x-h,del1,wh);
				upd_sing(m2,x-h,del2,wh);
			}
			prox1+=m1->res;
			prox2+=m2->res;
			
			merge(r1,m1,r1);
			merge(rt,rt,r1);

			merge(r2,m2,r2);
			merge(a.rt,a.rt,r2);

			x=p; del1=prox1; del2=prox2; wh=ADD_B;
		}
		
		merge(rt,rt,r1);
		merge(a.rt,a.rt,r2);
		
	}
	ll query(){
		pitem l,r;
		split(rt,l,r,len[0]);
		ll res=l->res;
		merge(rt,l,r);
		return res;
	}
};

int main(){
	FIN;
	int n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	string col; cin>>col;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	hld_init();
	
	// cache opt
	auto _a=a;
	auto _col=col;
	auto nl=pos;
	vector<vector<int>> _g=g; g.clear(); g.resize(n);
	fore(i,0,n){
		a[nl[i]]=_a[i];
		col[nl[i]]=_col[i];
		for(auto j:_g[i])g[nl[i]].pb(nl[j]);
	}
	_a.clear(); _g.clear(); _col.clear();
	hld_init();
	assert(nl[0]==0);
	fore(i,0,n)assert(pos[i]==i);
	Arbol white(n),black(n);
	bypass=1;
	fore(i,0,n){
		auto &arb=(col[i]=='W'?white:black);
		arb.upd_if(i,a[i]);
	}
	bypass=0;
	while(q--){
		int ty; cin>>ty;
		if(ty==1){
			int x,v; cin>>x>>v; x--; x=nl[x];
			white.upd_if(x,v);
			black.upd_if(x,v);
			// I have no idea where it is, so I upd_if both
		}
		else if(ty==2){
			int x; cin>>x; x--; x=nl[x];
			int s=x,e=E[x];
			white.swap_range(black,x,s,e);
		}
		else if(ty==3){
			cout<<white.query()<<"\n";
		}
		else assert(0);
	}
}