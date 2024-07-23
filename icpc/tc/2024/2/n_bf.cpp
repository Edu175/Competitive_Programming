#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll N=18,MAXN=1ll<<18,INF=4e8;

vector<ll>g[N];
ll vis[N];
ll n;
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}
ll is_scc(vector<ii>ed){
	fore(i,0,n)g[i].clear();
	for(auto [u,v]:ed)g[u].pb(v);
	// cout<<"is scc "; for(auto i:ed)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	fore(s,0,n){
		mset(vis,0); dfs(s);
		// cout<<s<<": "; fore(i,0,n)cout<<vis[i]<<" ";;cout<<"\n";
		fore(i,0,n)if(!vis[i])return 0;
	}
	return 1;
}

int main(){JET
	cin>>n;
	ll a[n][n];
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	vector<ii>ar;
	fore(i,0,n)fore(j,0,i)if(a[i][j]!=-1){ar.pb({i,j});}
	ll res=INF;
	fore(mk,0,1<<SZ(ar)){
		vector<ii>ed;
		ll sum=0;
		fore(i,0,SZ(ar)){
			auto [u,v]=ar[i];
			if(mk>>i&1)ed.pb({u,v}),sum+=a[u][v];
			else ed.pb({v,u}),sum+=a[v][u];
		}
		if(is_scc(ed))res=min(res,sum);
	}
	cout<<res<<"\n";
}