#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, edu=b; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=100005,MAXM=300005;

vector<pair<ll,ll>> g[MAXN];
bool vis[MAXM];

void dfs(ll x){
	//cout<<x+1<<" ";
	for(auto i:g[x]){
		if(!vis[i.snd]){
			vis[i.snd]=1;
			cout<<i.snd+1<<" ";
			dfs(i.fst);
			cout<<i.snd+1<<" ";
		}
	}
}

 int main(){FIN;
 	ll n,m,s; cin>>n>>m>>s;
 	s--;
 	fore(i,0,m){
 		ll a,b,w; cin>>a>>b>>w;
 		a--,b--;
 		g[a].pb({b,i});
 		g[b].pb({a,i});
 	}
 	cout<<2*m<<"\n";
 	dfs(s);
 	return 0;
 }
