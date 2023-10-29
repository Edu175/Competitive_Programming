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

vector<set<ll>> g[MAXN];
vector<ll> ali[MAXN];
//set<ll> tim[MAXN];
ll idx(ll x, ll t){
	ll res=lower_bound(ALL(ali[x]),t)-ali[x].begin();
	if(res>=SZ(ali[x])||ali[x][res]!=t)return -1;
	return res;
}
void erase(ll x){
	fore(i,0,SZ(ali[x])){
		ll t=ali[x][i];
		for(auto y:g[x][i]){
			if(idx(y,t)!=-1)g[y][idx(y,t)].erase(x);
		}
		g[x][i].clear();
	}
	ali[x].clear();
}
int main(){FIN;
	ll n,t; cin>>n>>t;
	vector<ii>ed[t];
	fore(i,0,t){
		ll m; cin>>m;
		ed[i].resize(m);
		fore(j,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed[i][j]={u,v};
			if(!SZ(ali[u])||ali[u].back()!=i)ali[u].pb(i),g[u].pb({});
			if(!SZ(ali[v])||ali[v].back()!=i)ali[v].pb(i),g[v].pb({});
			g[u].back().insert(v);
			g[v].back().insert(u);
		}
	}
	set<ll>con={0},old,now;
	ll q; cin>>q;
	vector<ll>a(q);
	fore(i,0,q)cin>>a[i],a[i]--;
	set<ii>can[t];
	if(idx(0,a[0])!=-1)for(auto i:g[0][idx(0,a[0])])can[a[0]].insert({0,i});
	erase(0);
	ll res=-2;
	fore(i,0,q){
		
		now.clear();
		for(auto [u,v]:can[a[i]]){
			if(!con.count(u))now.insert(u);
			if(!con.count(v))now.insert(v);
		}
		can[a[i]].clear();
		for(auto x:now){
			con.insert(x);
			if(idx(x,a[i])!=-1){
				for(auto j:g[x][idx(x,a[i])]){
					if(!con.count(j)&&!now.count(j)){
						can[a[i]].insert({x,j});
					}
				}
			}
		}
		for(auto j:now)erase(j);
		if(con.count(n-1)){
			res=i;
			break;
		}
	}
	cout<<res+1<<"\n";
	return 0;
}
