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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

vector<ll>g[MAXN];
ll /*c[MAXN],*/t[MAXN];
ll cnt=0;
void dfs(ll x, ll f, ll b){
	//c[x]=b;
	if(!b)t[x]=cnt++;
	for(auto y:g[x])if(y!=f)dfs(y,x,b^1);
	if(b)t[x]=cnt++;
}

vector<int> label(int n, int k, vector<int> u, vector<int> v){
	fore(i,0,n){
		g[i].clear();
		t[i]=0;
	}
	cnt=0;
	fore(i,0,SZ(u)){
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}
	dfs(0,-1,1);
	vector<ll>res(n);
	fore(i,0,n)res[i]=t[i];
	return res;
}
int find_next_station(int s, int t, vector<int> v){
	ll c=0;
	for(auto i:v)if(i<s)c=1;
	if(!c){
		ll f=s;
		for(auto i:v)f=max(f,i);
		if(t<s)return f;
		for(auto i:v)if(t<=i)return i;
		return v.back();
	}
	else {
		ll f=s;
		for(auto i:v)f=min(f,i);
		if(t>s)return f;
		reverse(ALL(v));
		for(auto i:v)if(t>=i)return i;
		return v.back();
	}
}
