#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e5+5;
const ll K=19;

vv g[MAXN];
int F[K][MAXN],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(ll n){
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

ll S[MAXN],E[MAXN];
ll cnt=0;
vv hoj,spe;
ll is[MAXN],ish[MAXN];

bool dfs0(ll x){
	S[x]=cnt++;
	bool hay=0; ll cuan=0;
	for(auto y:g[x])if(y!=F[0][x]){
		hay|=dfs0(y);
		cuan++;
	}
	E[x]=cnt;
	ish[x]=!cuan;
	if(ish[x])hoj.pb(x);
	if(!hay&&is[x])spe.pb(x);
	return hay||is[x];
}
bool is_anc(ll x, ll y){return S[x]<=S[y]&&S[y]<E[x];}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			is[i]=0;
		}
		cnt=0; hoj.clear(); spe.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		lca_init(n);
		vector<array<ll,3>> paths(m);
		vector<vector<ii>> bu(n);
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--,y--;
			ll p=lca(x,y);
			paths.pb({p,x,y});
			bu[p].pb({x,y});
		}
		sort(ALL(paths),[&](auto a, auto b){return D[a[0]]<D[b[0]];});
		vv to(n),Ito(n,-1); iota(ALL(to),0);
		for(auto [p,x,y]:paths){
			fore(wh,0,2){
				ll u=!wh?x:y;
				while(u!=p&&to[u]==u){
					to[u]=p;
					u=F[0][u];
				}
			}
		}
		// fore(i,0,n)cout<<i<<": "<<to[i]<<"\n";
		fore(i,0,n)is[to[i]]=1,Ito[to[i]]=i;
		dfs0(0);
		vv spePos;
		for(auto i:spe)spePos.pb(S[i]);
		vector<ii> ps;
		fore(ty,0,2)for(auto [p,x,y]:paths){
			if(ty)swap(x,y);
			if(!ish[x])continue;
			ll pos=upper_bound(ALL(spePos),S[y])-spePos.begin()-1;
			if(pos==-1)continue;
			ll ny=spe[pos];
			if(!is_anc(ny,y))continue;
			ps.pb({x,ny});
		}
		sort(ALL(ps));
		ii bad={-1,-1};
		fore(x,0,n){
			if(to[to[x]]!=0)bad={x,0};
		}
		fore(_,0,2){
			for(auto p:spe){
				for(auto h:hoj){
					if(is_anc(p,h))break;
					ii key={h,p};
					auto ptr=lower_bound(ALL(ps),key);
					if(ptr==ps.end()||*ptr!=key){
						bad={h,Ito[p]};
						break;
					}
				}
				if(bad.fst!=-1)break;
			}
			reverse(ALL(hoj));
		}
		if(bad.fst==-1)cout<<"YES\n";
		else {
			cout<<"NO\n";
			cout<<bad.fst+1<<" "<<bad.snd+1<<"\n";
		}
	}
	return 0;
}