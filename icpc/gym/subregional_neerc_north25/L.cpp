#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;
const ll MAXN=2005;
const ld INF=1e10;

ld dp[MAXN][MAXN];

int main(){
	FIN;
	 // primero se tiene que vaciar n
	 // [n][0] no se accede
	fore(n,0,MAXN)fore(k,0,MAXN){
		auto &res=dp[n][k];
		if(n==0){
			res=k==0?0:1./2;
			continue;
		}
		if(k==0){res=-INF;continue;} // nunca se usa
		if(k==1){
			res=dp[n-1][k];
			// assert(res==1./2);
			continue;
		}
		ld A=dp[n-1][k];
		ld B=dp[n-1][k-1];
		ld l=max(B+1-A,0.l);
		res=A+l*l/2.;
	}
	ll t; cin>>t;
	while(t--){
		ll n,k,d; cin>>n>>k>>d;
		ld fij=n*ld(d)/2;
		ld res=dp[n-1][k];
		// cerr<<fij<<" "<<res<<"\n";
		cout<<fixed<<setprecision(15)<<fij+res<<"\n";
		// cerr<<"\n";
	}
	return 0;
}