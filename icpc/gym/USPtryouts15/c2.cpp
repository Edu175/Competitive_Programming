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

Matrix ones(int n){
	Matrix r(n,vector<ld>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b){
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ld>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]+=a[i][k]*b[k][j];
	return r;
}

Matrix be(Matrix b, ll e){
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
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
		Matrix u={{l},{0}};
		
		Matrix p=ma*u;
		Matrix t={
			{p[0][0],-p[1][0]},
			{p[1][0],p[0][0]}
		};
		prnt(u);
		prnt(p);
		Matrix unit={{1},{0}};
		prnt(t*unit);
		
		t=be(t,n-1);
		
		//primer paso
		// for(auto &i:t)for(auto &j:i)j*=l;
		// t=t+u;
		t=t*u;
		
		Matrix rot={
			{cos(-alp),-sin(-alp)},
			{sin(-alp),cos(-alp)}
		};
		rot=be(rot,n-1);
		t=rot*t;
		auto brute=[&]()->pair<ld,ld>{
			ld al=-alp;
			Matrix ma={
				{cos(al),-sin(al)},
				{sin(al),cos(al)}
			};
			Matrix p={{0},{0}};
			fore(i,0,n){
				p=ma*p+u;
				// cout<<p[0][0]<<","<<p[1][0]<<"\n";
			}
			// cout<<"ended brute\n";
			return {p[0][0],p[1][0]};
		};
		auto notsobrute=[&](){
			Matrix ma={
				{cos(alp),-sin(alp)},
				{sin(alp),cos(alp)}
			};
			Matrix p={{0},{0}};
			Matrix u={{l},{0}};
			fore(i,0,n){
				p=p+u;
				u=ma*u;
				cout<<p[0][0]<<","<<p[1][0]<<"\n";
			}
			p=rot*p;
			cout<<"roto: "<<p[0][0]<<","<<p[1][0]<<"\n";
			cout<<"ended notsobrute\n";
		};
		// brute();
		// notsobrute();
		cout<<fixed<<setprecision(15)<<t[0][0]<<" "<<t[1][0]<<"\n";
	}
	return 0;
}