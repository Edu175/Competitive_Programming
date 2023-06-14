#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXQ=2e5+5,MAXM=2e5+5,MAXV=1e6+5;

struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,0){}
	void upd(ll p, ll v){ //sumo v
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};
vector<ll> g[MAXN];
vector<ii> qs[MAXN];
ll ans[MAXQ];
ll p[MAXN],w[MAXM];
STree sum(MAXV),qan(MAXV);
ll c[MAXM];
void ADD(ll x){
	ll v=w[p[x]];
	if(++c[p[x]]==1)sum.upd(v,v),qan.upd(v,1);
}
void REM(ll x){
	ll v=w[p[x]];
	if(--c[p[x]]==0)sum.upd(v,-v),qan.upd(v,-1);
}
void dfs(ll x, ll f){
	for(auto q:qs[x]){
		ll k=q.fst,i=q.snd;
		ans[i]=sum.query(k,MAXV)-k*qan.query(k,MAXV);
	}
	for(auto y:g[x])if(y!=f){
		ADD(y);
		dfs(y,x);
		REM(y);
	}
}

int main(){FIN;
	ll n,m,nq;cin>>n>>m>>nq;
	fore(i,0,m)cin>>w[i];
	fore(i,0,n-1){
		ll u; cin>>u>>p[i+1]; u--,p[i+1]--;
		g[u].pb(i+1);
		g[i+1].pb(u);
	}
	fore(i,0,nq){
		ll u,k; cin>>u>>k; u--;
		qs[u].pb({k,i});
	}
	dfs(0,-1);
	fore(i,0,nq){
		if(i)cout<<"\n";
		cout<<ans[i];
	}
	return 0;
}
