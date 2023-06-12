#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=503, INF=1e9*500*500+3;
ll g[MAXN][MAXN];
ll n;

void floyd(){
	fore(k,0,n)fore(i,0,n)if(g[i][k]!=INF)fore(j,0,n)if(g[k][j]!=INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]),
		g[j][i]=g[i][j];
}

int main(){FIN;
	ll m,q; cin>>n>>m>>q;
	fore(i,0,n){
		fore(j,0,n){
			g[i][j]=INF;
		}
	}
	fore(i,0,n)g[i][i]=0;
	fore(i,0,m){
		ll a,b,c; cin>>a>>b>>c; a--, b--;
		g[a][b]=min(g[a][b],c);
		g[b][a]=g[a][b];
	}
	floyd();
	while(q--){
		ll a,b; cin>>a>>b; a--, b--;
		if(g[a][b]==INF)cout<<-1;
		else cout<<g[a][b];
		cout<<"\n";
	}
	return 0;
}
