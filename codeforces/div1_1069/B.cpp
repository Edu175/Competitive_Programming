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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		vv fp(k+1,n);
		fore(i,0,n){
			cin>>a[i];
			auto &p=fp[a[i]];
			if(p==n)p=i;
		}
		for(ll i=k-1;i>=0;i--){
			fp[i]=min(fp[i],fp[i+1]);
		}
		fp[0]=-1;
		vector<vv> dp(k+1,vv(k+1));
		for(ll u=k;u>=0;u--)fore(s,0,k+1){
			auto &res=dp[u][s];
			res=u*(n-fp[u]); // end
			fore(v,u+1,k+1){
				ll si=s-v;
				if(si<0)break;
				if(fp[v]<fp[u])continue;
				ll cur=(fp[v]-fp[u])*u+dp[v][si];
				res=max(res,cur);
			}
		}
		ll res=dp[0][k];
		cout<<res<<"\n";
	}
	return 0;
}
