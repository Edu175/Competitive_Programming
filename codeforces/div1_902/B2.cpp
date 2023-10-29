#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>dp(n);
	map<ll,ll>mp;
	fore(i,0,n){
		ll &res=dp[i];
		for(ll j=i;j<n;j+=i+1)res=max(res,a[j]);
		mp[dp[i]]++;
	}
	//imp(dp);
	ll res=0;
	ll c=0;
	for(auto [v,q]:mp){
		ll resi=(fpow(2,q)-1+MOD)%MOD;
		resi=resi*fpow(2,c)%MOD;
		//cout<<v<<" "<<q<<": "<<resi<<"\n";
		res=(res+resi*v)%MOD;
		c+=q;
	}
	cout<<res<<"\n";
	return 0;
}
