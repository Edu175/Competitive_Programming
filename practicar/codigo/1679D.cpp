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
const ll MAXN=2e5+5;

vector<ll>g[MAXN], gi[MAXN];
ll w[MAXN],vis[MAXN],dp[MAXN];
ll n,m,k;
bool cyc=0;

void dfs(ll x){
	for(auto i:gi[x]){
		if(vis[i]!=2){
			if(vis[i]==1){
				cyc=1;
				vis[i]=2;
				break;
			}
			else vis[i]=1,dfs(i);
		}
	}
	vis[x]=2;
}

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	res=0;
	for(auto i:gi[x]){
		res=max(res,f(i));
	}
	res++;
	return res;
}

bool messirve(ll x){
	fore(i,0,n)gi[i].clear(),vis[i]=0;
	cyc=0;
	mset(dp,-1);
	//cout<<"reconstruir\n";
	fore(i,0,n){
		if(w[i]>x)continue;
		for(auto j:g[i]){
			if(w[j]<=x)gi[i].pb(j);
		}
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(gi[i]);
	}*/
	//cout<<"ciclos\n";
	fore(i,0,n)if(!vis[i])dfs(i);
	if(cyc)return 1;
	ll flag=0;
	//cout<<"dp\n";
	fore(i,0,n){
		if(w[i]<=x&&f(i)>=k)flag=1;
	}
	return flag;
}

int main(){FIN;
	cin>>n>>m>>k;
	fore(i,0,n)cin>>w[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	//cout<<"scan?\n";
	ll l=1,r=1e9+5;
	while(l<=r){
		ll m=(l+r)/2;
		//cout<<m<<":\n";
		if(messirve(m))r=m-1;//,cout<<"1\n";
		else l=m+1;//,cout<<"0\n";
		//cout<<"\n";
	}
	if(l>1e9+5)cout<<"-1\n";
	else cout<<l<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
