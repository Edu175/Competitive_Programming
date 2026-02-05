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
int mul(ll a, ll b){return a*b%MOD;}
typedef vector<vector<ll>> Matrix;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){	//no conmutativa
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]=(r[i][j]+a[i][k]*b[k][j])%MOD;
	return r;
}
Matrix be(Matrix b, ll e){	//b tiene que ser cuadrada
	Matrix r=ones(SZ(b));
	while(e){if(e&1ll)r=r*b; b=b*b; e/=2;}
	return r;
}

vector<ii> fact(ll n){
	vector<ii> r;
	for(ll i=2;i*i<=n;i++){
		ll c=0;
		while(n%i==0)c++,n/=i;
		if(c)r.pb({i,c});
	}
	if(n>1)r.pb({n,1});
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll res=1;
		for(auto [asd,c]:fact(k)){
			Matrix m={
				{1,c},
				{1,0}
			};
			Matrix a={
				{1},
				{1}
			};
			a=be(m,n)*a;
			ll cur=a[0][0];
			res=mul(res,cur);
			// cout<<c<<": "<<cur<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}