#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
const ll MAXN=1e5+5;

vector<ll>g[MAXN];

vector<ll>v;
ll ans[MAXN],a[MAXN];

void dfs(ll x, ll fa=-1){
	ll p=lower_bound(ALL(v),a[x])-v.begin();
	ll val=-1;
	if(p==SZ(v))v.pb(a[x]);
	else val=v[p],v[p]=a[x];
	ans[x]=SZ(v);
	for(auto y:g[x])if(y!=fa)dfs(y,x);
	if(val==-1)v.pop_back();
	else v[p]=val;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
		g[i].pb(p);
	}
	fore(i,0,n)cin>>a[i];
	dfs(0);
	fore(i,1,n)cout<<ans[i]<<" ";;cout<<"\n";
	return 0;
}