#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1005,MAXM=MAXN;

vector<ii> g[MAXN];

vector<ii> inutil;
ll vis[MAXN],vised[MAXM];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(vis[y])inutil.pb({x,y});
		else dfs(y);
	}
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	vv reps;
	fore(i,0,n)if(!vis[i]){
		reps.pb(i);
		dfs(i);
	}
	vector<ii> nuevas;
	fore(i,0,SZ(reps)-1)nuevas.pb({reps[i],reps[i+1]});
	assert(SZ(inutil)==SZ(nuevas));
	cout<<SZ(inutil)<<"\n";
	fore(i,0,SZ(inutil)){
		cout<<inutil[i].fst+1<<" "<<inutil[i].snd+1<<" "<<nuevas[i].fst+1<<" "<<nuevas[i].snd+1<<"\n";
	}
	return 0;
}