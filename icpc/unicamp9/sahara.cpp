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
const ll MAXN=1e5+5;

vector<ii> g[MAXN]; ll n;
const ll K=17; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto [y,i]:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
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
#define NEUT 0
ll oper(ll a, ll b){return a+b;}
struct STree{ //persistent
	vector<int>st,L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]+=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};
const ll B=205,MAXC=2e4+5;
ll dp[B][MAXN];
STree st(0);
vector<ll>rt;
void dfs(ll x){
	for(auto [y,w]:g[x])if(y!=F[0][x]){
		fore(b,1,B)dp[b][y]=dp[b][x]+(w+b-1)/b;
		//,cout<<"dp["<<b<<"]["<<y<<"]="<<dp[b][x]<<"+"<<(w+b-1)/b<<"\n";
		rt[y]=st.upd(rt[x],w,1);
		dfs(y);
	}
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	lca_init();
	st=STree(MAXC);
	rt.resize(n);
	dfs(0);
	/*fore(b,0,8){
		cout<<b<<":\n";
		fore(i,0,n)cout<<i<<": "<<dp[b][i]<<"\n";
	}*/
	while(q--){
		ll x,y,c; cin>>x>>y>>c; x--,y--;
		ll p=lca(x,y),res=0;
		if(c<B){
			res=dp[c][x]+dp[c][y]-2*dp[c][p];
			//cout<<dp[c][x]<<" "<<dp[c][y]<<" "<<dp[c][p]<<"\n";
		}
		else {
			for(ll s=0,i=1;s<MAXC;s+=c,i++){
				ll e=min(s+c,MAXC-1);
				res+=i*(st.query(rt[x],s,e)+st.query(rt[y],s,e)
				-2*st.query(rt[p],s,e));
			}
		}
		cout<<res+1<<"\n";
	}
	return 0;
}
