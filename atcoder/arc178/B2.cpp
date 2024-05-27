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
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
unordered_map<ll,ll>dp[2];
ll cv(ll a, ll b){
	return (a<<31)^b;
}
ll f(ll a1, ll a2, ll a3){
	if(a2<a1)swap(a1,a2);
	if((a3!=a2+1&&a3!=a2)||min({a1,a2,a3})<0)return 0;
	if(dp[a3-a2].count(cv(a1,a2)))return dp[a3-a2][cv(a1,a2)];
	ll &res=dp[a3-a2][cv(a1,a2)];
	if(a2>a1){
		res=f(a1,a1,a1+1);
		if(a3==a2){
			ll tot=mul(9,mul(fpow(10,a2-1),fpow(10,a1)));
			tot=add(tot,f(a1,a2-1,a3));
			res=sub(tot,res);
		}
	}
	else {
		
		Matrix m={{s9,sm10},{0,100}};
		Matrix a={{0},{1}};
		m=be(m,a1);
		a=m*a;
		res=a[0][0];
		
		if(a3==a2){
			ll tot=mul(99,fpow(10,(a1-1)*2));
			tot=add(tot,f(a1-1,a2-1,a3));
			res=sub(tot,res);
		}
		
	}
//	cout<<"f "<<a1<<" "<<a2<<" "<<a3<<": "<<res<<"\n";
	return res;
	
}

int main(){FIN;
	fore(i,0,10)fore(j,0,10){
		if(i+j==9)s9++;
		if(i+j>=10)sm10++;
	}
	cerr<<s9<<" "<<sm10<<"\n";
	ll t; cin>>t;
	while(t--){
		ll a1,a2,a3; cin>>a1>>a2>>a3;
		ll res=f(a1,a2,a3);
		if(res){
			res=(res-f(a1,a2-1,a3)-f(a1-1,a2,a3)+f(a1-1,a2-1,a3)+2*MOD)%MOD;
		}
		cout<<res<<"\n";
	}
	return 0;
}
