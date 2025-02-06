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
const ll MAXN=2e5+5;

vector<ll> g[MAXN];

ll D[MAXN],fa[MAXN],P[MAXN];
vv ord;
void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		D[y]=D[x]+1;
		ord.pb(x);
		dfs(y);
	}
	P[x]=SZ(ord);
	ord.pb(x);
}
const ll K=19;//K such that 2^k>n
ll oper(ll i, ll j){return D[i]<D[j]?i:j;}
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
ll lca(ll x, ll y){
	ll l=P[x],r=P[y];
	if(l>r)swap(l,r);
	return st_query(l,r+1);
}
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll n;
ll is[MAXN],d[MAXN];

void bfs(){
	queue<ll>q;
	mset(d,-1);
	fore(i,0,n)if(is[i])d[i]=0,q.push(i);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1; q.push(y);
		}
	}
}

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fa[0]=-1; D[0]=0;
	dfs(0);
	st_init(ord);
	ll res=0,ans=-1;
	fore(mk,0,1ll<<n){
		vv all;
		fore(i,0,n)if(mk>>i&1)all.pb(i);
		ll flag=1;
		fore(i,0,SZ(all))fore(j,i+1,SZ(all))
			flag&=dis(all[i],all[j])>=k;
		ll resi=SZ(all);
		if(flag)res=max(res,resi);
		if(res==resi)ans=mk;
	}
	cout<<res<<"\n";
	return 0;
}
