#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const vv MODS={611106846/*,567514317*/,ll(1e9)+7};
// int add(int a, int b){a+=b; if(a>=MOD)a-=MOD;return a;}
// ll mul(ll a, ll b){return a*b%MOD;}
typedef vector<vector<ll>> Matrix;
ll pos=-1;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){
	const ll MOD=MODS[pos];
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z){
		r[i][j]=(r[i][j]+LL(a[i][k])*b[k][j])%MOD;
	}
	return r;
}
Matrix be(Matrix b, ll e){
	Matrix r=ones(SZ(b));
	while(e){if(e&1)r=r*b; b=b*b; e/=2;}
	return r;
}
mt19937 rng(175);
// const ll ITER=3,L=1e8,R=1e9;
int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	Matrix g(n,vv(n));
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		assert(u!=v);
		g[u][v]++; g[v][u]++;
	}
	Matrix good(n,vv(n));
	fore(_,0,SZ(MODS)-1){
		pos=_;
		// MOD=rng()%(R-L)+L;
		auto gi=be(g,k);
		fore(i,0,n)fore(j,0,n)good[i][j]|=gi[i][j]>0;
	}
	pos=SZ(MODS)-1;
	// MOD=1e9+7;
	g=be(g,k);
	fore(i,0,n-1){
		ll prim=1;
		fore(j,i+1,n){
			ll val=g[i][j];
			good[i][j]|=val>0;
			if(!good[i][j])val=-1;
			if(!prim)cout<<" ";
			prim=0;
			// if(!g[i][j])assert(val==-1);
			cout<<val;
		}
		cout<<"\n";
	}
	return 0;
}
