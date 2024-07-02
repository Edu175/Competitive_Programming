#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

map<ll,bool>dp[MAXN];
ll n;
ll a[MAXN];
ll mx;
ll f(ll i, ll k){
	if(dp[i].count(k))return dp[i][k];
	auto &res=dp[i][k];
	if(k==0)return i==mx;
	if(i==n)i=0;
	if(i==mx){
		return res=f(i+1,k-min(a[i],k));
	}
	fore(j,1,min(a[i],k)+1){
		if(f(i+1,k-j))return res=1;
	}
	return res=0;
}
 int main(){JET
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	mx=0;
	fore(i,0,n)if(a[i]>a[mx])
	return 0;
 }