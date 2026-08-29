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
vv hojPos,spePos;
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

ll to[MAXN],Ito[MAXN];

ii getr(vv &vec, ll x){
	ll l=lower_bound(ALL(vec),S[x])-vec.begin();
	ll r=lower_bound(ALL(vec),E[x])-vec.begin();
	return {l,r};
}
pair<vv,vv> getv(vv &pos, vv &dat, ll x){
	auto [l,r]=getr(pos,x);
	vv ret1=vv(pos.begin()+l,pos.begin()+r);
	vv ret2=vv(dat.begin()+l,dat.begin()+r);
	return {ret1,ret2};
}
bool is_anc(ll x, ll y){return S[x]<=S[y]&&S[y]<E[x];}
ii check(ll x, vector<ii> ps){
	vv ch; for(auto y:g[x])if(y!=F[0][x])ch.pb(y);
	vv ten;
	for(auto y:ch){
		auto got=getr(spePos,y);
		if(got.snd-got.fst)ten.pb(y);
	}
	if(!SZ(ten))return {-1,-1};
	if(SZ(ten)>=2){
		auto [l,r]=getr(spePos,ten[0]);
		ll b1=spe[l];
		tie(l,r)=getr(spePos,ten[1]);
		ll b2=spe[l];
		return {Ito[b1],Ito[b2]};
	}
	ll p=ten[0];
	vv hs;
	for(auto y:ch)if(y!=p){
		auto got=getv(hojPos,hoj,y);
		for(auto i:got.snd)hs.pb(i);
	}
	auto [insPos,ins]=getv(spePos,spe,p);
	vector<ii> have; // normalized, {hoja, special}
	for(auto [x,y]:ps){
		if(!is_anc(p,y))swap(x,y);
		if(!is_anc(p,y)||!ish[x])continue;
		ll pos=upper_bound(ALL(insPos),S[y])-insPos.begin()-1;
		if(pos==-1)continue;
		ll ny=ins[pos];
		if(!is_anc(ny,y))continue;
		have.pb({x,ny});
	}
	sort(ALL(have)); have.resize(unique(ALL(have))-have.begin());
	for(auto h:hs)for(auto i:ins){
		ii key={h,i};
		auto ptr=lower_bound(ALL(have),key);
		if(ptr==have.end()||*ptr!=key)return {h,Ito[i]};
	}
	assert(SZ(have)==SZ(hs)*SZ(ins));
	return {-1,-1};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			is[i]=0;
			to[i]=i;
			Ito[i]=-1;
		}
		cnt=0; hoj.clear(); spe.clear();
		hojPos.clear(); spePos.clear();
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
		for(auto i:hoj)hojPos.pb(S[i]);
		for(auto i:spe)spePos.pb(S[i]);
		ii bad={-1,-1};
		fore(x,0,n){
			if(to[to[x]]!=0)bad={x,0};
		}
		if(bad.fst==-1){
			fore(x,0,n){
				auto got=check(x,bu[x]);
				if(got.fst!=-1)bad=got;
			}
		}
		if(bad.fst==-1)cout<<"YES\n";
		else {
			cout<<"NO\n";
			cout<<bad.fst+1<<" "<<bad.snd+1<<"\n";
		}
	}
	return 0;
}