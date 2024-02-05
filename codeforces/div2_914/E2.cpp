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

const ll MAXN=2e5+5,K=18;

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

#define NEUT {10*MAXN,-1}
#define CLEAR 0 // cleared lazy node
ii oper(ii a, ii b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ii calc(ii a, ll v){ // calculate STree range, a=previous value
	return {a.fst+v,a.snd+v};
} 
bool can(ii x, ll de){
	if(!de)return x.snd>0;
	else return x.fst==0;
}
struct STree{
	vector<ii>t; vector<ll>lazy; ll n; vector<vector<ll>>bag;
	STree(ll n):st(2*n+5,{0,0}),lazy(2*n+5,CLEAR),n(n){}
	STree(){}
	void push(ll k){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(k<n){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	vector<ll> decomp(ll l, ll r){
		vector<ll>ret;
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)ret.pb(l++);
			if(r&1)ret.pb(--r);
		}
		reverse(ALL(ret));
		return ret;
	}
	vector<ii> get_all(ll l, ll r){
		vector<ii>ret;
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)ret.pb(l++,1);
			else ret.pb(l,0);
			if(r&1)ret.pb(--r,1);
			else ret.pb(r,0);
		}
		reverse(ALL(ret));
		return ret;
	}
	void upd(ll l, ll r, ll v){
		for(auto [k,is]:get_all(l,r)){
			if(is)acum(lazy[k],v);
			push(k);
			if(k>1)push(k^1);
		}
	}
	ii query(ll l, ll r){}
};
struct STree{
	vector<ii>st; vector<ll>lazy; ll n; vector<vector<ll>>bag;
	STree(ll n):st(4*n+5,{0,0}),lazy(4*n+5,CLEAR),n(n){}
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
	ii query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	vector<vector<ll>> nod;
	void rec(ll k, ll s, ll e, ll a){
		if(e<=a)return;
		push(k,s,e);
		if(s>=a){nod.pb({k,s,e});return;}
		ll m=(s+e)/2;
		rec(2*k,s,m,a),rec(2*k+1,m,e,a);
	}
	ll find(ll k, ll s, ll e, ll de){
		//push(k,s,e);
		if(s+1==e){
			if(can(st[k],de))return s;
			return s+1;
		}
		ll m=(s+e)/2;
		push(2*k,s,m),push(2*k+1,m,e);
		if(can(st[2*k],de))return find(2*k,s,m,de);
		return find(2*k+1,m,e,de);
	}
	ll find(ll a, ll de){
		nod.clear();
		rec(1,0,n,a);
		for(auto v:nod){
			if(can(st[v[0]],de))return find(v[0],v[1],v[2],de);
		}
		return n;
	}
	void upd(ll a, ll b, ll v){
		upd(1,0,n,a,b,v);
		bag.pb({a,b,v});
	}
	void reset(){
		for(auto v:bag)upd(1,0,n,v[0],v[1],-v[2]);
		bag.clear();
	}
	ii query(ll a, ll b){return query(1,0,n,a,b);}
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

STree ran;

void dfs2(ll x){
	for(auto [v,idx]:qs[x]){
		ran.reset();
		//cout<<"query "<<idx<<": "<<v<<"\n";
		for(auto y:v){
			//cout<<y<<": ";
			if(S[y]<=S[x]&&S[x]<E[y]){ // y ancestro de x
				ll ny=father(D[x]-D[y]-1,x);
				ran.upd(0,S[ny],1);
				ran.upd(E[ny],n,1);
				//cout<<"[0,"<<S[ny]<<") ["<<E[ny]<<","<<n<<")\n";
			}
			else {
				ran.upd(S[y],E[y],1);
				//cout<<"["<<S[y]<<","<<E[y]<<")\n";
			}
		}
		ll &res=ans[idx];
		ll p=0;
		
		while(p<n){
			ll de=(ran.query(p,p+1).fst>0);
			ll l=ran.find(p,de);
			if(!de)res=max(res,st.query(p,l).snd);
			//,cout<<"["<<p<<","<<l<<") ";
			p=l;
		}
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
	ran=STree(n);
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
