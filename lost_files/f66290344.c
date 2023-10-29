#include "supertrees.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto dfh:v)cout<<dfh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

ll p[MAXN][MAXN];
vector<vector<int>>g;

vector<ll> comp[MAXN];
ll id[MAXN];
void uf_init(){
	fore(i,0,MAXN){
		comp[i]={i};
		id[i]=i;
	}
}

bool join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i),id[i]=b;
	comp[a].clear();
	return 1;
}

int construct(std::vector<std::vector<int>> P){
	ll n=SZ(P);
	g.resize(n,vector<int>(n));
	fore(i,0,n)fore(j,0,n)p[i][j]=P[i][j];
	// sub all 0, all 1, all 2
	uf_init();
	fore(i,0,n)fore(j,0,n)if(p[i][j])join(i,j);
	ll flag=1;
	fore(x,0,n){
		if(SZ(comp[x])<=1)continue;
		//self-loop? none
		if(SZ(comp[x])==2)flag=0;
		//check all p(i,j) non-zero
		vector<ll>a=comp[x];
		fore(i,0,SZ(a))fore(j,0,SZ(a))if(p[a[i]][a[j]]==0)flag=0;
		//sub all 1
		fore(i,0,SZ(a)){
			g[a[i]][a[(i+1)%SZ(a)]]=1;
			g[a[(i+1)%SZ(a)]][a[i]]=1;
		}
	}
	if(!flag)return 0;
	build(g);
	return 1;
}
