#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cerr<<i+1<<" ";;cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ll MAXN=3e5+5;//,INF=MAXN*MAXN*MAXN;
vv g[MAXN];

// hip parece true

vv merge(vv a, vv b){
	ll n=SZ(a),m=SZ(b);
	vector<vv> dp(n+3,vv(m+3));
	for(ll i=n;i>=0;i--)for(ll j=m;j>=0;j--){
		auto &res=dp[i][j];
		res=0;
		if(i<n)res=max(res,(i+j)*a[i]+dp[i+1][j]);
		if(j<m)res=max(res,(i+j)*b[j]+dp[i][j+1]);
	}
	vv c;
	for(ll i=0,j=0;i<n||j<m;){
		auto &res=dp[i][j];
		if(i<n&&res==(i+j)*a[i]+dp[i+1][j])c.pb(a[i++]);
		else c.pb(b[j++]);
	}
	// cout<<"merge:\n"; imp(a) imp(b) imp(c) cout<<"\n";
	return c;
}

vv dfs(ll x, ll fa){
	vv ans={};
	for(auto y:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		ans=merge(ans,cur);
	}
	ans.insert(ans.begin(),x);
	return ans;
}
ll val(vv a){
	ll res=0;
	fore(i,0,SZ(a))res+=(a[i]+1)*(i+1);
	return res;
}
int main(){
	ET;
	ll n,s; cin>>n>>s; s--;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto p=dfs(s,-1);
	ll res=val(p);
	imp(p)
	cout<<res<<"\n";
}