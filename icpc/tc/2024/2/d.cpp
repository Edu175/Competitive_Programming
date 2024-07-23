#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ll MAXN=1e5+5,INF=1e10;

ld dp[MAXN][10];
bool vis[MAXN][10];
ll a[MAXN];
ll n,d;
ld f(ll i, ll r){
	auto &res=dp[i][r];
	if(vis[i][r])return res;
	vis[i][r]=1;
	if(i==n)return res=(r==d?0:-INF);
	res=f(i+1,r);
	res=max(res,log(a[i])+f(i+1,(r*a[i])%10));
	return res;
}
vector<ll>ans;
void build(ll i, ll r){
	if(i==n)return;
	if(dp[i][r]==f(i+1,r))build(i+1,r);
	else {
		ans.pb(a[i]);
		build(i+1,(r*a[i])%10);
	}
}

int main(){
	JET
	
	cin>>n>>d;
	fore(i,0,n)cin>>a[i];
	ld res=f(0,1);
	// cout<<res<<"\n";
	if(res<=0)cout<<"-1\n";
	else {
		build(0,1);
		cout<<SZ(ans)<<"\n";
		for(auto i:ans)cout<<i<<" ";
		cout<<"\n";
	}
	
}