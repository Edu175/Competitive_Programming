#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=2e18;
typedef vector<vector<ll>> Matrix;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){	//no conmutativa
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m,INF));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]=min(r[i][j],a[i][k]+b[k][j]);
	return r;
}
Matrix be(Matrix b, ll e){	//b tiene que ser cuadrada
	Matrix r=b; e--;
	while(e){if(e&1ll)r=r*b; b=b*b; e/=2;}
	return r;
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<vector<ll>>g(n,vector<ll>(n,INF));
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u][v]=min(g[u][v],w);
	}
	//fore(i,0,n){imp(g[i]);}cout<<"\n";
	g=be(g,k);
	//fore(i,0,n){imp(g[i]);}cout<<"\n";
	ll res=g[0][n-1];
	if(res<INF)cout<<res<<"\n";
	else cout<<"-1\n";
	return 0;
}

