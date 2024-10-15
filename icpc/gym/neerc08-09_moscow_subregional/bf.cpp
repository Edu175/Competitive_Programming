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
int a[MAXN];

int f(ll l, ll r){
	auto &res=dp[l][r];
	if(res!=-1)return res;
	// assert(l<=r);
	if(l>=r)return res=0;
	if(r-l==1)return res=1;
	res=n+5;
	if(a[l]==a[r-1]){
		ll s=l,e=r;
		while(a[s]==a[l])s++;
		while(e>0&&a[e-1]==a[l])e--;
		res=1+f(s,e);
		// cout<<l<<","<<r<<": "<<s<<","<<e<<"\n";
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
	cout<<f(0,n)-1<<"\n";
}
