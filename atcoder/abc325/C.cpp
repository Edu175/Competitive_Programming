#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;
vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

ll vis[MAXN][MAXN];
char a[MAXN][MAXN];
ll n,m;

bool allowed(ll x, ll y, ii d){
	x+=d.fst,y+=d.snd;
	if(x<0||y<0||x>=n||y>=m)return 0;
	if(vis[x][y]||a[x][y]=='.')return 0;
	return 1;
}

void dfs(ll x, ll y){
	vis[x][y]=1;
	for(auto d:dir)if(allowed(x,y,d)){
		dfs(x+d.fst,y+d.snd);
	}
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	ll res=0;
	fore(x,0,n)fore(y,0,m){
		if(vis[x][y]||a[x][y]=='.')continue;
		dfs(x,y);
		res++;
	}
	cout<<res<<"\n";
	return 0;
}
