#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e4+5;
// random_device rd;
// mt19937_64 rng(rd());
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
vector<ii> g[MAXN];

ll D[MAXN],vis[MAXN],vised[MAXN];
ii cer[MAXN];
ll tot;
ii has[MAXN]; // la arista
vector<ll>ba;
ii dfs(ll x){
	// cout<<"dfs "<<x<<"\n";
	vis[x]=1;
	ii h={0,0};
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			D[y]=D[x]+1;
			has[i]=dfs(y);
			h=h+has[i];
		}
		else {
			// cout<<"back "<<x<<" "<<y<<" "<<i<<"\n";
			ll typ=abs(D[y]-D[x])&1;
			typ^=1;
			if(typ){ // back edge impar
				cer[y].snd++;
				tot++;
				h.snd++;
				ba.pb(i);
			}
			else {
				cer[y].fst++;
				h.fst++;
			}
		}
	}
	h.fst-=cer[x].fst;
	h.snd-=cer[x].snd;
	return h;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	vv res;
	fore(i,0,m)if(has[i].snd==tot&&!has[i].fst)res.pb(i),cout<<i<<" spf\n";
	// cout<<"ba\n";
	// for(auto i:ba)cout<<i<<" ";;cout<<"\n";
	if(SZ(ba)==1)res.pb(ba[0]);
	
	if(!tot){
		cout<<m<<"\n";
		fore(i,0,m)cout<<i+1<<" ";
		cout<<"\n";
		return 0;
	}
	// cout<<tot<<"\n";
	// fore(i,0,m)cout<<has[i].fst<<","<<has[i].snd<<" ";;cout<<"\n";
	
	sort(ALL(res));
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
