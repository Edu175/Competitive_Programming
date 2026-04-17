#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll k=18;
vector<ii> g[1<<k]; int n;
int F[k][1<<k], D[1<<k];
int M[k][1<<k];
void lca_dfs(int x){
	fore(i,0,SZ(g[x])){
		int y=g[x][i].fst;
		if(y==F[0][x]) continue;
		F[0][y]=x; M[0][y]=g[x][i].snd;
		D[y]=D[x]+1;
		lca_dfs(y);
	}
}	
void lca_init(){
	D[0]=0; F[0][0]=-1; M[0][0]=0;
	lca_dfs(0);
	fore(j,1,k)fore(x,0,n){
		if(F[j-1][x]<0) {F[j][x]=-1; M[j][x]=-1;}
		else {
			F[j][x]=F[j-1][F[j-1][x]];
			M[j][x]=max(M[j-1][F[j-1][x]],M[j-1][x]);
		}
	
	} 
}
int lca(int x, int y){
	if(D[x]<D[y]) swap(x,y);
	int m=0;
	for (int j=k-1; j>=0; --j)if(D[x]-(1<<j)>=D[y]){
		m=max(M[j][x],m);x=F[j][x];
	}
	if(x==y) return m;

	for(int j=k-1; j>=0; --j)if(F[j][x]!=F[j][y]){
		m=max(M[j][y],m);m=max(M[j][x],m);
		 x=F[j][x], y=F[j][y];
		}
	m=max(M[0][x],m);
	m=max(M[0][y],m);
	return m;
}
int uf[1<<k];
void init(){mset(uf,-1);}
int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool join(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(uf[x]>uf[y]) swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return true;
}

int main(){ET;
	int r; cin>>n>>r;
	vector <pair<ll,ii>> a;
	vector <pair<ii,ll>> b;
	fore(i,0,r) {
		int x,y,w; cin>>x>>y>>w; x--; y--;
		if(x>y) swap(x,y);
		a.pb({w,{x,y}});
		b.pb({{x,y},w});
	}
	init();
	sort(ALL(a));
	sort(ALL(b));
	ll T=0;
	fore(i,0,r){
		ll x=a[i].snd.fst,y=a[i].snd.snd,w=a[i].fst;
		if(join(x,y)){
			T+=w; 
			g[x].pb({y,w});
			g[y].pb({x,w});
		}
	}
	// cout<<"T: "<<T<<"\n";
	lca_init();
	int q; cin>>q;
	while(q--){
		int u,v; cin>>u>>v; u--; v--;if(u>v) swap(u,v);
		ll j=lower_bound(ALL(b),pair<ii,ll>({{u,v},0}))-b.begin();
		int res=T-lca(u,v)+b[j].snd;
		// cout<<"l: "<<lca(u,v)<<"\n";
		// cout<<"w: "<<b[j].snd<<"\n";
		// cout<<"myv: "<<b[j].fst.snd<<"\n";
		// cout<<"u: "<<u<<"\n";
		// cout<<"v: "<<v<<"\n";
		cout<<res<<"\n";
		// cout<<"\n";
	}
	return 0;
}
/*
3 3
1 2 10
2 3 5
1 3 7
3
2 3
1 2
1 3
*/