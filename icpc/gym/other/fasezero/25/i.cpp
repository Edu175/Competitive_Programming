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
const ll INF=1e12;
const ll MAXN=105;

int main(){FIN;
	ll n,t; cin>>n>>t;
	vector<vv> a(n,vv(t)),sp(n,vv(t+1));
	fore(i,0,n){
		fore(j,0,t)cin>>a[i][j],sp[i][j+1]=sp[i][j]+a[i][j];
	}
	auto cost=[&](ll i, ll l, ll r){
		return sp[i][r]-sp[i][l];
	};
	ll L,U; cin>>L>>U;
	vector<vv> dp(t+1,vv(n));
	auto go=[&](ll i, ll l, ll r){
		ll w=cost(i,l,r);
		// cout<<"range "<<i<<" "<<l<<","<<r<<" "<<w<<"\n";
		return w+dp[r][i];
	};
	ll ans=-INF;
	for(ll x=t-1;x>=0;x--){
		vv all(n,-INF);
		fore(i,0,n)fore(z,L,U+1){
			ll l=x,r=x+z;
			if(r<=t){
				all[i]=max(all[i],go(i,l,r));
			}
		}
		// cout<<x<<": ";
		// imp(all)
		vv pre(n+1,-INF),suf=pre;
		fore(i,1,n+1)pre[i]=max(all[i-1],pre[i-1]);
		for(ll i=n-1;i>=0;i--)suf[i]=max(all[i],suf[i+1]);
		fore(i,0,n)dp[x][i]=max(pre[i],suf[i+1]);
		if(x==0)ans=suf[0];
	}
	if(ans<0)ans=-1;
	cout<<ans<<"\n";
	return 0;
}
