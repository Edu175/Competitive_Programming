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
const ll MAXN=1e5+5;

set<ll> g[MAXN];
ll vis[MAXN];
vector<ll>a;
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
	a.pb(x);
}
void merge(vector<ll>&c){
	if(SZ(c)<=1)return;
	//imp(c);
	vector<ll>a,b;
	fore(i,0,SZ(c)){
		if(i<SZ(c)/2)a.pb(c[i]);
		else b.pb(c[i]);
	}
	merge(a); merge(b);
	ll l=0,r=0;
	c.clear();
	//imp(a); imp(b);
	while(l<SZ(a)||r<SZ(b)){
		//cout<<l<<","<<r<<"\n";
		ll ch=0;
		if(l==SZ(a))ch=1;
		else if(r<SZ(b)){
			if(g[b[r]].count(a[l]))ch=1;
			else if(!g[a[l]].count(b[r])&&b[r]<a[l])ch=1;
		}
		if(!ch)c.pb(a[l++]);
		else c.pb(b[r++]);
	}
	//imp(c);
	//cout<<"\n";
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].insert(v);
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	reverse(ALL(a));
	merge(a);
	for(auto i:a)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
