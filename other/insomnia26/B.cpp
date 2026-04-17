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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
typedef vector<vector<ll>> Matrix;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){	//no conmutativa
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	assert(z==SZ(b));
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]=(r[i][j]+a[i][k]*b[k][j])%MOD;
	return r;
}
Matrix be(Matrix b, ll e){	//b tiene que ser cuadrada
	Matrix r=ones(SZ(b));
	while(e){if(e&1ll)r=r*b; b=b*b; e/=2;}
	return r;
}

int main(){FIN;
	ll x,y; cin>>x>>y;
	vector<vv> mat(y,vv(y));
	Matrix ini(y,vv(1)); ini[0][0]=x;
	fore(j,0,y)mat[0][j]=x-1;
	fore(i,1,y){
		mat[i][i-1]=1;
	}
	auto a=be(mat,x-1)*ini;
	ll res=0;
	fore(i,0,y)res=(res+a[i][0])%MOD;
	cout<<res<<"\n";
	return 0;
}
