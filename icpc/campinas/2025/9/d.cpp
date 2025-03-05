#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3005,INF=1e12; // 18e6 ??

vv g[MAXN];

ll n;
vv bfs(ll s){
	vv d(n,-1);
	d[s]=0;
	queue<ll>q; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

int main(){
	JET
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll l; cin>>l;
	vv p(l);
	fore(i,0,l)cin>>p[i],p[i]--;
	ll b; cin>>b;
	vv t(b);
	fore(i,0,b)cin>>t[i],t[i]--;
	vector<vv>d(n);
	fore(i,0,n)d[i]=bfs(i);
	
	vector<vv> dp(l+3,vv(k+3));
	
	for(ll i=l-2;i>=0;i--){
		vv dis(b,INF);
		fore(j,0,b){
			ll tmp=d[t[j]][p[i+1]];
			if(tmp<=k)dis[j]=tmp+dp[i+1][k-tmp];
		}
		// dijkstra O(b^2)
		vv vis(b);
		while(1){
			ll mn=-1;
			fore(i,0,b)if(!vis[i]&&(mn==-1||dis[i]<dis[mn]))mn=i;
			if(mn==-1)break;
			vis[mn]=1;
			fore(i,0,b){
				ll tmp=d[t[mn]][t[i]];
				if(tmp<=k)dis[i]=min(dis[i],dis[mn]+tmp);
			}
		}
		
		vector<ii>bet;
		fore(j,0,b){
			ll tmp=d[p[i]][t[j]];
			bet.pb({tmp,tmp+dis[j]});
		}
		sort(ALL(bet));
		fore(i,1,SZ(bet))bet[i].snd=min(bet[i].snd,bet[i-1].snd);
		fore(c,0,k+1){
			auto &res=dp[i][c];
			res=INF;
			ll dis=d[p[i]][p[i+1]];
			if(dis<=c)res=dis+dp[i+1][c-dis];
			// mejoro con los t
			auto it=upper_bound(ALL(bet),(ii){c+1,-1});
			if(it!=bet.begin())res=min(res,prev(it)->snd);
			// cout<<i<<" "<<c<<": "<<res<<"\n";
		}
	}
	ll res=dp[0][k];
	if(res>=INF)res=-1;
	cout<<res<<"\n";
	return 0;
}