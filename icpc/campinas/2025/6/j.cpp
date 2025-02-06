#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn=1e5+10;
vv g[maxn];
int vis[maxn];

int main(){
	JET
	ll n; cin>>n;
	vv v(n);
	fore(i,0,n) cin>>v[i];
	sort(ALL(v));
	ll m; cin>>m;
	ll dist[m];
	ll cap[m];
	fore(i,0,m){
		ll x,y; cin>>x>>y;
		ll aux = v.end() - lower_bound(ALL(v),x);
		cap[i]=y*aux;
	}
	ll ar; cin>>ar;
	fore(i,0,ar){
		int a,b; cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	mset(dist,-1);
	vis[0]=1;
	priority_queue<pair<ii,ll>> pq;
	pq.push({{cap[0],0},cap[0]});
	while(SZ(pq)){
		auto [a,cap2] = pq.top();
		auto [cap1,idx] = a;
		pq.pop();
		dist[idx] = min(cap2,cap1);
		for(auto x:g[idx]){
			if(!vis[x]){
				vis[x]=1;
				pq.push({{cap[x],x},min(cap1,cap2)});
			}
		}
	}
	cout<<dist[m-1]<<"\n";
	return 0;
}