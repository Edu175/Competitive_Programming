#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a));
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=305;

ll n,m;
int dp[MAXN][MAXN];
int dp2[MAXN][MAXN];
int a[MAXN];
int f(ll l, ll r);
int g(ll l, ll r){ // estoy pintando
	auto &res=dp2[l][r];
	if(res!=-1)return res;
	if(l>=r)return res=0;
	res=f(l+1,r-1);
	fore(m,l+1,r)if(a[m]==a[l])res=min(res,g(l,m+1)+g(m,r));
	// cout<<l<<","<<r<<": "<<res<<" g\n";
	return res;
}

int f(ll l, ll r){
	auto &res=dp[l][r];
	if(res!=-1)return res;
	// assert(l<=r);
	if(l>=r)return res=0;
	res=n+5;
	if(a[l]==a[r-1]){
		res=1+g(l,r);
	}
	fore(m,l+1,r)res=min(res,f(l,m)+f(m,r));
	// cout<<l<<","<<r<<": "<<res<<" f\n";
	return res;
}

int main(){
	JET
	cin>>n>>m;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	mset(dp2,-1);
	cout<<f(0,n)-1<<"\n";
}
