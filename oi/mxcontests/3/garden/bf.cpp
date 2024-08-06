#include "garden.h"
#include "gardenlib.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=300005;

vector<ll> g[MAXN];

ll n,p;
ll go(ll u, ll v){
	if(SZ(g[v])==1)return 2*v;
	if(g[v][0]==u)return 2*v+1;
	return 2*v;
}
ll a[MAXN];

void count_routes(int N, int m, int P, int R[][2], int q, int qs[])
{
	n=N,p=P;
	fore(i,0,m){
		ll u=R[i][0],v=R[i][1];
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(x,0,n){
		a[2*x]=go(x,g[x][0]);
		if(SZ(g[x])>1)a[2*x+1]=go(x,g[x][1]);
	}
	fore(_,0,q){
		ll res=0;
		ll k=qs[_];
		fore(x,0,2*n)if(!(x&1)){
			ll y=x;
			fore(__,0,k)y=a[y];
			// cout<<x<<" --> "<<y<<"\n";
			res+=y/2==p;
		}
		answer(res);
	}
}


