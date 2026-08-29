#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int K = 18;
const int MAXN = 1<<K;
ll val[MAXN];
ii g[MAXN];
ll F[K][MAXN];
ll D[MAXN];
ll start[MAXN];
ll ed[MAXN];


struct STree{
	ll oper(ll a, ll b){
		return a+b;
	}
	#define NEUT 0
	int n; vv t;
	STree(int n):n(n),t(2*n,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}	
	ll query(int l, int r){
		ll izq = NEUT, der = NEUT;
		for(l += n, r+=n;l<r;l>>=1,r>>=1){
			if(l&1) izq = oper(izq,t[l++]);
			if(r&1) der = oper(t[--r],der);
		}
		return oper(izq,der);
	}
	#undef NEUT
};

struct STreeRangeAssign{
	int n;
	vv upds;
	ll NEUT;
	vv t;
	STreeRangeAssign(int n):n(n),upds(1,-1),NEUT(0),t(2*n,NEUT){}
	void upd(int l, int r, ll v){
		ll sz=SZ(upds); upds.pb(v);
		for(l += n, r+=n;l<r;l>>=1,r>>=1){
			if(l&1) t[l++]=sz;
			if(r&1) t[--r]=sz;
		}
	}
	ll query(int p){
		ll res=NEUT;
		for(p+=n;p>0;p>>=1)res=max(res,t[p]);
		return upds[res];
	}
};
void init_lca(){
	fore(k,1,K)fore(i,0,MAXN)if(F[k-1][i] >= 0) F[k][i] = F[k-1][F[k-1][i]];
}

ll lca(ll x, ll y){
	if(D[x] < D[y]) swap(x,y);
	for(ll k = K-1; k>=0; k--)if(D[y] + (1<<k) <= D[x]) x = F[k][x];
	if(x == y) return x;
	for(ll k = K-1;k>=0;k--)if(F[k][x] != F[k][y]) x = F[k][x], y = F[k][y];
	return F[0][x];
}
int wg[MAXN],dad[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(int y:{g[x].fst,g[x].snd})if(y!=dad[x]&&y!=-1){
		dad[y]=x;dfs1(y); wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c; int mx=-1;
	for(int y:{g[x].fst,g[x].snd})if(y!=-1&&y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:{g[x].fst,g[x].snd})if(y!=-1&&y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(ll rt){dad[rt]=-1;dfs1(rt);curpos=0;hld(rt,-1);}

STreeRangeAssign owns(1);
void updPath(ll x, ll y, ll v){ // y ancestor of x, [y,x]
	// cerr<<"updPath "<<x<<","<<y<<"\n";
	while(head[x]!=head[y]){
		// cerr<<x<<" "<<y<<"\n";
		if(x==-1)assert(0);
		owns.upd(pos[head[x]],pos[x]+1,v);
		x=dad[head[x]];
	}
	owns.upd(pos[y],pos[x]+1,v);
}

ll rival[MAXN]; // node of conflict
ll cnt = 0;
ll prof(ll x, ll d, STree &st){
	start[x] = cnt++;
	D[x] = d;
	ll r = x;
	if(g[x].fst != -1){
		ll y1 = g[x].fst, r1 = prof(y1, d+1, st);
		ll y2 = g[x].snd, r2 = prof(y2,d+1, st);
		if(r1 > r2) swap(r1,r2), swap(y1,y2);
		rival[r2] = x;
		updPath(r2, y2, r2);
		r = min(r1,r2); 
	}
	ed[x] = cnt;
	return r;
}

ll rt;
ll upd(int x, ll w, STree &st){
	ll xo = x;
	// cout<<"query agrego "<<w<<" al nodo "<<x+1<<"\n";
	while(rival[x] != -1){
		int y = owns.query(pos[rival[x]]);
		// cout<<"estoy viendo "<<x+1<<" con rival "<<y+1<<"\n";
		ll lc = lca(x,y);
		assert(g[lc].fst != -1);
		ll rx = g[lc].fst, ry = g[lc].snd;
		if(start[y] >= start[rx] && start[y] < ed[rx]) swap(rx,ry);
		ll wrx = st.query(start[rx],ed[rx]), wry = st.query(start[ry],ed[ry]);
		assert(wrx<=wry);
		if((wrx + w > wry) || (wrx + w == wry && rx<ry)){
			rival[x] = rival[y];
			rival[y] = lc;
		}
		else {
			updPath(x,rx,x);
			x=y;
		}
	}
	updPath(x, rt, x);
	st.upd(start[xo],w);
	return x;
}

int main(){
	JET
	mset(F,-1);
	fore(i,0,MAXN) g[i] = {-1,-1};
	mset(rival,-1);
	
	ll n; cin>>n;
	ll h=n; n=2*h-1; rt=n-1;
	fore(i,0,h) cin>>val[i];
	fore(i,h,n){
		ll x,y; cin>>x>>y;x--,y--;
		g[i] = {x,y};
		F[0][x] = i;
		F[0][y] = i;
	}
	
	STree st(n);
	owns = STreeRangeAssign(n);
	// fore(i,1,owns.n)cerr<<owns.t[i]<<" ";;cerr<<"\n";
	hld_init(rt);
	ll x=prof(rt,0,st);
	updPath(x, rt, x);
	
	// fore(i,1,owns.n)cerr<<owns.t[i]<<" ";;cerr<<"\n";
	// fore(i,0,n)cout<<owns.query(pos[i])<<" ";;cout<<"\n";
	
	init_lca();	
	ll win;
	fore(i,0,h)win = upd(i,val[i],st);
	cout<<win+1<<"\n";	
	ll q; cin>>q;
	while(q--){
		ll x,w; cin>>x>>w;x--;
		cout<<upd(x,w,st)+1<<"\n";
	}
	return 0;
}

