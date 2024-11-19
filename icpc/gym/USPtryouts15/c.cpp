#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef vector<vector<ld>> Matrix;

Matrix operator*(Matrix &a, Matrix &b){
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ld>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]+=a[i][k]*b[k][j];
	return r;
}


const ld EPS=1e-9;

Matrix operator-(Matrix a, Matrix b){
	fore(i,0,SZ(a))fore(j,0,SZ(a[0]))a[i][j]-=b[i][j];
	return a;
}
Matrix operator+(Matrix a, Matrix b){
	fore(i,0,SZ(a))fore(j,0,SZ(a[0]))a[i][j]+=b[i][j];
	return a;
}
Matrix ones(int n){
	Matrix r(n,vector<ld>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix be(Matrix b, ll e){
	// cout<<"exp de be: "<<e<<"\n";
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}
void prnt(Matrix a){
	fore(i,0,SZ(a)){
		cout<<"{";
		for(auto j:a[i])cout<<j<<",";
		cout<<"}\n";
	}
	cout<<"\n";
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ld alp,l; ll n; cin>>alp>>l>>n; 
		alp=-alp; // !!!!
		//radians
		alp=alp/180*acosl(-1);
		Matrix ma={
			{cos(alp),-sin(alp)},
			{sin(alp),cos(alp)}
		};
		Matrix res={{0},{0}};
		Matrix v={{l},{0}};
		ll _n=n;
		auto ro=ma;
		while(n){
			if(n&1)res=ro*res+v;//,cout<<"sumo\n",prnt(v);
			v=v+ro*v; n/=2; ro=ro*ro;
		}
		// prnt(res);
		Matrix rot={
			{cos(-alp),-sin(-alp)},
			{sin(-alp),cos(-alp)}
		};
		// cout<<_n<<"\n";
		rot=be(rot,_n-1);
		// cout<<"rot:\n";
		// prnt(rot);
		res=rot*res;
		cout<<fixed<<setprecision(15)<<res[0][0]<<" "<<res[1][0]<<"\n";
	}
	return 0;
}

/*
sumo
{1.5,}
{0,}

sumo
{7.64711,}
{-7.64711,}

sumo
{10.4462,}
{-18.0933,}

sumo
{10.4462,}
{-38.9856,}

sumo
{-1.30104e-17,}
{-77.9711,}

{-37.4856,}
{-88.4173,}

rot:
{1,-6.93889e-18,}
{6.93889e-18,1,}

-37.485571585149869 -88.417295593006371



*/