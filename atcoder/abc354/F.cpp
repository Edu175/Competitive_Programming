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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>dp(n),v;
		fore(i,0,n){
			ll lwb=lower_bound(ALL(v),a[i])-v.begin();
			if(lwb>=SZ(v))v.pb(a[i]);
			else v[lwb]=a[i];
			dp[i]=lwb;
		}
		set<ii>h[n+5];
		fore(i,0,n)h[dp[i]].insert({a[i],i});
		vector<ll>is(n);
		for(ll i=n-1;i>=0;i--){
			is[i]|=dp[i]==SZ(v)-1;
			h[dp[i]].erase({a[i],i});
			if(!is[i]||!dp[i])continue;
			vector<ii>pop;
			for(auto x:h[dp[i]-1]){
				if(x.fst>=a[i])break;
				is[x.snd]=1;
				pop.pb(x);
			}
			for(auto x:pop)h[dp[i]-1].erase(x);
		}
		vector<ll>res;
		fore(i,0,n)if(is[i])res.pb(i+1);
		cout<<SZ(res)<<"\n";
		imp(res);
	}
	return 0;
}
