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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=305;
bool g[MAXN][MAXN];
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(ll n){
	queue<int> q;
	mset(ds,-1);
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
		int x=q.front();q.pop();
		fore(y,0,n)if(g[x][y]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=true;
		}
	}
	return r;
}
bool dfs(int x, ll n){
	fore(y,0,n)if(g[x][y])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y],n)){
		mt[y]=x;mt2[x]=y;
		return true;
	}
	ds[x]=1<<30;
	return false;
}
int mm(ll n){
	int r=0;
	mset(mt,-1); mset(mt2,-1);
	while(bfs(n)){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i,n);
	}
	return r;
}
ll k;
struct UF{
	vector<vv> comp,h;
	vv id;
	ll n;
	UF(ll n):comp(n,vv(n)),h(n,vv(k)),id(n),n(n){
		fore(i,0,n)comp[i][i]=1,id[i]=i;
	}
	bool join(ll x, ll y){
		x=id[x],y=id[y];
		if(x==y)return 0;
		fore(i,0,n)if(comp[y][i])id[i]=x,comp[x][i]=1;
		fore(i,0,k)h[x][i]|=h[y][i];
		return 1;
	}
	bool good(){
		fore(i,0,n)fore(j,0,k)g[i][j]=id[i]==i&&h[i][j];
		return mm(n)==k;
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m>>k;
	vector<array<ll,3>>ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({w,u,v});
	}
	sort(ALL(ed));
	UF uf(n);
	fore(i,0,k){
		ll sz; cin>>sz;
		fore(_,0,sz){
			ll j; cin>>j; j--;
			uf.h[j][i]=1;
		}
	}
	ll res=0;
	ll cc=n;
	for(auto [w,x,y]:ed){
		auto old=uf;
		if(cc==k)break;
		if(uf.join(x,y)){
			if(uf.good())res+=w,cc--;
			else uf=old;
		}
	}
	cout<<res<<"\n";
	return 0;
}
