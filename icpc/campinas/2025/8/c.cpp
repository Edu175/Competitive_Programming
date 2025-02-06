#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll maxn=2e5+10;
ll n,k;
ll a[maxn];
set<ll> st[maxn];
ll dp[maxn][2];

const ll INF = -1e16;

ll f(ll i, ll b){
	auto pro=[&](ll x, ll y){return st[x].count(y);};
	ll &rta=dp[i][b];
	if(i==n) return 0;
	if(rta!=-1) return rta;
	rta=INF;
	if(b && !pro(a[i-2],a[i]));
	else if(b){
		rta = f(i+1,0)+1;
		return rta;
	}
	else if(!pro(a[i-1],a[i])){
		rta = f(i+1,1);
		return rta;
	}
	else rta = max(f(i+1,1),f(i+1,0)+1);
	// cout<<i<<" "<<b<<" "<<rta<<"\n";
	return rta;
}


int main(){
	JET
	cin>>n>>k;
	mset(dp,-1);
	fore(i,0,n) cin>>a[i];
	int m; cin>>m;
	fore(i,0,m){
		int x, y; cin>>x>>y;
		st[x].insert(y);
	}
	ll rta=0;
	if(a[0]== k+1 && a[1]==k+1){
		cout<<0<<"\n";
		return 0;
	}
	if(a[0]!=k+1){
		rta=max(rta,f(1,0)+1);
		// cout<<rta<<" 1 \n";
	}
	if(a[1]!=k+1){
		rta = max(rta,f(2,0)+1);
		// cout<<rta<<" 2 \n";
		
	}
	cout<<rta<<"\n";
	
}