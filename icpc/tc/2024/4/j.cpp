#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto skdjg:v)cout<<skdjg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll N=2005,MAXN=N*N;

vector<ll>g[MAXN];
ll deg[MAXN];
bool tk[MAXN];//,deg[MAXN];
queue<ll>hojas;
char a[MAXN];
bool hoj[MAXN];
ll n,m;
void add_edge(ll x, ll y){
	// cout<<"add edge "<<x<<","<<y<<"\n";
	tk[x]=tk[y]=1;
	for(auto i:g[x])if(!tk[i]){
		deg[i]--;
		if(deg[i]==1&&!hoj[i])hojas.push(i),hoj[i]=1;
	}
	for(auto i:g[y])if(!tk[i]){
		// g[i].erase(y);
		deg[i]--;
		if(deg[i]==1&&!hoj[i])hojas.push(i),hoj[i]=1;
	}
	g[x].clear(),g[y].clear();
	if(x>y)swap(x,y);
	if(x%m==y%m){
		a[x]='^',a[y]='v';
	}
	else {
		a[x]='<',a[y]='>';
	}
}
ii cv(ll x){return {x/m,x%m};}
ll cv(ii a){return a.fst*m+a.snd;}
void grafo(){
	fore(x,0,n*m){
		cout<<x<<": ";imp(g[x]);
	}
}
void tablero(){
	fore(i,0,n){
		fore(j,0,m){
			cout<<a[cv({i,j})];
		}
		cout<<"\n";
	}
}
void fail(){
	// tablero();
	// grafo();
	cout<<"Not unique\n";
	exit(0);
}
int main(){JET
	cin>>n>>m;
	ll lib=0;
	fore(i,0,n*m)cin>>a[i],lib+=a[i]=='.';
	fore(i,0,n)fore(j,0,m){
		auto add=[&](ll x, ll y){
			if(a[x]=='*'||a[y]=='*')return;
			g[x].pb(y),g[y].pb(x);
		};
		if(i)add(cv({i,j}),cv({i-1,j}));
		if(j)add(cv({i,j}),cv({i,j-1}));
		// if(i<n-1)add(cv({i,j}),cv({i+1,j}));
		// if(j<m-1)add(cv({i,j}),cv({i,j+1}));
	}

	fore(x,0,n*m){
		deg[x]=SZ(g[x]);
		if(deg[x]==1)hojas.push(x),hoj[x]=1;
		// cout<<x<<": ";imp(g[x]);
	}
	ll did=0;
	while(SZ(hojas)){
		auto x=hojas.front(); hojas.pop();
		// assert(!tk[x]);//continue;
		if(tk[x])continue;
		// cout<<"hoja "<<x<<"\n";
		if(!deg[x])fail();
		ll y=-1;
		for(auto i:g[x])if(!tk[i])y=i;
		add_edge(x,y);
		did+=2;
	}

	if(did==lib) tablero();
	else fail();
	return 0;
}