#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=105;

ld dp[MAXN][MAXN][MAXN];
ld f(ll a, ll b, ll s, ll i){
	auto &res=dp[a][b][s];
	if(res!=-1)return res;
	if(i==0)return res=0;
	res=0;
	if(a){
		ld resi=0;
		if(s==0&&i>0){ // agarro i
			resi=i+f(a-1,b,s,i-1);
		}
		else resi=f(a-1,b,s-1,i);
		res+=(a/ld(a+b))*resi;
	}
	if(b){
		res+=(b/ld(a+b))*f(a,b-1,s+1,i-1);
	}
	// cout<<a<<" "<<b<<" "<<s<<" "<<i<<": "<<res<<"\n";
	return res;
}

int main(){ET
	ll n; cin>>n;
	fore(i,0,n+3)fore(j,0,n+3)fore(k,0,n+3){
		// fore(l,0,n+5)dp[i][j][k][l]=-1;
		dp[i][j][k]=-1;
	}
	auto res=f(n,n,0,n);
	cout<<fixed<<setprecision(6)<<res<<"\n";
}