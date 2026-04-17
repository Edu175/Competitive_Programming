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
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll inv(ll a){return fpow(a,MOD-2);}
#define addig(a,b) a=add(a,b)
#define subig(a,b) a=sub(a,b)
#define mulig(a,b) a=mul(a,b)

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


ll cams(ll s, vector<vv> g, ll k){ // # of paths of size <=k from s
	ll n=SZ(g);
	fore(i,0,n)g[i].pb(1);
	g.pb(vv(n+1));
	g[n][n]=1;
	
	Matrix m=be(g,k+1); // +1 para la terminal n
	
	ll res=m[s][n];
	return res;
}

int main(){FIN;
	ll n,m; cin>>n>>m>>MOD;
	vector<vv> g(m,vv(m));
	vv sp(m+5);
	fore(i,1,SZ(sp)){
		sp[i]=add(sp[i-1],inv(i-1));
	}
	fore(i,0,m)fore(j,0,m){
		ll s=min(i,j),e=max(i,j);
		auto &coef=g[i][j]; coef=0;
		fore(l,0,s+1){
			ll ranl=e+1-l;
			ll ranr=m-l+1;
			
			ll cur=sub(sp[ranr],sp[ranl]);
			addig(coef,cur);
			cout<<i<<","<<j<<" "<<l<<": "<<cur<<"\n";
		}
	}
	fore(i,0,n){
		imp(g[i])
	}
	ll res=cams(0,g,n+1);
	cout<<res<<"\n";
	return 0;
}
