#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2005,MAXS=2000*2000*2/9+5;
vector<ii>g[MAXN];


ll tqrt(ll x){
	ll r=sqrt(x)-3;
	while(r<0||r*r<x)r++;
	return r;
}

vector<array<long long, 3>> Determina_aristas(int N,
vector<int> u, vector<int> v) {
	ll n=N,L=n*n*2/9+1;
	fore(i,0,n)g[i].clear();
	// ll is4=1;
	// fore(i,0,n-1)is4&=(u[i]==i+1&&v[i]==i);
	// assert(is4);
	vector<array<long long, 3>> res(n-1);
	fore(i,0,n-1)res[i]={u[i],v[i],0};
	fore(i,0,n-1){
		g[u[i]].pb({v[i],i});
		g[v[i]].pb({u[i],i});
	}
	ll x=0;
	fore(i,0,n)if(SZ(g[i])>1)x=i;
	res[g[x][0].snd][2]=1,res[g[x][1].snd][2]=n-1;
	ll j=2;
	fore(i,0,n-1){
		if(res[i][2])continue;
		res[i][2]=j++;
	}
	return res;
	/*vector<ll>val;
	ll sq=tqrt(L);
	fore(i,1,sq)val.pb(i),val.pb(sq*i);
	assert(SZ(val)<n);
	while(SZ(val)<n-1)val.pb(0);
	fore(i,0,n-1)res[i][2]=val[i];
	return res;*/
}