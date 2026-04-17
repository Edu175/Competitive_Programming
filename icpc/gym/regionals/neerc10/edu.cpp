#include<bits/stdc++.h>
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
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN],dag[MAXN];


int main(){JET
#ifdef ONLINE_JUDGE
	freopen("ideal.in","r",stdin);     freopen("ideal.out","w",stdout);
	#endif
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	vector<ll>d(n,-1);
	queue<ll>q;
	d[0]=0;
	q.push(0);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto [y,w]:g[x]){
			if(d[y]==-1){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	assert(d[n-1]!=-1);
	fore(x,0,n)if(d[x]!=-1){
		for(auto [y,w]:g[x]){
			if(d[y]==d[x]+1)dag[x].pb({y,w});
		}
	}
	set<ll> h={0};
	vector<ll>res;
	// ll cnt=0;
	while(1){
		if(h.count(n-1))break;
		// cnt++;
		ll INF=1e15;
		ll mn=INF;
		for(auto x:h)for(auto [y,w]:dag[x])mn=min(mn,w);
		set<ll>hi;
		for(auto x:h)for(auto [y,w]:dag[x])if(mn==w){
			hi.insert(y);
		}
		swap(h,hi);
		res.pb(mn);
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i<<" ";;cout<<"\n";
}