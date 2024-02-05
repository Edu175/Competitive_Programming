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
const ll MAXN=2e5+5,MAXM=2*MAXN;

queue<ii> g[MAXN];
ii a[MAXM];
ll vis[MAXM];
ll L[MAXM],R[MAXM];

ll go(ll idx){
	cout<<"go "<<idx<<"\n";
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

int main(){FIN;
	ll n,m; cin>>n>>m;
	a[m]={-1,0};
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].push({v,i});
		g[v].push({u,i});
		a[i]={u,v};
	}
	a[m+1]={-1,-1};
	R[0]=m+1;
	ll idx=m;
	vis[idx]=1;
	while(idx!=m+1){
		cout<<idx<<":\n";
		ll x=a[idx].snd;
		while(SZ(g[x])){
			auto [y,i]=g[x].front(); g[x].pop();
			if(vis[i])continue;
			ll rs=R[idx];
			R[idx]=i;
			R[go(i)]=rs;
		}
		idx=R[idx];
	}
	idx=m;
	vector<ll>res;
	while(idx!=m+1)res.pb(a[idx].snd),idx=R[idx];
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
