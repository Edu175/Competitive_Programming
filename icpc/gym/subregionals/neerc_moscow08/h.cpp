#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=80,INF=1e15,MAXD=75*1e9;

ll n;
ll g[MAXN][MAXN];

void floyd(){
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
	g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

ll diam(ll u, ll v, ll w){
	ll res=0;
	fore(i,0,n)fore(j,0,n){ //  /2 ?
		ll d=min({g[i][j],g[i][u]+w+g[v][j],g[j][u]+w+g[v][i]});
		// cout<<i<<","<<j<<": "<<d<<"\n";
		res=max(res,d);
	}
	// cout<<"diam "<<u<<" "<<v<<" "<<w<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	ll m; cin>>n>>m;
	fore(i,0,n)fore(j,0,n){
		if(i==j)g[i][j]=0;
		else g[i][j]=INF;
	}
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	floyd();
	ll res=INF;
	fore(u,0,n)fore(v,0,n)res=min(diam(u,v,0),res);
	// cout<<fixed<<setprecision(5);
	if(res>=INF){
		cout<<-1<<".00000 "<<-1<<".00000\n";
		return 0;
	}
	cout<<res<<".00000 ";
	// return 0;
	ll l=0,r=MAXD;
	while(l<=r){
		ll m=(l+r)/2;
		ll flag=0;
		fore(u,0,n)fore(v,0,n)flag|=diam(u,v,m)<=res;
		if(flag)l=m+1;
		else r=m-1;
	}
	if(r>=MAXD)cout<<-1<<".00000\n";
	else cout<<r<<".00000\n";
	return 0;
}
