#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
const ll MAXN=405,INF=1e15;

ll g[MAXN][MAXN];

struct floyd{
	ll t[MAXN][MAXN]; ll n;
	floyd(ll n):n(n){fore(i,0,n)fore(j,0,n)t[i][j]=g[i][j];}
	void upd(ll k){
		fore(i,0,n)if(t[i][k]<INF)fore(j,0,n)if(t[k][j]<INF)
			t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
	}
};
struct qu{
	ll u,v,idx;
};
int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii>a(n);
	vector<ll>p(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	fore(i,0,n)fore(j,0,n){
		if(i==j)g[i][j]=0;
		else g[i][j]=INF;
	}
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u][v]=g[v][u]=w;
	}
	vector<qu>pre[n],suf[n];
	ll q; cin>>q;
	fore(i,0,q){
		ll u,v,k,ty; cin>>u>>v>>k>>ty; u--,v--; k--;
		if(!ty)pre[k].pb(qu({u,v,i}));
		else suf[k].pb(qu({u,v,i}));
	}
	
	
	sort(ALL(a));
	fore(i,0,n){
		if(i&&a[i].fst==a[i-1].fst)p[a[i].snd]=p[a[i-1].snd];
		else p[a[i].snd]=i?p[a[i-1].snd]+1:0;
	}
	vector<ll> h[n];
	fore(i,0,n)h[p[i]].pb(i);
	floyd r(n);
	vector<ll>ans(q);
	fore(v,0,n){
		for(auto x:h[v])r.upd(x);
		for(auto q:pre[v]){
			ll resi=r.t[q.u][q.v];
			// if(p[q.u]>v||p[q.v]>v)resi=-1;
			ans[q.idx]=resi;
		}
	}
	
	
	fore(i,0,n)h[i].clear();
	
	reverse(ALL(a));
	fore(i,0,n){
		if(i&&a[i].fst==a[i-1].fst)p[a[i].snd]=p[a[i-1].snd];
		else p[a[i].snd]=i?p[a[i-1].snd]+1:0;
	}
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	// for(auto i:p)cout<<i<<" ";;cout<<"\n";
	fore(i,0,n)h[p[i]].pb(i);
	r=floyd(n);
	fore(v,0,n){
		for(auto x:h[v])r.upd(x);
		for(auto q:suf[v]){
			ll resi=r.t[q.u][q.v];
			// cout<<v<<": query "<<q.u<<","<<q.v<<"\n";
			// if(p[q.u]>v||p[q.v]>v)resi=-1;
			ans[q.idx]=resi;
		}
	}
	for(auto v:ans){
		if(v>=INF)cout<<"-1\n";
		else cout<<v<<"\n";
	}
	return 0;
} 