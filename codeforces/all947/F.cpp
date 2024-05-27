#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll N=21,MAXN=1ll<<N;

ll vis[MAXN][N],good[MAXN];
ll ppc(ll x){return __builtin_popcountll(x);}
ll n,m;
void dfs(ll x, ll b){
	cout<<"dfs "<<x<<" "<<b<<"\n";
	vis[x][b]=1;
	if(b==ppc(x)){
		good[x]=1;
		return;
	}
	fore(i,0,n)if(x>>i&1){
		ll y=x^(1ll<<i);
		if(vis[y][b])continue;
		dfs(y,b);
	}
}

int main(){FIN;
	cin>>n;
	m=1ll<<n;
	fore(x,1,m){
		ll mk; cin>>mk;
		fore(b,0,ppc(x)+1)if((mk>>b&1))dfs(x,b);
	}
	vector<ll>ret;
	fore(i,0,m)if(good[i])ret.pb(i);
	cout<<SZ(ret)<<"\n";
	for(auto i:ret)cout<<i<<"\n";
	return 0;
}
