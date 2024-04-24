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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=1e5+5;

vector<ll> g[MAXN][2];

ll rt[2];
vector<ll>ord[2];
ll S[MAXN][2],E[MAXN][2];
void dfs(ll x, ll w){
	S[x][w]=SZ(ord[w]);
	ord[w].pb(x);
	for(auto y:g[x][w])dfs(y,w);
	E[x][w]=SZ(ord[w]);
}
unordered_map<ll,ll> ft[MAXN+1];
void upd(int i0, int j0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j)
		ft[i][j]+=v;
}
int get(int i0, int j0){
	int r=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)
		r+=ft[i][j];
	return r;
}
int get_sum(int i0, int j0, int i1, int j1){
	return get(i1,j1)-get(i1,j0)-get(i0,j1)+get(i0,j0);
}
int main(){FIN;
	ll n; cin>>n;
	fore(w,0,2)fore(i,0,n){
		ll p; cin>>p; p--;
		if(p==-1)rt[w]=i;
		else g[p][w].pb(i);
	}
	fore(w,0,2)dfs(rt[w],w);
	fore(x,0,n){
		upd(S[x][0],S[x][1],1);
		//cout<<x<<": "<<S[x][0]<<","<<E[x][0]<<" "<<S[x][1]<<","<<E[x][1]<<"\n";
	}
	LL res=0;
	fore(x,0,n){
		ll resi=get_sum(S[x][0],S[x][1],E[x][0],E[x][1]);
		res+=resi;
		//cout<<x<<": "<<resi<<"\n";
	}
	cout<<res-n<<"\n";
	return 0;
}
