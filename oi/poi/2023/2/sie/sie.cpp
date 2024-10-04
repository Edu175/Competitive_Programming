#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szkopul=b;i<szkopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=205,INF=MAXN*MAXN;

ll d[MAXN][MAXN];
ll n;
void floyd(){
	fore(k,0,n)fore(i,0,n)fore(j,0,n)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
ll col[MAXN],vis[MAXN],q[2];
vector<ll>v;
ll bip=1;
void dfs(ll x, ll c, ll fa=-1){
	// cout<<"dfs "<<x<<" "<<c<<" "<<fa<<"\n";
	if(vis[x]){
		if(col[x]!=c)bip=0;
		return;
	}
	v.pb(x);
	vis[x]=1;
	col[x]=c;
	q[col[x]]++;
	fore(y,0,n)if(d[x][y])dfs(y,c^1,x);
}

ll n1,n2;
vector<ll> g[MAXN];
ll mat[MAXN],vis2[MAXN];

bool match(ll x){
	if(vis2[x])return 0;
	vis2[x]=1;
	for(auto y:g[x])if(mat[y]==-1||match(mat[y])){
		mat[y]=x;
		return 1;
	}
	return 0;
}

ll max_matching(){
	mset(mat,-1);
	ll res=0;
	fore(i,0,n1)mset(vis2,0),res+=match(i);
	return res;
}

vector<ll>ve[2];
ll vist[MAXN][2],is[MAXN];
void dfs2(ll x, ll w){
	if(vist[x][w])return;
	vist[x][w]=1;
	ve[w].pb(x);
	if(!w)for(auto y:g[x])dfs2(y,w^1);
	else dfs2(mat[x],w^1);
}

vector<vector<ll>> indepSet(){
	max_matching();
	// cout<<res<<"\n";
	fore(i,0,n1)if(mat[i]!=-1)is[mat[i]]=1;
	fore(i,0,n1)if(!is[i])dfs2(i,0);
	ve[0].clear();
	fore(i,0,n1)if(!vist[i][0])ve[0].pb(i);
	vector<ll>ele(n1,1);
	for(auto i:ve[0])ele[i]=0;
	vector<ll>ele1(n2,1);
	for(auto i:ve[1])ele1[i]=0;
	vector<vector<ll>>ret(2);
	fore(i,0,n1)if(ele[i])ret[0].pb(i);
	fore(i,0,n2)if(ele1[i])ret[1].pb(i);
	// fore(w,0,2)for(auto i:ve[w])ret[w*n1+i]=0;
	// ret[0]=ve[0];
	// ret[1]=ve[1];
	return ret;
}


int main(){FIN;
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		d[u][v]=d[v][u]=1;
	}
	fore(i,0,n)if(!vis[i]){
		q[0]=q[1]=0;
		v.clear();
		dfs(i,0);
		if(q[1]>q[0]){
			for(auto i:v)col[i]^=1;
			// swap(q[1],q[0]);
		}
	}
	if(!bip){
		cout<<"NIE\n";
		return 0;
	}
	fore(i,0,n)fore(j,0,n)if(!d[i][j])d[i][j]=INF;
	fore(i,0,n)d[i][i]=0;
	floyd();
	vector<ll>q(2);
	fore(i,0,n)q[col[i]]++;
	n1=q[0];
	n2=q[1];
	if(k&1){
		cout<<q[0]<<"\n";
		vector<ll>a(n);
		fore(i,0,n)a[i]=col[i]+1;
		imp(a);
		return 0;
	}
	vector<ll>idx(n),ids(2);
	vector<vector<ll>>h(2);
	fore(i,0,n)idx[i]=ids[col[i]]++,h[col[i]].pb(i);
	fore(i,0,n)fore(j,0,n)if(col[i]==0&&col[j]==1&&d[i][j]<k-1){
		g[idx[i]].pb(idx[j]);
	}
	// fore(i,0,n1){
	// 	cout<<i<<": ";
	// 	imp(g[i]);
	// }
	auto r=indepSet();
	// imp(r[0])
	// imp(r[1])
	vector<ll>num(n,-1);
	for(auto i:r[0])num[h[0][i]]=0;
	for(auto i:r[1])num[h[1][i]]=k-1;
	// imp(num);
	fore(v,0,k-1)fore(i,0,n)if(num[i]==v)fore(j,0,n)if(d[i][j]==1){
		if(num[j]==-1)num[j]=v+1;
	}
	// imp(num);
	
	fore(i,0,n)if(num[i]==-1)num[i]=k-2;
	ll res=SZ(r[0])+SZ(r[1]);
	cout<<res<<"\n";
	fore(i,0,n)cout<<num[i]+1<<" ";;cout<<endl;
	
	
	
	ll ans=0;
	fore(i,0,n){
		ans+=num[i]==0||num[i]==k-1;
		assert(0<=num[i]&&num[i]<k);
		fore(j,0,k)if(d[i][j]==1)assert(abs(num[i]-num[j])==1);
	}
	assert(res==ans);
	return 0;
}