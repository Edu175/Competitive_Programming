#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1505;

ll c[MAXN][MAXN];
void erase(ll i, ll j, ll v){
	if(i>j)swap(i,j);
	c[i][j]-=v;
}
void add(ll i, ll j, ll v){
	if(i>j)swap(i,j);
	c[i][j]+=v;
}
ll get(ll i, ll j){
	if(i>j)swap(i,j);
	return c[i][j];
}
ll id[MAXN];
vector<ll>comp[MAXN];
ll n;
void uf_join(ll x, ll y){
	x=id[x],y=id[y];
	if(x==y)return;
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
	for(auto i:comp[y]){
		id[i]=x;
		comp[x].pb(y);
	}
	fore(j,0,n){
		ll v=get(j,y);
		erase(j,y,v);
		add(j,x,v);
	}
	comp[y].clear();
}
void initialize(int N){
	n=N;
	fore(i,0,n)id[i]=i,comp[i]={i};
	fore(i,0,n)fore(j,i+1,n)add(i,j,1);
}
int hasEdge(int u, int v){
	ll x=id[u],y=id[v];
	erase(x,y,1);
	ll va=get(x,y);
	if(va==0){
		uf_join(x,y);
		return 1;
	}
	return 0;
}

