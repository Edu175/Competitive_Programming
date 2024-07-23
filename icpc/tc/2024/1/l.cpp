#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MAXN=2e5;
vector<vv> G(MAXN);
bool vis[MAXN];
ll col[MAXN];
bool T=true;
void dfs(int v, bool y){
	vis[v]=true;
	y=!y;
	col[v]=y;
	for(ll x: G[v]){
		if(!vis[x]) dfs(x,y);
		if(vis[x]) if(col[x]==col[v])  T=false;
	}
}
int main(){
	mset(col,-1);
	JET
	int n,m; cin>>n>>m;
	vector<ii> ar;
	fore(i,0,m) {
		int a,b; cin>>a>>b;
		a--; b--;
		G[a].pb(b);
		G[b].pb(a);
		ar.pb({a,b});
	}
	dfs(0,0);
	if(!T) {cout<<"NO\n"; return 0;}
	else{
		cout<<"YES\n";
		fore(i,0,m){
			cout<<col[ar[i].fst]; 
		}
		
	}
	return 0;
}