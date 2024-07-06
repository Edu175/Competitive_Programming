#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dffyhg:v)cout<<dffyhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
int count_common_roads(const std::vector<int>& r);
ll ask(vector<ll>a){
	vector<int>r;
	for(auto i:a)r.pb(i);
	return count_common_roads(r);
}
const ll MAXN=505,MAXM=MAXN*MAXN/2;

vector<ii>g[MAXN];
ll good[MAXM],vised[MAXM],vis[MAXN],fa[MAXN],id[MAXN];
vector<pair<ii,ll>> ba;
vector<ll>r;
ll n;
void dfs(ll x){
	vis[x]=1;
	// cout<<"dfs "<<x<<"\n";
	for(auto [y,i]:g[x])if(fa[x]!=y){
		// cout<<"arista "<<x<<","<<y<<"\n";
		if(vis[y]){
			if(!vised[i]){
				vised[i]=1;
				ba.pb({{x,y},i});
			}
		}
		else {
			r.pb(i);
			fa[y]=x,id[y]=i;
			dfs(y);
		}
	}
}
void meto(ll x){
	r.pb(x);
}
void saco(ll x){
	r.erase(find(ALL(r),x));
}
std::vector<int> find_roads(int N, std::vector<int> u, std::vector<int> v){
	n=N;
	mset(good,-1);
	fore(i,0,SZ(u)){
		g[u[i]].pb({v[i],i});
		g[v[i]].pb({u[i],i});
	}
	ll rt=0;
	fa[rt]=id[rt]=-1;
	dfs(rt);
	// fore(i,0,n)cout<<id[i]<<" ";;cout<<"\n";
	// fore(i,0,n)cout<<fa[i]<<" ";;cout<<"\n";
	// imp(r);
	// for(auto i:ba)cout<<i.snd<<" ";;cout<<"\n";
	ll num=ask(r);
	for(auto [ar,i]:ba){
		auto [u,v]=ar;
		// cout<<u<<","<<v<<endl;
		vector<ll>h;
		ll x=u;
		while(x!=v){
			h.pb(id[x]);
			x=fa[x];
		}
		vector<ll>ig;
		meto(i);
		for(auto j:h){
			if(good[i]!=-1&&good[j]!=-1)continue;
			saco(j);
			ll val=ask(r),dif=val-num;
			if(dif==1)good[i]=1,good[j]=0;
			else if(dif==-1)good[i]=0,good[j]=1;
			else {
				ig.pb(j);
				if(good[j]!=-1)good[i]=good[j];
			}
			meto(j);
		}
		saco(i);
		if(good[i]==-1)good[i]=0;
		for(auto j:ig)good[j]=good[i];
	}
	vector<ll>res;
	fore(i,0,SZ(u))if(good[i]!=0)res.pb(i);
	return res;
}
