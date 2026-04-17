#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];
ll n;
vector<ll> dijkstra(ll s){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	pq.push({0,s});
	d[s]=0;
	while(SZ(pq)){
		auto [di,x]=pq.top(); pq.pop(); di=-di;
		if(d[x]<di)continue;
		for(auto [y,w]:g[x]){
			ll nd=di+w;
			if(d[y]==-1||nd<d[y])pq.push({-nd,y}),d[y]=nd;
		}
	}
	return d;
}



int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,k; cin>>n>>m>>k;
		ll a,b,l,r; cin>>a>>b>>l>>r;
		a--,b--;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		vector<ll>d[2];
		d[0]=dijkstra(a);
		d[1]=dijkstra(b);
		if(d[0][b]<k){
			cout<<"0\n";
			continue;
		}
		auto mayor=[&](){
			vector<ll>dis;
			fore(i,0,n)dis.pb(d[1][i]);
			sort(ALL(dis));
			auto get=[&](ll l, ll r){
				return ll(lower_bound(ALL(dis),r)-lower_bound(ALL(dis),l));
			};
			ll ans=0;
			fore(x,0,n){
				ll s=k-r-d[0][x],e=k-l-d[0][x]+1;
				ll res=get(s,e);
				// cout<<x<<": "<<res<<" --> ";
				for(auto [y,w]:g[x]){
					res-=s<=d[1][y]&&d[1][y]<e;
				}
				// cout<<res<<"\n";
				ans+=res;
			}
			cout<<ans<<"\n";
		};
		ll flag=d[0][b]==k;
		if(!flag){mayor();continue;}
		ll ans=0;
		fore(x,0,n)fore(y,0,n)if(x!=y){
			ll is=0;
			for(auto [j,w]:g[x])is|=j==y;
			if(is)continue;
			ll d0=d[0][x],d1=d[1][y];
			ll b0=d[0][y],b1=d[1][x];
			if(d0+d1<b0+b1||(d0+d1==b0+b1&&x<y)){
				if(d0+d1+l>=k)ans+=r-l+1;
				else ans+=max(0ll,d0+d1+r-k+1);
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}