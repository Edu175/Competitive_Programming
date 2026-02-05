#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;

vv g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		vv deg(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
			deg[u]++;deg[v]++;
		}
		vv ans(n);
		vv cur;
		fore(i,0,n)if(deg[i]==1)cur.pb(i);
		vv vis(n);
		ll col=0,d=0;
		while(SZ(cur)){
			vv prox;
			for(auto i:cur)vis[i]=1;
			map<ll,ll> mp;
			for(auto x:cur){
				for(auto y:g[x])if(!vis[y]){
					if(--deg[y]==1)prox.pb(y);
					mp[y]++;
				}
			}
			if(!SZ(mp))break;
			vector<ii> sd;
			for(auto [x,c]:mp)sd.pb({c,x});
			sort(ALL(sd)); reverse(ALL(sd));
			ll ex=0;
			fore(i,0,SZ(sd)){
				ll c=sd[i].snd;
				col+=c;
				if(c>1)ex=1;
				
			}
		}
		for(ll i=n-1;i>=0;i--)ans[i]=min(ans[i],ans[i+1]);
		fore(i,1,n)cout<<ans[i]<<" ";;cout<<"\n";
		// cerr<<"\n";
	}
	return 0;
}
