#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll MAXN=5e3+5;
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};

vector<int> g[MAXN]; // [0,n)->[0,m)
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(int n){
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
int mm(int n){
	int r=0;
	memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
	while(bfs(n)){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}


ll col[MAXN];
vv G[MAXN];
void dfs0(ll x){
	for(auto y:G[x])if(col[y]==-1){
		col[y]=col[x]^1;
		dfs0(y);
	}
}

ll mat[MAXN],vis[MAXN],los[MAXN];

void arma(ll n){ // arma mat
	mset(mat,-1);
	// fore(i,0,n)cout<<col[i]<<" ";;cout<<"\n";
	vv idx(n),cnt(2),h[2];
	fore(i,0,n)idx[i]=cnt[col[i]]++,h[col[i]].pb(i);
	// fore(k,0,2){
	// 	cout<<"h["<<k<<"]: ";
	// 	for(auto i:h[k])cout<<i<<" ";
	// 	cout<<endl;
	// }
	fore(i,0,n)if(!col[i])for(auto j:G[i])g[idx[i]].pb(idx[j]);
	ll z=cnt[0];
	mm(z);
	fore(i,0,n)if(mt[i]!=-1){
		ll u=h[0][mt[i]],v=h[1][i];
		mat[v]=u;
		mat[u]=v;
	}
	// fore(i,0,n){
		// cout<<i<<", "<<mat[i]<<": ";
		// for(auto j:G[i])cout<<j<<" ";
		// cout<<"\n";
	// }cout<<endl;
}

void dfs1(ll x, ll fa){
	// cout<<"dfs1 "<<x<<endl;
	vis[x]=1;
	if(mat[x]!=-1&&mat[x]!=fa){
		ll y=mat[x];
		assert(!vis[y]);
		los[y]=1;
		dfs1(y,x);
	}
	else for(auto y:G[x])if(!vis[y])dfs1(y,x);
}

int main(){
	JET
	ll n; cin>>n;
	map<ii,ll>mp;
	vector<ii>ps;
	fore(i,0,n){
		ll x,y; cin>>x>>y; ps.pb({x,y});
		assert(!mp.count({x,y}));
		mp[{x,y}]=i;
		for(auto [a,b]:dir){
			a+=x,b+=y;
			if(mp.count({a,b})){
				ll j=mp[{a,b}];
				G[i].pb(j);
				G[j].pb(i);
			}
		}
	}
	mset(col,-1);
	fore(i,0,n)if(col[i]==-1){
		col[i]=0; dfs0(i);
	}
	arma(n);
	
	fore(i,0,n)if(mat[i]==-1&&!vis[i]){
		los[i]=1;
		dfs1(i,-1);
	}
	vector<ii>ans;
	fore(i,0,n)if(los[i])ans.pb(ps[i]);
	sort(ALL(ans));
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<i.fst<<" "<<i.snd<<"\n";
	return 0;
}