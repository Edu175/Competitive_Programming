#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef ii node;
node operst(node a, node b){
	return max(a,b);
}
node NEUTst={-5,-1};
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUTst){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=operst(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUTst;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=operst(res,t[l++]);
			if(r&1)res=operst(res,t[--r]);
		}
		return res;
	}
};
#define NEUT 0
#define CLEAR 0 // cleared lazy node
ll oper(ll a, ll b){
	return a+b;
}
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+(e-s)*v;
}

struct STlazy{
	vector<ll>st,lazy; ll n;
	STlazy(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
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
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
	ll query(ll a){return query(1,0,n,a,a+1);}
};

const ll MAXN=2e5+5;
vector<ll>g[MAXN]; ll n;
const ll K=18; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN],S[MAXN],E[MAXN],cnt=0;
void lca_dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
	E[x]=cnt;
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

ll father(ll v, ll x){ // v-ésimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>n>>q;
		fore(i,0,n){
			g[i].clear();
		}
		cnt=0;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		STree st(n);
		STlazy la(n);
		lca_init();
		vector<ll>es(n);
		set<ii>my;
		ll cant=0;
		auto upd=[&](ll x){
			if(!es[x]){
				st.upd(S[x],{D[x],x});
				my.insert({D[x],x});
				la.upd(S[x],E[x],1);
				cant++;
			}
			else {
				st.upd(S[x],NEUTst);
				my.erase({D[x],x});
				la.upd(S[x],E[x],-1);
				cant--;
			}
			es[x]^=1;
		};
		fore(i,0,n)if(a[i])upd(i);
		while(q--){
			ll k; cin>>k; k--;
			upd(k);
			if(cant==0){cout<<"No\n";continue;}
			if(cant==1){cout<<"Yes\n";continue;}
			ll x=prev(my.end())->snd;
			ll p=my.begin()->snd;
			ll hx=father(D[x]-D[p]-1,x);
			ll y=operst(st.query(0,S[hx]),st.query(E[hx],n)).snd;
			ll flag=1;
			flag&=(!p||la.query(S[F[0][p]])==0);
			ll a=la.query(S[x]),b=la.query(S[y]);
			flag&=a==D[x]-D[p]+1;
			flag&=b==D[y]-D[p]+1;
			flag&=a+b-1==cant;
			if(flag)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
