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
const ll MAXN=2e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll tag[MAXN];	// tag[y]>=tag[x] for every y in x's subgraph (has to be conenected to x)
ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
ll ccnt=0;
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=1; tag[x]=ccnt++;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(ll n){
	fore(i,0,n)tk[i]=0;
	ccnt=0;cdfs();
}

vv cet[MAXN];

ll dfs(ll x, ll fa, ll rt){
	ll res=1;
	for(auto y:g[x])if(y!=fa&&tag[y]>=tag[rt])
		res=mul(res,add(1,dfs(y,x,rt)));
	return res;
}
ll ans=0;
void doit(ll x){
	ll res=dfs(x,-1,x);
	cout<<"doit "<<x<<": "<<res<<"\n";
	ans=add(ans,res);
	for(auto y:cet[x])doit(y);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			cet[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		centroid(n);
		ll rt=-1;
		fore(i,0,n){
			if(fat[i]==-1)rt=i;
			else cet[fat[i]].pb(i);
		}
		ans=0;
		doit(rt);
		// ans=add(ans,1); // vacio no
		cout<<ans<<"\n";
	}
	return 0;
}
