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
const ll MAXN=2e5+5,INF=1e10;
int uf[MAXN];
ll val[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y, ll w){
	x=uf_find(x);y=uf_find(y);
	val[x]=min(val[x],w);
	val[y]=min(val[y],w);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	val[x]=min(val[x],val[y]);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)uf[i]=-1,val[i]=INF;
		vector<array<ll,3>>ed;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({w,u,v});
		}
		sort(ALL(ed));
		ll res=INF;
		for(auto [w,u,v]:ed){
			uf_join(u,v,w);
			ll p=uf_find(0);
			ll q=uf_find(n-1);
			if(p==q){
				res=min(res,w+val[p]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
