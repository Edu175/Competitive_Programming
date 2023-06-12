#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXP=1e18;

vector<ii>gn[MAXN];
vector<ii>g[MAXN];
ll fqrt(ll x){
	ll r=sqrt(x);
	for(;r<0||r*r<=x;r++);
	return r-1;
}
ll cost(ll p, ll t){
	ll l=1,r=2*p;
	while(l<=r){
		ll m=(l+r)/2;
		if(m+t*fqrt(m)>=p)r=m-1;
		else l=m+1;
	}
	return l;
}
ll d[MAXN],f[MAXN],w[MAXN],n;
void dijkstra(){
	mset(d,-1);
	priority_queue<ii>pq;
	pq.push({-1,1});
	while(SZ(pq)){
		auto i=pq.top(); pq.pop();
		auto x=i.snd,p=-i.fst;
		if(d[x]!=-1&&d[x]<p)continue;
		for(auto j:g[x]){
			auto y=j.fst,t=j.snd;
			ll pi=cost(p,t);
			pi+=w[y];
			if(d[y]==-1||pi<d[y])d[y]=pi,f[y]=x,pq.push({-d[y],y});
		}
	}
}
long long heroe(vector<int> &a, vector<int> &b, vector<int> &t, vector<int> &e, vector<int> &secuencia) {
	n=SZ(e);
	fore(i,0,n)w[i]=e[i];
	fore(i,0,SZ(a)){
		ll u=a[i],v=b[i]; u--,v--;
		gn[u].pb({v,t[i]});
		g[v].pb({u,t[i]});
	}
	f[1]=-1;
	dijkstra();
	ll res=d[0];
	vector<ll>ans;
	for(ll x=0;x!=-1;x=f[x])ans.pb(x);
	secuencia.clear();
	for(auto i:ans)secuencia.pb(i+1);
	return res;
}
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
