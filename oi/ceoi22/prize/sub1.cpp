#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ceoi=b;i<ceoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto kdjfhg:v)cout<<kdjfhg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5,K=20;

vector<ii> g[2][MAXN]; ll n; ll rt[2];
struct LCA{
	vector<vector<ll>>F,V; vector<ll>D;
	LCA(): F(K,vector<ll>(1<<K)),V(K,vector<ll>(1<<K)),D(MAXN){}
	void lca_dfs(ll x, ll z){
		for(auto [y,w]:g[z][x])if(y!=F[0][x]){
			F[0][y]=x;
			V[0][y]=w;
			D[y]=D[x]+1;
			lca_dfs(y,z);
		}
	}
	void lca_init(ll rt, ll z){
		D[rt]=V[0][rt]=0;F[0][rt]=-1;
		lca_dfs(rt,z);
		fore(k,1,K)fore(i,0,n){
			if(F[k-1][i]<0)F[k][i]=-1,V[k][i]=V[k-1][i];
			else {
				F[k][i]=F[k-1][F[k-1][i]];
				V[k][i]=V[k-1][i]+V[k-1][F[k-1][i]];
			}
		}
	}
	ii lca(ll x, ll y){
		if(D[x]<D[y])swap(x,y);
		ll res=0;
		for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
			res+=V[k][x];
			x=F[k][x];
		}
		//cout<<"iguales?\n";
		if(x==y)return {x,res};
		//cout<<"no\n";
		for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
			res+=V[k][x]+V[k][y];
			x=F[k][x];
			y=F[k][y];
		}
		res+=V[0][x]+V[0][y];
		x=F[0][x];
		return {x,res};
	}
};

vector<ll>nod;
void dfs(ll x, ll z){
	nod.pb(x);
	for(auto [y,c]:g[z][x])dfs(y,z);
}
int main(){
	ll k,q,t; cin>>n>>k>>q>>t;
	fore(h,0,2)fore(i,0,n){
		ll p; cin>>p; p--;
		if(p<0)rt[h]=i;
		else g[h][p].pb({i,0});
	}
	dfs(rt[0],0);
	nod.resize(k);
	LCA G1;
	G1.lca_init(rt[0],0);
	vector<ll>pa(n);
	fore(i,0,n)pa[i]=G1.F[0][i];
	for(auto i:nod)cout<<i+1<<" ";;cout<<endl;
	for(auto i:nod)if(pa[i]>=0)
		cout<<"? "<<i+1<<" "<<pa[i]+1<<endl;
	cout<<"!"<<endl;
	fore(i,0,n)g[0][i].clear();
	fore(i,0,SZ(nod))if(pa[nod[i]]>=0){
		//cout<<"ingresa "<<i<<endl;
		ll w=0;
		fore(j,0,4){
			ll x; cin>>x;
			w=max(w,x);
		}
		g[0][pa[nod[i]]].pb({nod[i],w});
	}
	//cout<<"termina"<<endl;
	G1.lca_init(rt[0],0);
	vector<ii>ans;
	while(t--){
		ll x,y; cin>>x>>y; x--,y--;
		ll r=G1.lca(x,y).snd;
		ans.pb({r,r});
	}
	for(auto i:ans)cout<<i.fst<<" "<<i.snd<<endl;
	return 0;
}
