#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5*1e4;
const ll INF=1e6;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
ll n;
ll tt[MAXN];
ll g(ll x, ll y){
	return tt[x]+y-x;
}
ll dist[MAXN];
void dijkstra(ll x, ll r){
	mset(dist,-1);
	priority_queue<pair<ll,ii>> q;
	dist[x]=0; q.push({0,{x,x+1}});
	while(!q.empty()){
		x=q.top().snd.fst; ll c=-q.top().fst, z=q.top().snd.snd;q.pop();
		if(dist[x]!=c) continue;
		fore(i,z,min(x+r+1,n)){
		c=g(x,i);
		if(dist[i]<0 || dist[x]+c<dist[i])
		dist[i]=dist[x]+c,q.push({-dist[i],{i,x+r+1}});
		}
	}
}
int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("journey.in","r",stdin);     freopen("journey.out","w",stdout);
	#endif
	ll t;cin>>n>>t;
	ll p[n-1];
	fore(i,0,n-1) cin>>p[i];
	tt[0]=0; tt[n-1]=0;
	fore(i,1,n-1) cin>>tt[i];
	ll l=0, r=n-2;
	while(l<=r){
		ll h=(l+r)/2;
		dijkstra(0,h+1);
		if(dist[n-1]<=t) r=h-1;
		else l=h+1;
	}
	ll M=INF;
	fore(i,l,n-1)if(p[i]<M)M=p[i];
	cout<<M<<"\n";
	return 0;
}