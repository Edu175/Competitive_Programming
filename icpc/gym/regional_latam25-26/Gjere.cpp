#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
const int maxn = 1e5;
vv g[maxn];
vv gc[maxn];

ll n,m;

ll p(int x, int y){
    return x*m + y;
}
ii pp(ll x){
	return {x/m , x%m};
}


const ll INF = 3e18;

struct Dinic{
	int nodes,src,dst;
	ll res = 0;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap,a,b;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap, ll a, ll b){
		// cout<<"metiendo arista "<<s<<" to "<<t<<"\n";
		g[s].pb((edge){t,SZ(g[t]),0,cap,a,b});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,0,0});
	}
	void reset(ll k){
		bool b = false;
		for(auto &v:g)for(auto &x:v) {
			x.cap = x.a + x.b * k;
			if(x.cap < x.f) b = true;
		}
		if(b){
			for(auto &v:g)for(auto &x:v) x.f = 0;
			res = 0;
		}
		// fore(i,0,nodes)for(auto x:g[i]) cout<<"tengo arista "<<i<<" to "<<x.to<<"  cap: "<<x.cap<<"\n";
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst, ll k){
		reset(k);
		src=_src;dst=_dst;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))res+=delta;
		}
		return res;
	}
};
const int maxl = 305;
vv ori(maxn);
vv cam(maxn);
ll o[maxn], ca[maxn];
ll last = -1;


// ll solve(ll x){
//     ll st = n*m*2, end = n*m*2+1;
//     Dinic d(n*m*2+2);
// 	if(last<0) return 0;
//     d.add_edge(st,0,INF);
//     d.add_edge(last*2+1,end,INF);
// 	// cout<<"adding edge "<<st<<" "<<0<<"    cap: inf\n";
// 	// cout<<"adding edge "<<last*2+1<<" "<<end<<"     cap:inf\n";
//     fore(i,0,n*m){
// 		// cout<<"adding edge "<<2*i<<" -> "<<2*i+1<<"   cap: "<<o[i] + ca[i]*x<<"\n";
//         d.add_edge(2*i,2*i+1,o[i] + ca[i]*x);
//     }
//     fore(i,0,n*m) for(auto x:gc[i])if(x >= 0){
// 		// cout<<"adding edge "<<2*i+1<<" -> "<<2*x<<"   cap: inf\n";
//         d.add_edge(2*i + 1,2*x,INF);
//     }
//     return d.max_flow(st,end);
// }

vv ord;
ll vis[maxl*maxl];
void dfs(ll x){
	vis[x] = 1;
	ord.pb(x);
	for(auto y:g[x]) if(!vis[y])dfs(y);
}

int main(){
    JET
    ll ar,k;
    cin>>n>>m>>ar>>k;
    fore(i,0,n) fore(j,0,m) cin>>ori[p(i,j)];
    fore(i,0,n)fore(j,0,m) cin>>cam[p(i,j)];
    vector<ii> ed(ar);
    fore(i,0,ar){
		ll x,y,x1,y1; cin>>x>>y>>x1>>y1;
        x--,y--,x1--,y1--;
        g[p(x,y)].pb(p(x1,y1));
		g[p(x1,y1)].pb(p(x,y));
    }
	dfs(0);
	ll rev[maxl*maxl];
	Dinic d(2*n*m+2);
    ll st = n*m*2, end = n*m*2+1;

	fore(i,0,SZ(ord)){
		rev[ord[i]] = i;
		// cout<<"nodo "<<ord[i]<<" ahora se llama "<<i<<"\n";
		if(ord[i] == n*m-1) last = i;
		o[i] = ori[ord[i]];
		ca[i] = cam[ord[i]];
		d.add_edge(2*i,2*i+1,0,o[i],ca[i]);
	}
	if(last < 0){
		cout<<0<<"\n";
		return 0;
	}
	d.add_edge(st,0,INF,INF,0);
    d.add_edge(last*2+1,end,INF,INF,0);
	fore(i,0,n*m)if(vis[i])for(auto y:g[i])if(vis[y]){
		gc[rev[i]].pb(rev[y]);
		d.add_edge(2 * rev[i] + 1,2*rev[y],INF, INF, 0);
	}
	ori.clear(); cam.clear();
	// ll l1 = 0, r1 = k;
	// while(l1<r1){
	// 	ll m1 = (l1+r1)/2;
	// 	if(dfs(0,m1)) l1 = m1+1;
	// 	else r1 = m1;
	// }
    ll l = 1, r = k;
	// cout<<d.max_flow(st,end,0)<<"\n";
	// cout<<d.max_flow(st,end,0)<<"\n";

	// return 0;
	// ll aux,aux1;
	// solve(0);
	// return 0;
    while(l<r){
        ll m = (l+r)/2;
        ll f = d.max_flow(st,end,m);
		ll f1 = d.max_flow(st,end,m+1);
        if(f <= f1){
			l = m + 1;
		}
        else{
			r = m;
		}
    }
	// assert(l == 0 || solve(l) >= solve(l-1));
	// assert(l <= 1 || solve(l) >= solve(l-2));
    cout<<max(d.max_flow(st,end,l),max(d.max_flow(st,end,0),d.max_flow(st,end,k)))	<<"\n";
	// cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cerr<<l<<" "<<d.max_flow(st,end,l)<<"\n";
    return 0;
}