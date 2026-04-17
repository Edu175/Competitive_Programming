#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2005;
vector<int> g[MAXN]; // [0,n)->[0,m)
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(ll n){
	queue<int> q;
	memset(ds,-1,sizeof(ds));
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=true;
		}
	}
	return r;
}
bool dfs(int x){
	for(int y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
		mt[y]=x;mt2[x]=y;
		return true;
	}
	ds[x]=1<<30;
	return false;
}
int mm(ll n){
	int r=0;
	memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
	while(bfs(n)){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}

ll god[MAXN][MAXN];
ll col[MAXN];
void dfs1(ll x, ll w){
	col[x]=w;
	for(auto y:g[x])if(col[y]==-1)dfs1(y,w^1);
}
ll relabel(ll n){ // graph g, make it bipartite [0,n)->[0,m)
	mset(col,-1);
	fore(i,0,n)if(col[i]==-1)dfs1(i,0);
	vector<vv>h(2);
	fore(i,0,n)h[col[i]].pb(i);
	vv id(n);
	fore(k,0,2)fore(i,0,SZ(h[k]))id[h[k][i]]=i;
	vector<ii>ed;
	fore(x,0,n){
		for(auto y:g[x])if(!col[x])ed.pb({id[x],id[y]});
		g[x].clear();
	}
	for(auto [x,y]:ed)g[x].pb(y);
	return SZ(h[0]);
}
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n)fore(j,0,n){
		char x; cin>>x;
		god[i][j]=x=='1';
	}
	vector<vv> c(n);
	auto yatan=[&](ll x, ll y){
		for(auto i:c[x])if(count(ALL(c[y]),i))return 1;
		return 0;
	};
	ll cnt=0;
	fore(x,0,n)while(SZ(c[x])<2){
		ll u=-1;
		fore(y,0,n)if(!yatan(x,y)&&god[x][y])u=y;
		c[x].pb(cnt);
		if(u==-1){cnt++;continue;}
		c[u].pb(cnt);
		fore(y,0,n)if(!yatan(x,y)&&god[x][y]&&god[u][y])c[y].pb(cnt);
		cnt++;
	}
	// fore(i,0,n)imp(c[i]);
	fore(i,0,n)g[c[i][0]].pb(c[i][1]),g[c[i][1]].pb(c[i][0]);
	ll N=relabel(cnt);
	ll res=mm(N);
	cout<<res<<"\n";
}
