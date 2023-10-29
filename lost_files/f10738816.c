#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

const ll MAXN=100005, INF=1000000000000006;
bool vis[MAXN];
priority_queue<pair<ll,ll>> pq;
pair<ll,ll> dist[MAXN];
void dijkstra(ll v){
	vis[v]=1;
	
}

int main(){FIN;
	ll n; cin>>n;
	mset(dist,{INF,0});
	dist[0].fst=0;
	fore(i,0,n) pq.push({dist[i],i});
	return 0;
}
