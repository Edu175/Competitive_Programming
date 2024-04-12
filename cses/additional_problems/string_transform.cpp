#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=30;
queue<ii> g[MAXN]; // graph with node, edge index
ii a[MAXM]; // array with m edges
ll vis[MAXM];
ll R[MAXM];
ll go(ll idx){
	ll x=a[idx].snd;
	while(SZ(g[x])){
		auto [y,i]=g[x].front(); g[x].pop();
		if(vis[i])continue;
		if(a[i].snd!=y)swap(a[i].fst,a[i].snd);
		R[idx]=i;
		vis[i]=1;
		return go(i);
	}
	return idx;
}
vector<ll> euler_path(ll s){
	ll flag=1;
	//ll cnt=0;
	//fore(i,0,n)cnt+=SZ(g[i])&1);
	//if(cnt!=0&&cnt!=2)flag=0; // condition for circuit/path
	ll idx=m;
	a[m]={-1,s}; // start
	a[m+1]={-1,-1}; // end
	R[m]=m+1;
	vis[idx]=1;
	while(idx!=m+1){
		ll rs=R[idx],e=go(idx);
		if(e==idx)idx=R[idx];
		else R[e]=rs;
	}
	fore(i,0,n)if(SZ(g[i]))flag=0;
	idx=m;
	vector<ll>res;
	while(idx!=m+1){
		if(SZ(res)&&a[idx].fst!=res.back())flag=0; // generic condition
		res.pb(a[idx].snd),idx=R[idx];
	}
	if(!flag)return {};
	return res;
}
int main(){FIN;
	//cout<<int('#')<<" "<<int('$')<<" "<<int('a')<<"\n";
	
	return 0;
}
