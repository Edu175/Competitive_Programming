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
const ll K=17,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
vector<ii> g[1<<K];int n; // 0 es cualq, legal es 1, 2 es ilegal
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i].fst;if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

const ll MAXN=1e5+5;
ll subo[MAXN],bajo[MAXN];
ll res=0;
void paga(ll c){
	// cout<<"pago "<<c<<"\n";
	ll cur=sub(fpow(2,c),1);
	res=add(res,cur);
}
ii dfs(ll x, ll fa){
	ii ret={subo[x],bajo[x]};
	for(auto [y,w]:g[x])if(y!=fa){
		// cout<<x<<","<<y<<"\n";
		ii cur=dfs(y,x);
		if(w){
			if(w==1)paga(cur.fst);
			else paga(cur.snd);
		}
		ret.fst+=cur.fst;
		ret.snd+=cur.snd;
	}
	return ret;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll u,v,ty; cin>>u>>v>>ty; u--,v--;
		g[u].pb({v,1*ty});
		g[v].pb({u,2*ty});
	}
	lca_init();
	ll k; cin>>k;
	vv p(k+1); p[0]=0;
	fore(i,1,k+1)cin>>p[i],p[i]--;
	fore(i,0,SZ(p)-1){
		ll x=p[i],y=p[i+1];
		ll anc=lca(x,y);
		subo[x]++; subo[anc]--;
		bajo[y]++; bajo[anc]--;
	}
	dfs(0,-1);
	cout<<res<<"\n";
	return 0;
}
