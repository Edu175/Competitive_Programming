#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5;
ll k;
vv g[MAXN]; ll d[MAXN], c[MAXN]; bool vis[MAXN];
ll addm(ll a, ll b){
	a+=b;
	return a<k?a:a-k;
}
void dfs(ll v){
	vis[v]=true;
	for(ll i: g[v]){
		if(!vis[i]){
			c[i]=(c[i]==-1||c[i]==c[v]?addm(c[v],1):c[i]);
		}
	}
	for(ll i: g[v]){
		if(!vis[i]){
			dfs(i);
		}
	}
	
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("holes.in","r",stdin);     freopen("holes.out","w",stdout);
	#endif
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll x,y;
		 cin>>x>>y; x--;y--;
		 g[y].pb(x); g[x].pb(y);
		 d[x]++; d[y]++;
	}
	k=0;
	fore(i,0,n){k=max(k,d[i]);}
	k+=!(k&1);
	mset(c,-1);
	c[0]=0; dfs(0);
	cout<<k<<"\n";
	fore(i,0,n) cout<<c[i]+1<<"\n";
	return 0;
}
7 8
1 4
4 2
2 6
6 3
3 7
4 5
5 6
5 2
3
1
3
2
2
2
1
3
