#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e4+5,MAXM=2*MAXN;

vector<ii> g[MAXN];
ll lw[MAXN],D[MAXN];
ll we[MAXM],vised[MAXM],br[MAXM];

void dfs(ll x){
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){
			D[y]=D[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			br[i]=lw[y]>=D[y];
		}
		else lw[x]=min(lw[x],D[y]);
	}
}

vector<ii> t[MAXN]; // only bridges

ll n,diam;
vv d;
vv nod;
void dfs2(ll x, ll fa){
	nod.pb(x);
	for(auto [y,w]:t[x])if(y!=fa){
		d[y]=d[x]+w;
		dfs2(y,x);
	}
}

int main(){
	TUCUTUCUTUCUTUCU
	ll m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		we[i]=w;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed.pb({u,v});
	}
	mset(lw,-1);
	dfs(0);
	ll cost=0;
	fore(i,0,m){
		cost+=we[i];
		auto [x,y]=ed[i];
		// cout<<x<<","<<y<<": "<<br[i]<<" "<<we[i]<<"\n";
		if(br[i]){
			cost+=we[i];
			t[x].pb({y,we[i]});
			t[y].pb({x,we[i]});
		}
	}
	// ll diam=0;
	d=vv(n,0);
	// fore(s,0,n)if(d[s]==-1){
	ll s=0;
	d[s]=0; dfs2(s,-1);
		// cout<<"start "<<s<<": ";
		// for(auto i:nod)cout<<i<<" ";;cout<<"\n";
	ll mx=s;
	for(auto i:nod)if(d[i]>d[mx])mx=i;
	ll diam=d[mx];
	
		// nod.clear(); d[mx]=0; dfs2(mx,-1);
		// for(auto i:nod)if(d[i]>d[mx])mx=i;
		// diam=max(diam,d[mx]);
	// }
	// cout<<cost<<" "<<diam<<"\n";
	ll res=cost-diam;
	cout<<res<<"\n";
	return 0;
}