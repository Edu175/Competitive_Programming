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
const ll MAXN=505;
ll n,m;
vector<ll>g[MAXN];
bool vis[MAXN];
ll mat[MAXN];
bool match(ll x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto i:g[x]){
		if(mat[i]==-1||match(mat[i])){
			mat[i]=x;
			return 1;
		}
	}
	return 0;
}
vector<ii> max_matching(){
	mset(mat,-1);
	vector<ii> res;
	fore(x,0,n){
		fore(i,0,n)vis[i]=0;
		match(x);
	}
	fore(i,0,m)if(mat[i]!=-1)res.pb({mat[i],i});
	return res;
}
int main(){FIN;
	ll k; cin>>n>>m>>k;
	fore(i,0,k){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	vector<ii>res=max_matching();
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
