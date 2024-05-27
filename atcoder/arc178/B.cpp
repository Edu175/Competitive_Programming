#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)
		r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
	return r;
}
Matrix be(Matrix b, ll e) {
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}
ll s9=0,sm10=0;
ll f(ll a1, ll a2, ll a3, ll b=0){
	if(a3!=a2+1&&a3!=a2)return 0;
	ll res=-1;
	if(a2>a1){
		res=f(a1,a1,a1+1,1);
	}
	else {
		
		Matrix m={{s9,sm10},{0,100}};
		Matrix a={{0},{1}};
		m=be(m,a1);
		a=m*a;
		res=a[0][0];
	}
	
	if(a3==a2){
		res=sub(mul(fpow(9+b,a1),fpow(9,a2)),res);
	}
	
	return res;
	
}

int main(){FIN;
	fore(i,1,10)fore(j,1,10){
		if(i+j==9)s9++;
		if(i+j>=10)sm10++;
	}
	cerr<<s9<<" "<<sm10<<"\n";
	ll t; cin>>t;
	while(t--){
		ll a1,a2,a3; cin>>a1>>a2>>a3;
		if(a2<a1)swap(a1,a2);
		ll res=f(a1,a2,a3);
		cout<<res<<"\n";
	}
	return 0;
}
