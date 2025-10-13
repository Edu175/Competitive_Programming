#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=1000;
vector<pair<ii,ll>> g[maxn];
ll dst[maxn];
void dijkstra(int x){
	mset(dst,-1);
	priority_queue<ii> q; 
	dst[x]=0; q.push({0,x});
	while(!q.empty()){
		x=q.top().snd; ll c=-q.top().fst; q.pop();
		if(dst[x]!=c) continue;
		for(auto [p,i]: g[x]){
			auto [y,c]=p;
			if(dst[y]<0||dst[x]+c<dst[y])
				dst[y]=dst[x]+c,q.push({-dst[y],y});
		}
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("gas.in","r",stdin);     freopen("gas.out","w",stdout);
	#endif
	JET
	ll n,m,c; cin>>n>>m>>c;
	fore(i,0,m){
		ll a,b,w; cin>>a>>b>>w; a--,b--;
		g[a].pb({(ii){b,w},i});
		g[b].pb({(ii){a,w},i});
	}
	dijkstra(0);
	// cout<<"AAA";
	if(dst[n-1]>=c) cout<<"Fair\n";
	else{
		cout<<"Unfair\n";
		// cout<<endl;
		vv v;
		ll u=n-1;
		do{
			// cout<<u<<endl;
			for(auto [p,i]: g[u]){
				auto [y,w]=p;
				if(dst[u]==dst[y]+w){
					v.pb(i);
					u=y;
					break;
				}
			}
		}while(u);
		cout<<SZ(v)<<"\n";
		sort(ALL(v));
		for(auto i: v){
			cout<<i+1<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}