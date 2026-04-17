#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005;
const ll REP=15;

ld dp[MAXN][REP][3][2];

int main(){FIN;
	ll n; cin>>n;
	vector<vv> a(2,vv(3));
	fore(i,0,2)fore(j,0,3)cin>>a[i][j],a[i][j]++;
	
	forr(i,0,n)forr(it,0,REP)forr(r,0,3)fore(w,0,2){
		auto &res=dp[i][it][r][w];
		ll val=a[w][r];
		ld p=1./val;
		 // k=0
		if(it+1<REP)res=(!w+dp[i][it+(r==2)][(r+1)%3][w^1])*p;
		 // k>0
		fore(k,1,val){
			res+=(!w+dp[min(i+k,n)][0][0][w^1])*p;
		}
		// cerr<<i<<" "<<it<<" "<<r<<" "<<w<<": "<<res<<"\n";
	}
	cout<<fixed<<setprecision(10);
	ld res=dp[0][0][0][0];
	cout<<res<<"\n";
	return 0;
}
