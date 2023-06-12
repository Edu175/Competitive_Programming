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
const ll MAXN=2e5+5;

ll tr[MAXN][30],qidx=0;
ll id[355],h[MAXN];
vector<ll>g[MAXN];
ll add(ll x, char c){
	ll &res=tr[x][c-'A'];
	if(res!=-1)return res;
	res=++qidx;
	g[x].pb(res);
	g[res].pb(x);
	return res;
}
ll d[355][MAXN];
/*void dfs(ll x, ll f, ll s){
	for(auto y:g[x])if(y!=f){
		d[s][y]=d[s][x]+1;
		dfs(y,x,s);
	}
}*/
void bfs(ll s){
	queue<pair<ll,ll>>q;
	q.push({id[s],-1});
	while(SZ(q)){
		auto i=q.front(); q.pop();
		ll x=i.fst,f=i.snd;
		for(auto y:g[x])if(y!=f){
			d[s][y]=d[s][x]+1;
			q.push({y,x});
		}
	}
}
int maquina(int T, vector<string> &lineas, vector<string> &orden) {
	mset(tr,-1); mset(h,-1);
	ll n=SZ(lineas),t=T;
	vector<string>a=lineas;
	fore(i,0,n){
		ll x=0;
		for(auto j:a[i]){
			x=add(x,j);
		}
		id[i]=x;
		h[x]=i;
	}
	fore(i,0,n)bfs(i);
	vector<ll> ord;
	fore(i,0,n)ord.pb(i);
	ll res=1e16;
	vector<ll>ans;
	do{
		ll resi=d[ord[0]][0];
		fore(i,1,n)
			resi+=min(t+d[ord[i]][0],d[ord[i-1]][id[ord[i]]]);
		if(resi<res)ans=ord,res=resi;
	}
	while(next_permutation(ALL(ord)));
	orden.clear();
	for(auto i:ans)orden.pb(a[i]);
	return res+n;
}
