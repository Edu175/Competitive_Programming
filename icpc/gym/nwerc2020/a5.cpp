#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
typedef vector <vv> Matrix;
const ll INF=3e18;
Matrix operator*(Matrix &a, Matrix &b){
	ll n=SZ(a), m=SZ(b), h=SZ(b[0]);
	Matrix r(n, vv(h,INF));
	fore(i,0,n)fore(j,0,h){
		fore(k,0,m){
			r[i][j]=min(r[i][j],a[i][k]+b[k][j]);
		}
	}
	return r;
}
/*
Matrix ones(ll n){
	Matrix r(n, vv(n,INF));
	fore(i,0,n) r[i][i]=0;
	return r;
}*/
Matrix P[30];
int main(){
	JET
	ll n,q;
	cin>>n>>q;
	ll best[n+1]; best[0]=0; fore(i,1,n+1) cin>>best[i];
	best[0]=0;
	fore(i,1,n+1){
		fore(j,0,i){
			best[i]=min(best[i],best[j]+best[i-j]);
		}
	}
	Matrix ifo(n,vv(n,INF));
	P[0]=ifo;
	fore(i,1,n+1){
		P[0][0][i]=best[i];
	}
	fore(i,0,n-1){P[0][i+1][i]=0;}
	fore(i,1,30){
		P[i]=P[0]*P[0];
	}
	Matrix v(n, vv(0));
	fore(i,0,n)v[0][i]=best[n-i+1];
	while(q--){
		ll k; cin>>k;
		Matrix lol=v;
		fore(i,0,30) if((k>>i)&1) lol=P[i]*lol;
		cout<<lol[0][0]<<"\n";
	}
	
	
}





