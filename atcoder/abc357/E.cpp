#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll vis[MAXN],dp[MAXN],cyc[MAXN],a[MAXN];
vector<ll>p,ord;
void dfs(ll x){
	// cout<<"dfs "<<x<<" "<<vis[x]<<"\n";
	if(vis[x]){
		if(vis[x]==1){
			ll j=SZ(p)-1,sz=1;
			while(j>=0&&p[j]!=x)j--,sz++;
			fore(i,j,SZ(p))dp[p[i]]=sz,cyc[p[i]]=1;
			// cout<<"did "<<x<<": "; imp(p);
		}
		return;
	}
	vis[x]=1;
	p.pb(x);
	dfs(a[x]);
	p.pop_back();
	vis[x]=2;
	ord.pb(x);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)dfs(i);
	// reverse(ALL(ord));
	ll res=0;
	for(auto x:ord){
		if(!cyc[x])dp[x]=dp[a[x]]+1;
		// cout<<x<<" "<<cyc[x]<<": "<<dp[x]<<"\n";
		res+=dp[x];
	}
	cout<<res<<"\n";
	return 0;
}
