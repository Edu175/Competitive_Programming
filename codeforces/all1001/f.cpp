#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15;


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			y-=x;
			a[i]={y,x};
		}
		sort(ALL(a));
		for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		vector<vector<vv>>dp(n+2,vector<vv>(n+2,vv(2)));
		fore(k,1,n+1)fore(fi,0,2)dp[n][k][fi]=INF;
		dp[n][0][0]=0;
		for(ll i=n-1;i>=0;i--)fore(k,0,n+1)fore(fi,0,2) {
			auto &res=dp[i][k][fi];
			res=dp[i+1][k][fi];
			if(k){
				ll val=a[i].snd+(fi?0:a[i].fst);
				res=min(res,val+dp[i+1][k-1][0]);
			}
			cout<<i<<" "<<k<<" "<<fi<<": "<<res<<"\n";
		}
		fore(k,2,n+1)cout<<dp[0][k][1]<<" ";;cout<<"\n";
	}
	return 0;
}
