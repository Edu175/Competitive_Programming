#include "Laberinto.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhj:v)cout<<dfhj<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=500*500*10+5,MAXN=500*500+5;
ll n;
ll cv(ii x){return x.fst*n+x.snd;}
ii cv(ll x){return {x/n,x%n};}
vector<ii>dir={{1,0},{0,1},{-1,0},{0,-1}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll h[505][505];
bool allowed(ii i){
	return i.fst>=0&&i.fst<n&&i.snd>=0&&i.snd<n&&h[i.fst][i.snd];
}
vector<ll>g[MAXN];
vector<ll>cost={0,0,0,1,2};
vector<ll>Per={0,2,1};
// vector<int> mover(int x);
vector<int> Pista(int N, vector<vector<int>> Laberinto) {
	n=N;
	fore(i,0,n*n)g[i].clear();
	fore(i,0,n)fore(j,0,n)h[i][j]=Laberinto[i][j];
	vector<ll>d(n*n,-1);
	vector<ll>ord;
	
	queue<ll>q;
	ll s=cv({n-2,1}),e=cv({1,n-2});
	d[s]=0; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		ord.pb(x);
		fore(j,0,4){
			auto i=cv(x)+dir[j];
			if(!allowed(i)){g[x].pb(-1);continue;}
			auto y=cv(i);
			g[x].pb(y);
			if(d[y]==-1)d[y]=d[x]+1,q.push(y);
		}
	}
	reverse(ALL(ord));
	vector<ll>dp(n*n,INF),ch(n*n,-1);
	vector<ll>lib[n*n];
	for(auto x:ord){
		fore(j,0,4){
			auto y=g[x][j];
			if(y==-1)continue;
			// cout<<x<<" "<<j<<": "<<y<<endl;
			lib[x].pb(j);
			// cout<<"paso"<<endl;
			if(!(d[y]==d[x]+1))continue;
			if(dp[y]<dp[x]/*||(dp[y]==dp[x]&&rand()%2==0)*/)
				ch[x]=j,dp[x]=dp[y];
		}
		dp[x]+=cost[SZ(lib[x])];
		if(x==e)dp[x]=0;
	}
	vector<int> p;
	auto x=s;
	ll ant=-1;
	while(x!=e){
		vector<ll>v;
		for(auto i:lib[x])if(i!=ant)v.pb(i);
		if(SZ(v)==2){
			p.pb(v[1]==ch[x]);
		}
		else if(SZ(v)==3){
			if(v[Per[0]]==ch[x])p.pb(0),p.pb(0);
			if(v[Per[1]]==ch[x])p.pb(0),p.pb(1);
			if(v[Per[2]]==ch[x])p.pb(1);//,p.pb(0);
		}
		ant=ch[x]^2;
		x=g[x][ch[x]];
	}
	return p;
}
void Juego(vector<int> p) {
	ll idx=0;
	auto u=mover(-1);
	ll ant=-1;
	vector<ll>I(3);
	fore(i,0,3)I[Per[i]]=i;
	auto go=[&](ll d){
		ant=d^2;
		u=mover(d);
		// cout<<"mover "<<d<<endl;
	};
	while(u!=vector<int>(4,0)){
		vector<ll>v;
		// imp(u);
		fore(j,0,4)if(j!=ant&&u[j])v.pb(j);
		assert(SZ(v));
		if(SZ(v)==1)go(v[0]);
		if(SZ(v)==2)go(v[p[idx++]]);
		if(SZ(v)==3){
			if(p[idx++])go(v[I[2]]);
			else go(v[I[p[idx++]]]);
		}
	}
}