#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto jsdh:v)cout<<jsdh<<" ";cout<<endl;}
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
const ll MAXN=1005;

ll n,m;
ll a[MAXN][MAXN];
vector<ii> b[MAXN][MAXN];
ll vis[MAXN][MAXN];
void dfs(ll x, ll y){
	if(vis[x][y])return;
	vis[x][y]=1;
	for(auto [x2,y2]:b[x][y])dfs(x2,y2);
}
int main(){JET
	cin>>n>>m;
	fore(i,0,n)fore(j,0,m)cin>>a[i][j],a[i][j]--;
	fore(i,0,n)fore(j,0,n)fore(k,0,m){
		b[a[i][k]][a[j][k]].pb({i,j});
	}
	ll flag=1;
	dfs(0,0);
	fore(i,0,n)fore(j,0,n)flag&=vis[i][j];
	if(flag)cout<<"S\n";
	else cout<<"N\n";
	return 0;
}