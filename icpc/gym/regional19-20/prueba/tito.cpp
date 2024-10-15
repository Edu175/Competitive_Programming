#include <bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll kk=b, i=a; i<kk; i++)
#define FR ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(x) ((ll)x.size())
typedef long long ll;
typedef long double ld;
typedef short int sint;
typedef vector<ll> vv;
typedef vector<ld> vd;
typedef vector<vv> Matrix;
typedef int LALLAMA;
const ll mod=1e9+7;
ll addmod(ll a, ll b){
	a+=b;
	return a<mod?a:a-mod;
}
ll mulmod(ll a, ll b){
	return a*b%mod;
}
Matrix operator*(Matrix &a, Matrix &b){
	ll n=SZ(a), m=SZ(b), h=SZ(b[0]);
	Matrix r(n, vv(h));
	fore(i,0,n)fore(j,0,h)fore(k,0,m){
		r[i][j]=addmod(r[i][j],mulmod(a[i][k],b[k][j]));
	}
	return r;
}
Matrix ones(ll n){
	Matrix r(n, vv(n));
	fore(i,0,n) r[i][i]=1;
	return r;
}
vector<Matrix> p(30, Matrix(200,vv(200,0)));
LALLAMA main(){FR;
	sint n,q; int m; cin>>n>>m>>q;
	while(m--){
		sint a,b; cin>>a>>b;a--;b--;
		p[0][a][b]=1;
	}
	fore(i,1,30){
		p[i]=p[i-1]*p[i-1];
	}
	while(q--){
		sint s,t; int k; cin>>s>>t>>k;s--; t--;
		Matrix m=ones(n);
		fore(i,0,30)if(k&(1<<i)) m=m*p[i];
		Matrix res(200,vv(1,0));
		res[t][0]=1;
		res=m*res;
		cout<<res[s][0]<<"\n";
	}
}