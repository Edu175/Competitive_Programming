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
struct UF{
	vector<vector<ll>> comp;
	vector<ll> id;
	void init(ll n){
		comp.resize(n),id.resize(n);
		fore(i,0,n){
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
};
void cycle(vector<ll>a){
	if(SZ(a)==1)return;
	fore(i,0,SZ(a)){
		g[a[i]][a[(i+1)%SZ(a)]]=1;
		g[a[(i+1)%SZ(a)]][a[i]]=1;
	}
}
void line(vector<ll>a){
	fore(i,0,SZ(a)-1){
		g[a[i]][a[i+1]]=1;
		g[a[i+1]][a[i]]=1;
	}
}

int construct(std::vector<std::vector<int>> P){
	ll n=SZ(P);
	g.resize(n,vector<int>(n));
	fore(i,0,n)fore(j,0,n)p[i][j]=P[i][j];
	// sub all 0, all 1, all 2
	uf_init();
	fore(i,0,n)fore(j,0,n)if(p[i][j])join(i,j);
	UF uf;
	uf.init(n);
	fore(i,0,n)fore(j,0,n)if(p[i][j]==1)uf.join(i,j);
	ll flag=1;
	/*fore(i,0,n)fore(j,0,n){
		if(p[i][j]==3)flag=0;
	}*/
	//if(!flag)return 0; //(not necessary)
	fore(x,0,n){
		if(SZ(comp[x])<=1)continue;
		//self-loop? none (not neccessary)
		//if(SZ(comp[x])==2)flag=0;
		vector<ll>a=comp[x];
		vector<ll>c; //cycle
		set<ll>st;
		for(auto i:a)st.insert(uf.id[i]);
		for(auto i:st)c.pb(i);
		if(SZ(c)==2)flag=0;
		cycle(c);
		for(auto y:c)line(uf.comp[y]);
		//check all p(i,j) non-zero ADD 1 or 2
		for(auto i:a)for(auto j:a){
			if(p[i][j]==0)flag=0;
			if(uf.id[i]==uf.id[j]){
				if(p[i][j]!=1)flag=0;
			}
			else {
				if(p[i][j]!=2)flag=0;
			}
		}
	}
	if(!flag)return 0;
	build(g);
	return 1;
}
