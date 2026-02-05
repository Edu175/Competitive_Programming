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
const ll MAXN=2e5+5,INF=1e18;
int uf[MAXN];
void uf_init(ll n){memset(uf,-1,sizeof(int)*n);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
typedef ll tn; // node type
typedef ll tl; // lazy type
#define NEUT -INF
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
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
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
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

vector<ii> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
ll wf[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(auto [y,w]:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y]; wf[y]=w;
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(auto [y,w]:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(auto [y,w]:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
void upd(int x, int y, STree& rmq, ll v){ // add v
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		rmq.upd(pos[head[y]],pos[y]+1, v);
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	rmq.upd(pos[x]+1,pos[y]+1,v);
}
// for updating: rmq.upd(pos[x],v);
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line *)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		uf_init(n);
		fore(i,0,n)g[i].clear();
		vector<array<ll,3>> ed;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({w,u,v});
		}
		sort(ALL(ed));
		ll sum=0,tree=1;
		fore(i,0,n-1){
			auto [w,x,y]=ed[i];
			sum+=w;
			tree&=uf_join(x,y);
			g[x].pb({y,w});
			g[y].pb({x,w});
		}
		if(!tree){
			cout<<sum<<"\n";
			continue;
		}
		hld_init();
		ll res=INF;
		if(m>=n+1)res=sum-ed[n-3][0]-ed[n-2][0]+ed[n-1][0]+ed[n][0];
		STree st(n);
		vv ini(n);
		fore(x,0,n)if(x)ini[pos[x]]=wf[x];
		st.init(ini);
		fore(i,n-1,m){
			auto [w,x,y]=ed[i];
			upd(x,y,st,-INF);
			ll got=st.query(0,st.n);
			// cout<<x<<","<<y<<" "<<w<<": "<<got<<"\n";
			// fore(i,0,st.n)cout<<st.query(i,i+1)<<" ";;cout<<"\n";
			upd(x,y,st,+INF);
			if(got<=0)continue;
			ll cur=sum-got+w;
			res=min(res,cur);
		}
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
