#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b, const ll MOD=MOD){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b, const ll MOD=MOD){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
// int fpow(int b, ll e){
// 	int res=1;
// 	while(e){
// 		if(e&1)res=mul(res,b);
// 		b=mul(b,b); e>>=1;
// 	}
// 	return res;
// }
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
vv z_function(vv& s){
	int l=0,r=0,n=SZ(s);
	vv z(SZ(s)); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	vv a(n),b(n),c(n),d(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)c[i]=sub(a[(i+1)%n]%m,a[i]%m,m);
	fore(i,0,n)d[i]=sub(b[i]%m,b[(i+1)%n]%m,m);
	
	vv s=c;
	fore(_,0,2)fore(i,0,n)s.pb(d[i]);
	auto z=z_function(s);
	ll q=0,good=0;
	fore(i,0,n)if(z[n+i]>=n){
		q++; good|=!i;
	}
	Matrix ma={	{MOD-1,1},
				{0,n-1}};
	Matrix v={{good},{q}};
	
	v=be(ma,k)*v;
	// cerr<<good<<" "<<q<<": ";
	cout<<v[0][0]<<"\n";
	return 0;
}