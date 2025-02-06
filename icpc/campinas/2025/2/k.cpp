#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,INF=1e17; // 1e12
vv g[MAXN];
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll tag[MAXN];	// tag[y]>=tag[x] for every y in x's subgraph (has to be conenected to x)
ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
ll ccnt=0;
vv ord;
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=1; tag[x]=ccnt++; ord.pb(x);
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);ccnt=0;cdfs();}

typedef ii tn; // node type
typedef ll tl; // lazy type
// tn unit(ll v){return v;}
ii NEUT={-INF,1};
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a.fst+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(){}
	STree(vv ind):st(4*SZ(ind)+5,NEUT),lazy(4*SZ(ind)+5,CLEAR),n(SZ(ind)){
		vector<tn>a(SZ(ind));
		fore(i,0,SZ(ind))a[i]={0,-ind[i]};
		init(a);
	}
	void init(ll k, ll s, ll e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

vv S[MAXN],E[MAXN];
ll cnt=0; vv ind;
void dfs(ll rt, ll x, ll fa){
	ind.pb(x);
	S[x].pb(cnt++);
	for(auto y:g[x])if(y!=fa&&tag[y]>=tag[rt])dfs(rt,y,x);
	E[x].pb(cnt);
}
STree st[MAXN]; // subarbol de yo como centroid
void upd(ll x, ll w){ // +=
	for(ll y=x,j=0;y!=-1;y=fat[y],j++){
		ll pos=S[x][j];
		st[y].upd(pos,pos+1,w);
	}
}
void upd(ll x, ll y, ll w){ // += (metele menos che qlia)
	ll i=0,j=0,px=x,py=y;
	while(px!=py){
		if(tag[px]>tag[py])px=fat[px],i++;
		else py=fat[py],j++;
	}
	while(px!=-1){
		if(S[x][i]<=S[y][j]&&S[y][j]<E[x][i])swap(x,y),swap(i,j);
		// x abajo
		st[px].upd(S[x][i],E[x][i],w);
		px=fat[px]; i++,j++;
	}
}

ii query(ll x){
	auto res=NEUT;
	for(ll y=x,j=0;y!=-1;y=fat[y],j++){
		ll pos=S[x][j];
		ii lhs=st[y].query(pos,pos+1);
		auto rhs=oper(st[y].query(0,pos),st[y].query(pos+1,st[y].n));
		rhs.fst+=lhs.fst;
		res=oper(res,rhs);
	}
	return res;
}
int main(){
	JET
	ll n,q; cin>>n>>q;
	assert(n>1);
	map<ii,ll>ed;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		if(u>v)swap(u,v);
		ed[{u,v}]=w;
	}
	centroid();
	reverse(ALL(ord));
	for(auto i:ord)cnt=0,ind.clear(),dfs(i,i,-1),st[i]=STree(ind);
	fore(i,0,n)upd(i,a[i]);
	for(auto [ar,w]:ed)upd(ar.fst,ar.snd,-w);
	ll now=0;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,w; cin>>x>>w; x--; w-=a[x];
			upd(x,w);
			a[x]+=w;
		}
		else {
			ll x,y,w; cin>>x>>y>>w; x--,y--;
			if(x>y)swap(x,y);
			w-=ed[{x,y}];
			upd(x,y,-w);
			ed[{x,y}]+=w;
		}
		auto [res,prox]=query(now); prox=-prox;
		assert(res>-INF);
		now=prox;
		cout<<now+1<<" ";
	}
	cout<<"\n";
	return 0;
}