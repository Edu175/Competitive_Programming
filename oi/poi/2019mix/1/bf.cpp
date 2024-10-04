#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define forr(i,a,b) for(ll i=b-1,skopul=a;i>=skopul;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll K=17,MAXN=1e5+5,INF=MAXN*(1e6+5);

vector<ii>g[MAXN];
ll F[K][MAXN],S[MAXN],E[MAXN],D[MAXN],Dw[MAXN];
ll cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto [y,w]:g[x])if(y!=F[0][x]){
		D[y]=D[x]+1;
		Dw[y]=Dw[x]+w;
		F[0][y]=x;
		dfs(y);
	}
	E[x]=cnt;
}
ll n;
void lca_init(){
	D[0]=0; F[0][0]=-1;
	dfs(0);
	fore(k,1,K)fore(x,0,n){
		F[k][x]=(F[k-1][x]==-1)?-1:F[k-1][F[k-1][x]];
	}
}
ll lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);
	forr(k,0,K)if(F[k][x]!=-1&& D[F[k][x]]>=D[y])x=F[k][x];
	if(x==y)return x;
	forr(k,0,K)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
ll dis(ll x, ll y){return Dw[x]+Dw[y]-2*Dw[lca(x,y)];}
int main(){FIN;
	ll r; cin>>n>>r;
	vector<ll> nod[r];
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--,nod[a[i]].pb(i);
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	lca_init();
	ll q; cin>>q;
	fore(_,0,q){
		ll x,y,c; cin>>x>>y>>c; x--,y--,c--;
		ll res=INF;
		for(auto i:nod[c]){
			res=min(res,dis(x,i)+dis(y,i));
		}
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}