#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<(i?"▮":" "); cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vector<ll>> mat;

bool check(mat b){
	ll n=SZ(b);
	fore(i,0,n-1)fore(j,0,n-1){
		if(b[i][j]&&i+j<n-1)return 0;
		ll c=b[i][j]^b[i+1][j]^b[i][j+1];
		if(c)return 0;
	}
	return 1;
}
int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll cant=0;
		// ll cant=n*n+5;
		// vector<mat> cands;
		ll bound=n*n/10*3;
		cerr<<"solution for n="<<n<<"\n";
		mat cand;
		fore(_mk,0,1ll<<(n-2)){
			ll mk=_mk*2+1;
			mk|=1ll<<(n-1);
			mat a(n,vv(n));
			fore(i,0,n){
				a[i][n-1]=mk&1; mk>>=1;
			}
			fore(i,1,n)fore(j,0,n-1)a[i][j]=a[i-1][j]^a[i-1][j+1];
			ll c=0;
			for(auto r:a)c+=count(ALL(r),1);
			if(c>cant)cant=c,cand=a;
			assert(check(a));
		}
		cerr<<"cant "<<cant<<"\n";
		cerr<<"bound "<<bound<<"\n";
		cerr<<"cand:\n";
		for(auto r:cand)imp(r)
		cout<<"\n";
	}
	return 0;
}
