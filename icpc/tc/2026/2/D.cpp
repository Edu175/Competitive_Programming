#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vv g[MAXN];
set<ll> id;
ll col[MAXN];
void dfs(ll x, ll fa){
	assert(col[x]!=-1);
	id.erase(col[x]);
	for(auto y:g[x])id.erase(col[y]);
	for(auto y:g[x])if(col[y]==-1){
		col[y]=*id.begin();
		id.erase(id.begin());
	}
	
	id.insert(col[x]);
	for(auto y:g[x])id.insert(col[y]);
	for(auto y:g[x])if(y!=fa)dfs(y,x);
}
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll k=-1,rt=-1;
	fore(i,0,n){
		k=max(k,SZ(g[i]));
		if(k==SZ(g[i]))rt=i;
	}
	k++;
	fore(i,0,k)id.insert(i);
	mset(col,-1);
	col[rt]=0;
	dfs(rt,-1);
	cout<<k<<"\n";
	fore(i,0,n)cout<<col[i]+1<<" ";;cout<<"\n";
	return 0;
}