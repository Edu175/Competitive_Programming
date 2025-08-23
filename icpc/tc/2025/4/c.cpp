
#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;

vector<ii> g[MAXN];
vv dp[MAXN];
ll vis[MAXN],fal[MAXN];
vector<ii> best[MAXN]; // a lo sumo 3


ll f(ll x, ll fa){
	ll p=lower_bound(ALL(g[x]),ii({fa,-1}))-g[x].begin();
	if(fa==-1)p=SZ(g[x]);
	auto &res=dp[x][p];
	if(res!=-1)return res;
	auto &b=best[x];
	if(vis[x]==0){ // armo best
		for(auto [y,undir]:g[x])if(y!=fa){
			ll wh=(undir?y:-1);
			ll from=(undir?x:-1);
			b.pb({f(y,from),wh});
		}
		sort(ALL(b));
		reverse(ALL(b));
		if(SZ(b)>2)b.resize(2);
		if(fa!=-1)fal[x]=fa,vis[x]=1;
		else vis[x]=2;
	}
	else if(vis[x]==1&&fa!=fal[x]){ // agrego fal
		for(auto [y,undir]:g[x])if(y==fal[x]){
			// cout<<x<<" "<<fa<<" agrega fal "<<fal[x]<<": "<<y<<" "<<x<<"\n";
			assert(undir);
			b.pb({f(y,x),y});
		}
		vis[x]=2;
	}
	// la info es reliable
	res=0;
	for(auto [val,wh]:b)if(fa==-1||wh!=fa)res=max(res,val+1);
	// cout<<x<<" "<<fa<<": "<<vis[x]<<" "<<fal[x]<<": ";
	// for(auto [val,wh]:b)cout<<val<<","<<wh<<" ";;cout<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			fal[i]=-1;
			vis[i]=0;
			best[i].clear();
		}
		fore(i,0,m){
			ll u,v; string s; cin>>u>>s>>v; u--,v--;
			bool undir=s=="--";
			g[u].pb({v,undir});
			if(undir)g[v].pb({u,undir});
		}
		fore(i,0,n){
			dp[i]=vv(SZ(g[i])+1,-1);
			sort(ALL(g[i]));
			// cout<<"g "<<i<<": ";
			// for(auto j:g[i])cout<<j.fst<<","<<j.snd<<" ";;cout<<"\n";
		}
		ll res=0;
		fore(x,0,n)res=max(res,f(x,-1));
		cout<<res<<"\n";
	}
	return 0;
}

