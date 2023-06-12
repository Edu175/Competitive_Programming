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
const ll MAXN=2e3+5;

vector<ll>g[MAXN];

ll vis[MAXN],vec[MAXN],f[MAXN];
ll flag=-1;
/*void dfs(ll x, ll v){
	if(flag!=-1)return;
	vis[x]=1;
	if(x!=v&&vec[x]){
		flag=x;
		return;
	}
	for(auto y:g[x])if(!vis[y]){
		dfs(y);
	}
}*/
void bfs(ll v){
	queue<ll>q;
	q.push(v);
	while(SZ(q)){
		auto x=q.front();q.pop();
		vis[x]=1;
		if(x!=v&&vec[x])flag=x;
		if(flag!=-1)break;
		for(auto y:g[x])if(!vis[y]){
			q.push(y);
			f[y]=x;
		}
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll u1=-1,v1=-1,v2=-1;
		fore(u,0,n){
			if(SZ(g[u])<4)continue;
			mset(vis,0),mset(vec,0); flag=-1; mset(f,-1);
			for(auto i:g[u])vec[i]=1;
			vis[u]=1;
			for(auto v:g[u]){
				f[v]=u;
				bfs(v);
				if(flag!=-1){
					u1=u,v1=v,v2=flag;
					break;
				}
			}
		}
		if(u1==-1){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		vector<ll>c;
		vector<pair<ll,ll>>res;
		for(auto i:g[u1])if(i!=v1&&i!=v2)c.pb(i);
		fore(i,0,2)res.pb({u1,c[i]});
		res.pb({u1,v2});
		for(ll x=v2;x!=u1;x=f[x])res.pb({x,f[x]});
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
