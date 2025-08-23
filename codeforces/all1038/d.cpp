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
const ll MAXN=5005;

vector<ll> g[MAXN];
vector<ii> ed;
ll n;
void dijkstra(ll s){
	vv d(n,-1);
	priority_queue<ii>pq;
	while(SZ(pq)){
		auto [x,dis]=pq.top(); pq.pop(); dis=-dis;
		if(dis!=d[x])continue;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		
	}
	return 0;
}
