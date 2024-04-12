#include "island.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=305;
ll dp[MAXN][MAXN];
ll ask(ll v, ll k){
	ll &res=dp[v][k];
	if(res!=-1)return res;
	return res=query(v+1,k+1)-1;
}
ll uf[MAXN],hay[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	assert(x!=y);
	if(-uf[x]>-uf[y])swap(x,y);
	uf[y]+=uf[x],uf[x]=y,hay[y]+=hay[x];
}
//vector<ll> g[MAXN];
ll num[MAXN],is[MAXN][MAXN];
vector<ii>res;
ll cnt=0;
void add_edge(ll x, ll y){
	if(x>y)swap(x,y);
	//g[x].pb(y),g[y].pb(x)
	res.pb({x,y});
	num[y]++;
	uf_join(x,y);
	cnt++;
}
void solve(int N, int L) {
	ll n=N,Q=L;
	mset(dp,-1);
	mset(uf,-1);
	fore(i,0,n)hay[i]=1;
	fore(x,0,n){
		hay[uf_find(x)]--;
		fore(i,num[x],n-1)if(cnt<n-1){
			ll y=ask(x,i),no=0;
			if(i&&dp[x][i-1]>y)no=1;
			//cout<<x<<" "<<y<<": "<<cnt<<"\n";
			if(!no&&(is[x][y]||!hay[uf_find(x)]||(uf_find(x)!=uf_find(y)&&ask(y,num[y])==x)))
				add_edge(x,y);
			else {
				if(uf_find(x)!=uf_find(y)){
					ll z=ask(y,num[y]);
					is[z][y]=is[y][z]=1;
				}
				break;
			}
		}
	}
	for(auto [u,v]:res)answer(u+1,v+1);
}
