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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

vv g[MAXN];

int main(){FIN;
	#ifdef ONLINE_JUDGE
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	#endif
	ll n,m,k; cin>>n>>m>>k;
	priority_queue<ll>pq,bag;
	vv ind(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		ind[v]++;
	}
	fore(i,0,n)if(!ind[i])pq.push(-i);
	vector<ii>ed;
	vv ans;
	while(SZ(pq)||SZ(bag)){
		ll x=-1,tag=0;
		if(SZ(pq))x=-pq.top(),pq.pop();
		else x=bag.top(),bag.pop(),tag=1;
		ll saco=0;
		if(!tag){
			ll voy=0;
			if(k){
				if(SZ(pq))voy=1;
				else if(SZ(bag)&&!(x>bag.top()))voy=1;
			}
			if(voy)k--,bag.push(x);
			else saco=1;
		}
		else {
			assert(SZ(ans));
			ed.pb({ans.back(),x});
			saco=1;
		}
		if(saco){
			// cout<<"saco\n";
			ans.pb(x);
			for(auto y:g[x])if(!--ind[y])pq.push(-y);
		}
	}
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	cout<<SZ(ed)<<"\n";
	for(auto i:ed)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}
