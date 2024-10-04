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
const ll MAXN=2e5+5;

vector<ii> g[MAXN];
ll hay[MAXN];
ll n;
ii cv(ll x){return {x/2,x%2};}
ll cv(ii x){return x.fst*2+x.snd;}
void dijkstra(ll s){
	vector<ll>d(2*n,-1);
	d[s]=0;
	priority_queue<ii>pq;
	pq.push({0,s});
	while(SZ(pq)){
		auto [ds,x]=pq.top(); pq.pop(); ds=-ds;
		if(d[x]<ds)continue;
		for(auto [y,w]:g[x]){
			ll nd=ds+(w);
			
		}
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
