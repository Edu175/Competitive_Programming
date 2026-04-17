#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=2e5+5;
vector<ii> g[maxn]; //{nodo,edgy}
int lw[maxn],D[maxn],sz[maxn];
bool br[maxn],vised[maxn];
bool tree[maxn];
ll cnt=0;
void dfs_(ll x){
	lw[x]=D[x];
	sz[x]++;
	for(auto [y,i]: g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){// tree
			tree[i]=1;
			D[y]=D[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			br[i]=(lw[y]>=D[y]);
			sz[x]+=sz[y];
		}
		else lw[x]=min(lw[x],D[y]),br[i]=0; // back
	}
}


void dfs_tree(int n, int m=0){
	if(!m) mset(lw,-1),mset(vised,0);
	else{
		fore(i,0,n) lw[i]=-1;
		fore(i,0,m) vised[i]=0;
	}
	fore(i,0,n)if(lw[i]==-1) D[i]=0,dfs_(i);
}

int uf[maxn];
// void uf_init(){mset(uf,-1);}
int ufind(int x){return uf[x]<0?x:uf[x]=ufind(uf[x]);}
bool ujoin(int x, int y){
	x=ufind(x); y=ufind(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return true;
}

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("cactus.in","r",stdin);     freopen("cactus.out","w",stdout);
	#endif
	ll n,m;
	cin>>n;
	while(m--){
		ll k,x,y; cin>>k>>x;x--,k--;
		fore(i,0,k){
			cin>>y; y--;
			g[x].pb({y,cnt});
			g[y].pb({x,cnt++});
			x=y;
		}
	}
	dfs_tree(n);
	return 0;
}