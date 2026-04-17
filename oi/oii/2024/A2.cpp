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
#define bint __int128
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
		ll valid=0;
		set<ii>st;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
			if(u<v)swap(u,v);
			if(!st.count({u,v})){
				valid+=u!=v;
				st.insert({u,v});
			}
		}
		vector<ll>d[2];
		d[0]=dijkstra(a);
		d[1]=dijkstra(b);
		if(d[0][b]<k){ // o <
			cout<<"0\n";
			continue;
		}
		ll flag=d[0][b]==k;
		vector<ll>dis,sp(n+1);
		fore(i,0,n)dis.pb(d[1][i]);
		sort(ALL(dis));
		fore(i,1,n+1)sp[i]=sp[i-1]+dis[i-1];
		auto get=[&](ll l, ll r){
			return ll(lower_bound(ALL(dis),r)-lower_bound(ALL(dis),l));
		};
		ll ans=0;
		// imp(dis) imp(sp)

		fore(i,0,n)g[i].pb({i,1});
		fore(x,0,n)fore(y,0,n)if(x!=y){
			ll is=0;
			for(auto [j,w]:g[x])is|=j==y;
			if(is)continue;
			ll d0=d[0][x],d1=d[1][y];
			if(!flag){
				if(d0+d1>=k)ans+=r-l+1;
				else if(d0+d1+r>=k)ans+=k-(d0+d1);
			}
			else ans+=d0+d1+l<=k&&k<=d0+d1+r;
		}
		/*fore(x,0,n){
			ll res=0;
			if(!flag){
				ll s=k-r-d[0][x],e=k-l-d[0][x]+1;
				res=get(s,e);
				// cout<<x<<": "<<res<<" --> ";
				for(auto [y,w]:g[x]){
					res-=s<=d[1][y]&&d[1][y]<e;
				}
				// cout<<res<<"\n";
			}
			else {
				ll e=k-d[0][x];
				ll p=lower_bound(ALL(dis),e)-dis.begin();
				ll qan=n-p;
				ll s=k-d[0][x]-r;
				ll q=lower_bound(ALL(dis),s)-dis.begin();
				ll val=(p-q)*dis[p]-(sp[p]-sp[q]);
				// cout<<x<<": "<<s<<","<<e<<": "<<q<<","<<p<<": "<<val<<" "<<qan<<" --> ";
				for(auto [y,w]:g[x]){
					ll d1=d[1][y];
					if(d1>=e)qan--;
					if(s<=d1&&d1<e)val-=k-d[0][x]-d1;
				}
				// cout<<val<<" "<<qan<<"\n";
				res=qan*(r-l+1)+val;
			}
			// cout<<res<<"\n";
			ans+=res;
		}*/
		if(flag)ans/=2;
		cout<<ans<<"\n";
	}
	return 0;
}