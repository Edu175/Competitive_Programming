#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<endl;}
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXV=1e6+5,MAXN=2e5+5; // CAMBIARRRR xd no lo cambie

vector<ll>divs[MAXV];
ll did=0;
void init_sieve(){
	fore(i,1,MAXV)for(ll j=i;j<MAXV;j+=i)divs[j].pb(i);
}
ll n;
vector<ll> g[MAXN];
vector<ll> idx[MAXV];
ll d[MAXN];

ll bfs(ll s){ //devuelve diametro del tree
	queue<ll>q;
	d[s]=0;
	q.push(s);
	ii res={0,s};
	vector<ll>pop;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		pop.pb(x);
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			res=max(res,{d[y],y});
			q.push(y);
		}
	}
	for(auto i:pop)d[i]=-1;
	
	s=res.snd;
	ll ans=0;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			ans=max(ans,d[y]);
			q.push(y);
		}
	}
	return ans;
}
LL get(vector<ll>&h){ //devuelve diametro del forest
	ll res=0;
	for(auto x:h)if(d[x]==-1){
		res=max(res,bfs(x));
	}
	for(auto x:h)d[x]=-1;
	return res;
}
ll used[MAXV];
long long int Arbolstian(int N, vector<int> u,
vector<int> v, vector<int> w) {
	if(!did++){
		init_sieve();
	}
	n=N;
	fore(i,0,n)d[i]=-1;
	vector<ll>us;
	fore(i,0,SZ(u)){
		for(auto d:divs[w[i]]){
			idx[d].pb(i);
			if(!used[d])us.pb(d),used[d]=1;
		}
	}
	LL res=0;
	vector<ll>vis(n);
	// imp(us);
	for(auto d:us){
		assert(SZ(idx[d]));
		vector<ll>h;
		for(auto i:idx[d]){
			g[u[i]].pb(v[i]);
			g[v[i]].pb(u[i]);
			if(!vis[u[i]])h.pb(u[i]),vis[u[i]]=1;
			if(!vis[v[i]])h.pb(v[i]),vis[v[i]]=1;
		}
		res=max(res,d*get(h));
		for(auto i:h){
			g[i].clear();
			vis[i]=0;
		}
		idx[d].clear();
	}
	for(auto i:us)used[i]=0;
	return res;
}