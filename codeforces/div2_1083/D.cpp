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
		ll n; cin>>n;
		vv a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		vv dp(n);
		set<ll> st={-1,n};
		ll res=0;
		for(ll x=n-1;x>=0;x--){
			ll i=p[x];
			auto it=st.insert(i).fst;
			ll l=*prev(it);
			ll r=*next(it);
			ll cur=0;
			if(l!=-1)cur=max(cur,dp[l]);
			if(r!=n)cur=max(cur,dp[r]);
			cur++;
			res=max(res,cur);
			dp[i]=cur;
		}
		cout<<n-res<<"\n";
	}
	return 0;
}
