#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=105;

vector<ll> g[MAXN];
ll n;
ll mat[MAXN],vis[MAXN];

bool match(ll x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:g[x])if(mat[y]==-1||match(mat[y])){
		mat[y]=x;
		return 1;
	}
	return 0;
}

ll max_matching(){
	mset(mat,-1);
	ll res=0;
	fore(i,0,n)mset(vis,0),res+=match(i);
	return res;
}

vector<ll>v[2];
ll vist[MAXN][2],is[MAXN];
void dfs(ll x, ll w){
	if(vist[x][w])return;
	vist[x][w]=1;
	v[w].pb(x);
	if(!w)for(auto y:g[x])dfs(y,w^1);
	else dfs(mat[x],w^1);
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		if(c=='o'){
			g[i].pb(j);
		}
	}
	ll res=max_matching();
	cout<<res<<"\n";
	fore(i,0,n)if(mat[i]!=-1)is[mat[i]]=1;
	fore(i,0,n)if(!is[i])dfs(i,0);
	v[0].clear();
	fore(i,0,n)if(!vist[i][0])v[0].pb(i);
	fore(w,0,2)for(auto i:v[w])cout<<w+1<<" "<<i+1<<"\n";
	//fore(i,0,n)cout<<mat[i]<<"\n";
	assert(res==SZ(v[0])+SZ(v[1]));
	return 0;
}
