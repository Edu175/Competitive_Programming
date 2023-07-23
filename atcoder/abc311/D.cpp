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
const ll MAXN=205;

vector<ll>dir;
char a[MAXN*MAXN];
ll n,m;
ll cv(ll i, ll j){return m*i+j;}
ll vis[MAXN*MAXN][4];

/*bool block(ll i, ll j){
	if(a[i][j]=='#')return 0;
}*/
ll is[MAXN*MAXN];
void dfs(ll x, ll d){
	vis[x][d]=1;
	is[x]=1;
	//cout<<x<<" "<<d<<"\n";
	ll y=x+dir[d];
	if(a[y]=='.'){
		if(!vis[y][d])dfs(y,d);
	}
	else {
		fore(i,0,SZ(dir)){
			y=x+dir[i];
			if(a[y]=='.'&&!vis[y][i])dfs(y,i);
		}
	}
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n)fore(j,0,m)cin>>a[cv(i,j)];
	dir={-m,1,m,-1};
	fore(i,0,4)dfs(cv(1,1),i);
	ll res=0;
	fore(i,0,n*m)res+=is[i];
	cout<<res<<"\n";
	return 0;
}
