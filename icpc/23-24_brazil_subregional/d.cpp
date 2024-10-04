#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll INF=1e14;
const ll MAXN=305,B=17;

ll g[MAXN][MAXN]; ll n;
struct floyd{
	ll n; vector<vv>d;
	floyd(ll n):n(n),d(n,vv(n)){
		fore(i,0,n)fore(j,0,n)d[i][j]=g[i][j];
	}
	void add(ll k){
		// cout<<"add "<<k<<"\n";
		fore(i,0,n)if(d[i][k]<INF)fore(j,0,n)if(d[k][j]<INF)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
	/*void prnt(){
		fore(i,0,n){
			fore(j,0,n)cout<<d[i][j]<<" ";
			cout<<endl;
		}
		cout<<"\n";
	}*/
};
vector<vv> d[MAXN];
int main(){JET
	ll m; cin>>n>>m; 
	fore(i,0,n){
		fore(j,0,n)g[i][j]=INF;
		g[i][i]=0;
	}
	vector<ii> q;
	fore(i,0,m){
		ll x,y,z;
		cin>>x>>y>>z;
		x--; y--;
		g[x][y]=g[y][x]=z;
		q.pb({x,y});
	}
	fore(i,0,n/B+1){
		// cout<<"bloque "<<i<<":\n";
		floyd fl(n);
		// fl.prnt();
		fore(x,0,n)if(x/B!=i)fl.add(x);
		// fl.prnt();
		fore(x,i*B,min((i+1)*B,n)){
			// cout<<x<<":\n";
			floyd my=fl;
			fore(y,i*B,min((i+1)*B,n))if(x!=y)my.add(y);
			d[x]=my.d;
			// my.prnt();
		}
	}
	fore(i,0,SZ(q)){
		ll x=q[i].fst,y=q[i].snd;
		ll rta=INF;
		fore(j,0,n){
			if(j==x || j==y) continue;
			rta=min(d[x][j][y]+g[x][j],rta);
		}
		if(rta==INF) cout<<-1<<"\n";
		else cout<<rta<<"\n";
	}
	return 0;
}


/*

bloque 0:
0 4 8 2 
4 0 4 100000000000000 
8 4 0 3 
2 100000000000000 3 0 

0 4 8 2 
4 0 4 100000000000000 
8 4 0 3 
2 100000000000000 3 0 

0:
add 1
add 2
add 3
0 4 5 2 
4 0 4 7 
5 4 0 3 
2 7 3 0 

1:
add 0
add 2
add 3
0 4 5 2 
4 0 4 6 
5 4 0 3 
2 6 3 0 

2:
add 0
add 1
add 3
0 4 5 2 
4 0 4 6 
5 4 0 3 
2 6 3 0 

3:
add 0
add 1
add 2
0 4 8 2 
4 0 4 6 
8 4 0 3 
2 6 3 0 




*/