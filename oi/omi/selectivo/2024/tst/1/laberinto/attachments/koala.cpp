#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhj:v)cout<<dfhj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=500*500+5;
ll n;
ll cv(ii x){return x.fst*n+x.snd;}
ii cv(ll x){return {x/n,x%n};}
vector<ii>dir={{1,0},{0,1},{-1,0},{0,-1}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}

vector<ii>ed;
ll c[MAXN][4];
ll neg(ll x){
	ii p=cv(x);
	return cv({n-1-p.fst,n-1-p.snd});
}


int Flamante_Koala(int K, int N, vector<int> r1, vector<int> c1,
vector<int> r2, vector<int> c2) {
	n=K;
	ed.clear();
	// res=cnt=0;
	fore(i,0,n*n)fore(j,0,4)c[i][j]=0;
	fore(i,0,N){
		ed.pb({cv({r1[i]-1,c1[i]-1}),cv({r2[i]-1,c2[i]-1})});
		ll x=ed.back().fst,y=ed.back().snd;
		ll po=-1;
		fore(j,0,4){
			auto k=cv(x)+dir[j];
			if(cv(k)==y)po=j;
		}
		c[x][po]++;
		c[y][po^2]++;
	}
	
	random_shuffle(ALL(ed));
	vector<ll>id; vector<vector<ll>>comp;
	fore(i,0,n*n)id.pb(i),comp.pb({i});
}
