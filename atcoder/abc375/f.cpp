#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=305,INF=1e14;

ll g[MAXN][MAXN];
int n;
void add(int u, int v, ll w){
	if(w>=g[u][v])return;
	fore(i,0,n)fore(j,0,n){
		g[i][j]=g[j][i]=min(g[i][j],g[i][u]+w+g[v][j]);
	}
}

int main(){FIN;
	int m,q; cin>>n>>m>>q;
	vector<pair<ii,ll>>ed(m);
	vector<bool>vis(m);
	fore(i,0,m){
		int u,v,w; cin>>u>>v>>w; u--,v--;
		ed[i]={{u,v},w};
	}
	fore(i,0,n)fore(j,0,n)g[i][j]=INF;
	fore(i,0,n)g[i][i]=0;
	vector<ii>qs(q);
	fore(i,0,q){
		int ty; cin>>ty;
		if(ty==1){
			int p; cin>>p; p--;
			qs[i]={p,-1};
			vis[p]=1;
		}
		else {
			int x,y; cin>>x>>y; x--,y--;
			qs[i]={x,y};
		}
	}
	fore(i,0,m)if(!vis[i]){
		ll u=ed[i].fst.fst,v=ed[i].fst.snd,w=ed[i].snd;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	vv ans;
	reverse(ALL(qs));
	fore(i,0,q){
		if(qs[i].snd==-1){
			int p=qs[i].fst;
			add(ed[p].fst.fst,ed[p].fst.snd,ed[p].snd);
		}
		else {
			int x=qs[i].fst,y=qs[i].snd;
			ll res=g[x][y];
			if(res>=INF)res=-1;
			ans.pb(res);
		}
	}
	reverse(ALL(ans));
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}
