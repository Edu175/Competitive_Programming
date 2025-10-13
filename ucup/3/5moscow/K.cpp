#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5,INF=1e18;
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

vector<ii> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
ll wf[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(auto [y,w]:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
		wf[y]=w;
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
ll query(int x, int y, STree& rmq){
	ll r=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		r=oper(r,rmq.query(pos[head[y]],pos[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	r=oper(r,rmq.query(pos[x],pos[y]+1));
	return r;
}
// for updating: rmq.upd(pos[x],v);

vector<ii> path[MAXN]; // value, sink

STree st(MAXN);

ll dfs(ll x, ll fa){
	ll sum=0;
	for(auto [y,w]:g[x])if(y!=fa)sum+=dfs(y,x);
	st.upd(pos[x],sum);
	ll res=sum;
	for(auto [val,s]:path[x]){
		ll cur=query(x,s,st)+val;
		res=max(res,cur);
	}
	st.upd(pos[x],-res);
	return res;
}

const ll K=18;
int main(){
    JET
	ll n,m; cin>>n>>m;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	hld_init();
	wf[0]=INF;
	vector<vv> F(K,vv(n)),V=F;
	fore(i,0,n)F[0][i]=dad[i],V[0][i]=wf[i];
	fore(k,1,K)fore(x,0,n){
		ll fa=F[k-1][x];
		if(fa==-1)F[k][x]=-1,V[k][x]=V[k-1][x];
		else F[k][x]=F[k-1][fa],V[k][x]=V[k-1][x]+V[k-1][fa];
	}
	auto get=[&](ll x, ll v){
		for(ll k=K-1;k>=0;k--){
			ll val=V[k][x];
			if(v>val){
				v-=val;
				x=F[k][x];
			}
		}
		assert(v<=wf[x]);
		return x;
	};
	fore(i,0,m){
		ll k,s; cin>>k>>s; s--;
		vv vals(k),lens(k);
		fore(i,0,k)cin>>vals[i];
		fore(i,0,k)cin>>lens[i];
		ll sum=0,sv=0;
		fore(i,0,k){
			sum+=lens[i];
			sv+=vals[i];
			ll t=get(s,sum);
			if(t)path[t].pb({sv,s});
		}
	}
	
	cout<<dfs(0,-1)<<"\n";
	
    return 0;
}
