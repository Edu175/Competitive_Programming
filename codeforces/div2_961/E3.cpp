#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e10;

ll dp[MAXN][2],a[MAXN];
ll n,mn;
ll op(ll i){return i<n?i+n:i-n;}
ll val(ll v){return v<mn?INF:v;}
ll f(ll i, ll b){
	ll &res=dp[i][b];
	if(res!=-1)return res;
	ll v=!b?a[i]:a[op(i)];
	if(i==(n^1))return res=val(v+a[n]);
	ll go0=max(val(v+a[i^1]),f(op(i^1),0));
	ll go1=max(val(v+a[op(i^1)]),f(op(i^1),1));
	return res=min(go0,go1);
}

ll solve(ll _mn){
	mn=_mn;
	fore(i,0,2*n)fore(j,0,2)dp[i][j]=-1;
	ll res0=f(0,0);
	swap(a[0],a[n]);
	fore(i,0,2*n)fore(j,0,2)dp[i][j]=-1;
	ll res1=f(0,0);
	ll res=min(res0,res1);
	// cout<<"solve "<<mn<<": res0 "<<res0<<", res1 "<<res1<<"\n";
	
	swap(a[0],a[n]);
	return res-mn;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,2*n)cin>>a[i];
		if(!(n&1)){
			ll mx=-1,mn=INF;
			fore(i,0,n)if(!(n&1)){
				if(a[i]>a[op(i)])swap(a[i],a[op(i)]);
				if(a[i^1]<a[op(i^1)])swap(a[i^1],a[op(i^1)]);
			}
			fore(i,0,2*n){
				ll s=a[i]+a[i^1];
				mx=max(mx,s);
				mn=min(mn,s);
			}
			cout<<mx-mn<<"\n";
			continue;
		}
		vector<ll>sums;
		fore(i,0,2*n){
			sums.pb(a[i]+a[i^1]);
			sums.pb(a[i]+a[op(i^1)]);
			sums.pb(a[i]+a[op(op(i)^1)]);
		}
		auto transf=[&](vector<ll>&a){
			sort(ALL(a));
			vector<ll>b;
			fore(i,0,SZ(a))if(!i||a[i]!=a[i-1])b.pb(a[i]);
			a=b;
		};
		transf(sums);
		ll l=0,r=SZ(sums)-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(sums[m])+sums[m]<INF)l=m+1;
			else r=m-1;
		}
		cout<<solve(sums[r])<<"\n";
		/*ll res=INF;
		fore(i,0,SZ(sums)){if(!i||sums[i]!=sums[i-1])
			res=min(res,solve(sums[i]));
		}
		cout<<res<<"\n";*/
	}
	return 0;
}