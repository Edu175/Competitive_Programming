#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll N=22,MAXN=1ll<<N;
ll a[MAXN];
vector<ll> ans;
ll depth(ll x){
	if(a[x]==0)return 0;
	if(a[2*x]>a[2*x+1])return 1+depth(2*x);
	return 1+depth(2*x+1);
}

void go(ll x){
	if(a[x]==0)return;
	if(a[2*x]>a[2*x+1])a[x]=a[2*x],go(2*x);
	else a[x]=a[2*x+1],go(2*x+1);
}

void solve(ll x, ll d){ // desired height
	if(d==0)return;
	while(depth(x)>d)ans.pb(x),go(x);
	solve(2*x,d-1),solve(2*x+1,d-1);
}

int main(){JET
	ll t; cin>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		fore(i,1,1ll<<(n+2))a[i]=0;
		fore(i,1,1ll<<n)cin>>a[i];
		ans.clear();
		solve(1,d);
		ll res=0;
		fore(i,1,1ll<<n)res+=a[i];
		cout<<res<<"\n";
		for(auto i:ans)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}