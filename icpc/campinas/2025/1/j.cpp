#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<int,ll> ii;
random_device rd;
mt19937 rng(rd());
const int MAXN=2e5+5;
const ll INF=1e9*MAXN*100;
vector<ii>g[MAXN];

void up(ll *a, int w){
	ll b[4];
	b[0]=max(a[0],a[3]+w);
	fore(i,1,4)b[i]=a[i-1]+w;
	fore(i,0,4)a[i]=b[i];
}
// const int B=300; // 450
ll ans[MAXN][4];
void dfs(int x, int fa){
	vector<int> v;
	for(auto [y,w]:g[x])if(y!=fa){
		v.pb(y);
		dfs(y,x);
		up(ans[y],w);
	}
	shuffle(ALL(v),rng);
	int n=SZ(v);
	ll B=2*sqrt(n)+50;
	vector<vector<vv>> dp(2,vector<vv>(2*B+1,vv(2,-INF)));
	dp[n&1][B][0]=0;
	for(int i=n-1;i>=0;i--)fore(bal,0,2*B+1)fore(od,0,2){
		auto &res=dp[i&1][bal][od];
		auto y=v[i];
		res=ans[y][0]+dp[(i+1)&1][bal][od];
		if(bal)res=max(res,ans[y][1]+dp[(i+1)&1][bal-1][od]);
		if(bal<2*B)res=max(res,ans[y][3]+dp[(i+1)&1][bal+1][od]);
		res=max(res,ans[y][2]+dp[(i+1)&1][bal][od^1]);
	}
	ans[x][0]=dp[0][B][0];
	ans[x][1]=dp[0][B+1][0];
	ans[x][3]=dp[0][B-1][0];
	ans[x][2]=dp[0][B][1];
}

int main(){
	JET
	int n; cin>>n;
	fore(i,0,n-1){
		int u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dfs(0,-1);
	cout<<ans[0][0]<<"\n";
	return 0;
}