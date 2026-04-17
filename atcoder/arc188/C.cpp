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
const ll MAXN=2e5+5;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

vv g[MAXN];
ll c[MAXN];
ll good=1;
void dfs(ll x){
	for(auto y:g[x]){
		if(c[y]!=-1)good&=c[x]!=c[y];
		else {
			c[y]=c[x]^1;
			dfs(y);
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vector<vv>> to(n,vector<vv>(2));
	uf_init();
	fore(i,0,m){
		ll a,b,c; cin>>a>>b>>c; a--,b--;
		to[a][c].pb(b);
	}
	// fore(x,0,n){
	// 	cout<<"to "<<x<<":\n";
	// 	fore(w,0,2)imp(to[x][w])
	// 	cout<<"\n";
	// }
	fore(x,0,n)fore(w,0,2){
		auto &v=to[x][w];
		fore(i,0,SZ(v)-1)uf_join(v[i],v[i+1]);
	}
	fore(x,0,n){
		auto &a=to[x][0];
		auto &b=to[x][1];
		if(SZ(a)&&SZ(b)){
			ll u=uf_find(a[0]);
			ll v=uf_find(b[0]);
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	mset(c,-1);
	fore(x,0,n)if(c[x]==-1){
		c[x]=0;
		dfs(x);
	}
	if(!good){
		cout<<"-1\n";
		return 0;
	}
	vv wh(n);
	fore(x,0,n)wh[x]=c[uf_find(x)];
	// imp(wh)
	// cout<<endl;
	vv res(n);
	fore(x,0,n){
		auto &cur=res[x]; cur=0;
		fore(w,0,2){
			auto v=to[x][w];
			if(!SZ(v))continue;
			ll y=v[0],t=wh[y];
			// cout<<x<<" "<<wh[x]<<": "<<w<<" "<<t<<endl;
			if(!(w==(t!=wh[x])))cur=1;
		}
		// assert(cur!=1);
		// if(cur==2)cur--;
		cout<<cur;
	}
	cout<<"\n";
	return 0;
}
