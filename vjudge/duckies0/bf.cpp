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
const ll MAXN=2e5+5;

vector<ll> g[MAXN];
ll p[MAXN];

void dfs(ll x){
	for(auto y:g[x])if(y!=p[x]){
		p[y]=x;
		dfs(y);
	}
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	p[0]=-1;
	dfs(0);
	vector<ll>is(n-k); fore(i,0,k)is.pb(1);
	ll res=0;
	do{
		ll resi=0;
		fore(i,0,n){
			if(is[i]){
				for(ll x=i;x!=-1;x=p[x])resi+=!is[x];
			}
		}
		res=max(res,resi);
	}
	while(next_permutation(ALL(is)));
	cout<<res<<"\n";
	return 0;
}
