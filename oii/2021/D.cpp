#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

char ty[MAXN];
vector<ll> g[MAXN];

set<ll> comp[MAXN];
ll id[MAXN];
ll join(ll x, ll y, char t){
	x=id[x],y=id[y];
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
	set<ll>aux;
	for(auto i:comp[y]){
		if(t=='O'){
			comp[x].insert(i);
		}
		if(t=='A'){
			if(comp[x].count(i))aux.insert(i);
		}
		if(t=='X'){
			if(comp[x].count(i))comp[x].erase(i);
			else comp[x].insert(i);
		}
	}
	if(t=='A')comp[x]=aux;
	return x;
}
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
	if(ty[x]=='E')return;
	if(ty[x]=='L'){
		id[x]=id[g[x][0]];
	}
	else {
		id[x]=join(g[x][0],g[x][1],ty[x]);
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>ty[i];
	fore(i,0,n)id[i]=i;
	fore(i,0,n){
		ll m; cin>>m;
		vector<ll>v(m);
		fore(i,0,m)cin>>v[i];
		if(ty[i]=='E'){
			for(auto j:v)comp[id[i]].insert(j);
		}
		else g[i]=v;
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	fore(x,0,n){
		if(ty[x]=='L'){
			for(auto i:comp[id[x]])cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
