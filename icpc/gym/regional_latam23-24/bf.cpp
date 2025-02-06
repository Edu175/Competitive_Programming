#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=105;

vv g[MAXN];
ll cnt=0;
vector<ii>ed;
void dfs(ll x, ll fa){
	for(auto y:g[x])if(y!=fa)ed.pb({x,y}),dfs(y,x);
}
int main(){
	ET;
	ll n,s; cin>>n>>s; s--;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(s,-1);
	ll res=0;
	vv per(n); iota(ALL(per),0);
	do{
		ll flag=1,resi=0;
		vv pos(n);
		fore(i,0,n)pos[per[i]]=i,resi+=(i+1)*(per[i]+1);
		for(auto [x,y]:ed)flag&=pos[x]<pos[y];
		if(flag)res=max(res,resi);
	}while(next_permutation(ALL(per)));
	cout<<res<<"\n";
}