#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	int r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b);
		e>>=1;
	}
	return r;
}
typedef vector<vector<ll>> Matrix;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z){
		r[i][j]=add(r[i][j],mul(a[i][k],b[k][j]));
	}
	return r;
}
Matrix be(Matrix b, ll e){
	// if()e<0
	Matrix r=ones(SZ(b));
	while(e){
		if(e&1)r=r*b;
		b=b*b;
		e>>=1;
	}
	return r;
}

int main(){
	FIN
	ll n; cin>>n;
	if(n==1){
		cout<<"2\n";
		return 0;
	}
	Matrix a={{1},{1},{1},{2}};
	Matrix m={
		{1,1,1,0},
		{1,0,0,0},
		{0,0,1,0},
		{1,1,1,1}
	};
	auto r=be(m,n-2)*a;
	// for(auto i:r){
	// 	cout<<"{ ";
	// 	for(auto j:i)cout<<j<<" ";
	// 	cout<<"}\n";
	// }
	ll res=mul(fpow(2,n+1),add(r[3][0],r[1][0]));
	cout<<res<<"\n";
	return 0;
} 

/*

2
{ 3 }
{ 1 }
{ 1 }
{ 4 }
32

3
{ 5 }
{ 3 }
{ 1 }
{ 9 }
144

4
{ 9 }
{ 5 }
{ 1 }
{ 18 }
576



*/



