#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=100;

vector<ll> g[MAXN];
ll n;
vv mintop(vector<ii> ed){
	for(auto [u,v]:ed)g[u].pb(v);
	vv ind(n);
	fore(x,0,n)for(auto y:g[x])ind[y]++;
	priority_queue<ll>pq;
	fore(x,0,n)if(!ind[x])pq.push(-x);
	vv ret;
	while(SZ(pq)){
		auto x=pq.top(); pq.pop(); x=-x;
		ret.pb(x);
		for(auto y:g[x])if(!--ind[y])pq.push(-y);
	}
	for(auto [u,v]:ed)g[u].pop_back();
	if(SZ(ret)<n)return {};
	return ret;
}

int main(){FIN;
	ll m,k; cin>>n>>m>>k;
	ll vis[n][n]; mset(vis,0);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		vis[u][v]=1;
	}
	// if(n==1){
	// 	cout<<"1\n";
	// 	return 0;
	// }
	vector<ii>can;
	fore(i,0,n)fore(j,0,n)if(i!=j&&!vis[i][j])can.pb({i,j});
	// for(auto i:can)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	vv res=mintop({});
	auto proba=[&](ll k){
		// cout<<"proba "<<SZ(can)<<" "<<k<<endl;
		vv per(SZ(can)-k,0); fore(i,0,k)per.pb(1);
		do{
			vector<ii>ed;
			fore(i,0,SZ(can))if(per[i])ed.pb(can[i]);
			res=max(res,mintop(ed));
			// imp(per)
		}while(next_permutation(ALL(per)));
		// ll mk=(1ll<<k)-1,r,c;
		// while(mk<=(1ll<<n)-(1ll<<(n-k))){
			
		// 	vector<ii>ed;
		// 	fore(i,0,SZ(can))if(mk>>i&1)ed.pb(can[i]);
		// 	res=max(res,mintop(ed));
		// 	if(!k)break;
		// 	c=mk&-mk,r=mk+c,mk=r|(((r^mk)>>2)/c);
		// }
	};
	fore(i,0,min(SZ(can),k)+1)proba(i);
	// imp(res);
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
