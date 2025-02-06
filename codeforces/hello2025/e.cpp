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
const ll MAXN=405,INF=2*MAXN;

ll n;
ll d[MAXN][MAXN];
ll _d[MAXN][MAXN];
void floyd(){//O(n^3)
	//setear d[i][i]=0 y INF a aristas no existentes
	//se pisan los valores en la matriz de adyacencia
	fore(k,0,n)fore(i,0,n)if(d[i][k]!=INF)fore(j,0,n)if(d[k][j]!=INF)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);//or if(d==f||newPath<d)for flag value
}
// vector<ii> g[MAXN];
int uf[MAXN];
void uf_init(){fore(i,0,n)uf[i]=-1;}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	// cout<<"join "<<x<<" "<<y<<endl;
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	fore(i,0,n)d[x][i]=min(d[x][i],d[y][i]);
	fore(i,0,n)d[i][x]=min(d[i][x],d[i][y]);
	// add x
	fore(i,0,n)fore(j,0,n)
		d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
	
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,q; cin>>n>>m>>q;
		fore(i,0,n){
			// g[i].clear();
			fore(j,0,n)d[i][j]=INF;
			d[i][i]=0;
		}
		vector<pair<ii,ll>>ed;
		vv vals;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({{u,v},w});
			vals.pb(w);
		}
		auto _vals=vals; sort(ALL(_vals)); vals.clear();
		for(auto i:_vals)if(!SZ(vals)||vals.back()!=i)vals.pb(i);
		vv que[m];
		fore(i,0,m){
			auto [ar,w]=ed[i];
			auto [u,v]=ar;
			w=lower_bound(ALL(vals),w)-vals.begin();
			que[w].pb(i);
			// g[u].pb({v,w});
			// g[v].pb({u,w});
			// cout<<u<<" "<<v<<"\n";
			d[u][v]=d[v][u]=min(d[u][v],1ll);
		}
		floyd();
		// fore(i,0,n){
		// 	fore(j,0,n)cout<<d[i][j]<<" ";;cout<<"\n";
		// }
		// cout<<"floyd ^^^\n\n";
		fore(i,0,n)fore(j,0,n)_d[i][j]=d[i][j];
		vector<pair<ii,ll>>qs(q);
		vv ls(q),rs(q);
		vector<vv> h(SZ(vals));
		fore(i,0,q){
			ll a,b,k; cin>>a>>b>>k; a--,b--,k--;
			qs[i]={{a,b},k};
			ls[i]=0,rs[i]=SZ(vals)-1;
			ll mid=(ls[i]+rs[i])/2;
			h[mid].pb(i);
		}
		ll did=1;
		while(did){
			// cout<<"\n\n\nbinaria\n";
			did=0;
			uf_init();
			fore(i,0,n)fore(j,0,n)d[i][j]=_d[i][j];
			vector<vv> hi(SZ(vals));
			fore(w,0,SZ(vals)){
			// for(ll w=SZ(vals)-1;w>=0;w--){
				// upd
				for(auto i:que[w]){
					// assert(w==ed[i].snd);
					uf_join(ed[i].fst.fst,ed[i].fst.snd);
				}
				
				
				// bs queries
				// cout<<"mid "<<w<<":\n";
				for(auto i:h[w]){
					did=1;
					auto &l=ls[i],&r=rs[i];
					auto [fst,k]=qs[i];
					auto [a,b]=fst;
					// mid=w;
					// cout<<"query "<<i<<": "<<a<<","<<b<<" "<<k<<": "<<d[a][b]<<endl;
					a=uf_find(a),b=uf_find(b);
					// cout<<d[a][b]<<endl;
					// cout<<l<<","<<r<<" -> ";
					if(d[a][b]<=k)r=w-1;
					else l=w+1;
					// cout<<l<<","<<r<<endl;
					if(l<=r){
						ll mid=(l+r)/2;
						hi[mid].pb(i);
					}
				}
				
				
			}
			swap(h,hi);
		}
		fore(i,0,q)cout<<vals[ls[i]]<<" ";;cout<<"\n";
	}
	return 0;
}
