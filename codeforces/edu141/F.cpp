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
const ll MAXN=3e3+5;

struct UF{
	ll n; vector<ll> uf;
	void init(int x){n=x,uf.resize(n,-1);}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return 0;
		if(uf[x]>uf[y])swap(x,y);
		uf[x]+=uf[y];uf[y]=x;
		return 1;
	}
};
ll n;
vector<ll>g[MAXN];
ll mat[MAXN];
bool vis[MAXN];
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
void max_matching(){
	mset(mat,-1);
	fore(i,0,n)mset(vis,0),match(i);
}
int main(){FIN;
	cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cin>>b[i],b[i]--;
	UF c,d; c.init(n),d.init(n);
	fore(i,0,n)c.join(i,a[i]),d.join(i,b[i]);
	fore(i,0,n)g[c.find(i)].pb(d.find(i));
	max_matching();
	ll ed[n][n]; mset(ed,0);
	fore(i,0,n)if(mat[i]!=-1)ed[mat[i]][i]=1;
	vector<ll>res;
	fore(i,0,n){
		ll &e=ed[c.find(i)][d.find(i)];
		if(e)e=0;
		else res.pb(i);
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
