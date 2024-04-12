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
const ll MAXN=200*200+5;
vector<ll>g[MAXN];
ll n;
vector<ll> bfs(ll s){
	vector<ll>d(n,-1);
	queue<ll>q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}

vector<ll>dg[MAXN];
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:dg[x])if(!vis[y])dfs(y);
}
int main(){FIN;
	ll h,w; cin>>h>>w;
	char s[h][w];
	ll S,E;
	fore(i,0,h)fore(j,0,w){
		cin>>s[i][j];
		if(s[i][j]=='S')S=w*i+j;
		if(s[i][j]=='T')E=w*i+j;
	}
	ll q; cin>>q;
	vector<ii>a;
	while(q--){
		ll i,j,v; cin>>i>>j>>v; i--,j--;
		a.pb({w*i+j,v});
	}
	vector<ii>dir={{1,0},{0,-1},{-1,0},{0,1}};
	//fore(i,0,2)fore(j,0,2)dir.pb({i*2-1,j*2-1});
	fore(i,0,h)fore(j,0,w)if(s[i][j]!='#'){
		for(auto d:dir){
			ll i1=i+d.fst,j1=j+d.snd;
			if(i1>=0&&i1<h&&j1>=0&&j1<w&&s[i1][j1]!='#')g[i*w+j].pb(i1*w+j1);
		}
	}
	n=h*w;
	for(auto [x,e]:a){
		auto d=bfs(x);
		for(auto [y,sg]:a)if(d[y]!=-1&&d[y]<=e)dg[x].pb(y);;
		if(d[E]!=-1&&d[E]<=e)dg[x].pb(E);
	}
	dfs(S);
	if(vis[E])cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
