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
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MAXN=2e5+5,K=18,INF=10*MAXN;

ll n;
vector<ll> g[MAXN];
//K such that 2^K>=n, log2 techo de n, ceil(log2(n))
ll F[K][MAXN],D[MAXN];//késimo padre de x, distancia a root
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];//level
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];//find lca
	return F[0][x];
}
ll father(ll v, ll x){
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
	}
	return x;
}

#define NEUT 0
#define CLEAR 0 // cleared lazy node
#define oper max
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll a, ll v){ // calculate STree range, a=previous value
	return a+v;
} 
struct STree{
	vector<ll> st,lazy; ll n; vector<vector<ll>>bag;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	STree(){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
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
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){
		upd(1,0,n,a,b,v);
		bag.pb({a,b,v});
	}
	void rollback(){
		for(auto v:bag)upd(1,0,n,v[0],v[1],-v[2]);
		bag.clear();
	}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};


vector<ll>ord;
ll S[MAXN],E[MAXN];

void dfs1(ll x){
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto y:g[x])if(y!=F[0][x]){
		dfs1(y);
	}
	E[x]=SZ(ord);
}

STree st;

void down(ll x){
	st.upd(S[x],E[x],-1);
	st.upd(0,S[x],1); st.upd(E[x],n,1);
}
void up(ll x){
	st.upd(S[x],E[x],1);
	st.upd(0,S[x],-1); st.upd(E[x],n,-1);
}
vector<pair<vector<ll>,ll>>qs[MAXN];
ll ans[MAXN];

void dfs2(ll x){
	for(auto [v,idx]:qs[x]){
		//cout<<"query "<<idx<<": "<<v<<"\n";
		st.bag.clear();
		for(auto y:v){
			//cout<<y<<": ";
			if(S[y]<=S[x]&&S[x]<E[y]){ // y ancestro de x
				ll ny=father(D[x]-D[y]-1,x);
				st.upd(0,S[ny],-INF);
				st.upd(E[ny],n,-INF);
				//cout<<"[0,"<<S[ny]<<") ["<<E[ny]<<","<<n<<")\n";
			}
			else {
				st.upd(S[y],E[y],-INF);
				//cout<<"["<<S[y]<<","<<E[y]<<")\n";
			}
		}
		ll &res=ans[idx];
		res=st.query(0,n);
		st.rollback();
		//cout<<res<<"\n\n";
	}
	for(auto y:g[x])if(y!=F[0][x]){
		down(y);
		dfs2(y);
		up(y);
	}
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init();
	dfs1(0);
	st=STree(n);
	fore(i,0,n)st.upd(S[i],S[i]+1,D[i]);
	fore(_,0,q){
		ll x,k; cin>>x>>k; x--;
		vector<ll>v(k);
		fore(i,0,k)cin>>v[i],v[i]--;
		qs[x].pb({v,_});
	}
	dfs2(0);
	fore(i,0,q)cout<<ans[i]<<"\n";
	return 0;
}
