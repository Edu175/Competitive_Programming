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
Matrix solve(ld a, ld b, ld c, ld d, ld l1, ld l2){
	// not bad por ahora
	assert(abs(a)>EPS||abs(b)>EPS);
	ll sw=0;
	if(abs(a)<EPS)swap(a,c),swap(b,d),swap(l1,l2),sw=1;
	b/=a; l1/=a; a=1;
	d-=c*b; l2-=c*l1; c=0;
	assert(abs(d)>EPS);
	l2/=d;
	l1-=b*l2;
	if(sw)swap(l1,l2);
	return {{l1},{l2}};
}
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

bool operator!=

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
		Matrix rot={
			{cos(-alp),-sin(-alp)},
			{sin(-alp),cos(-alp)}
		};
		rot=be(rot,n-1);
		Matrix u={{l},{0}};
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
		Matrix num=be(ma,n)-ones(2);
		Matrix lhs=num*u;
		ld l1=lhs[0][0],l2=lhs[1][0];
		Matrix rhs=ma-ones(2);
		ld a=rhs[0][0],b=rhs[0][1],c=rhs[1][0],d=rhs[1][1];
		auto res=solve(a,b,c,d,l1,l2);
		
		// prnt(lhs);
		// Matrix v={{res.fst},{res.snd}};
		// prnt(rhs);
		// prnt(rhs*v);
		// all=all;
		
		res=rot*res;
		
		cout<<fixed<<setprecision(15)<<res[0][0]<<" "<<res[1][0]<<"\n";
	}
	return 0;
}