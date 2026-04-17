#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXMK=1<<9,INF=1e15;

ll dp[MAXN][MAXMK];
bitset<MAXMK> vis[MAXN];
vector<ll> a[MAXN];
ll m,k;
ll f(ll i, ll mk){
	ll &res=dp[i][mk];
	if(vis[i][mk])return res;
	vis[i][mk]=1;
	if(i==m){
		if(mk==0)return res=0;
		return res=-INF;
	}
	res=f(i+1,mk/2);
	ll s=0,c=0;
	auto mi=mk;
	fore(j,0,k)if(!(mi>>j&1)){
		// cout<<i<<" "<<j<<" "<<c<<endl;
		if(c>=SZ(a[i]))break;
		s+=a[i][c++];
		mi|=1ll<<j;
		res=max(res,s+f(i+1,mi/2));
	}
	// cout<<i<<" "<<mk<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	ll n; cin>>n>>m>>k;
	fore(i,0,n){
		fore(j,0,m){
			ll x; cin>>x;
			a[j].pb(x);
		}
	}
	fore(j,0,m){
		sort(ALL(a[j])),reverse(ALL(a[j]));
		// imp(a[j]);
	}
	mset(dp,-1);
	ll res=f(0,(1ll<<(k-1))-1);
	cout<<res<<"\n";
	return 0;
}