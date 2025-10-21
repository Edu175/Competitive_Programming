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

void cap(vector<ii> &a){
	sort(ALL(a));
	a.resize(min(2ll,ll(unique(ALL(a))-a.begin())));
}

enum{
	JOIN,
	SEP
};

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<vector<ii>> dp(n+3);
	dp[n]={{0,0}};
	auto good=[&](ll i, ll bo)->bool {
		if(i>=n)return 0;
		if(i==n-1)return bo==SEP;
		if(a[i+1]-a[i]<=1000)return bo==JOIN;
		if(a[i+1]-a[i]>=2000)return bo==SEP;
		return 1;
	};
	for(ll i=n-1;i>=0;i--){
		auto &res=dp[i];
		vector<ii> go2,go3;
		if(good(i,JOIN)&&good(i+1,SEP))go2=dp[i+2];
		if(good(i,JOIN)&&good(i+1,JOIN)&&good(i+2,SEP))go3=dp[i+3];
		for(auto &i:go2)i.fst++,res.pb(i);
		for(auto &i:go3)i.snd++,res.pb(i);
		cap(res);
		// cout<<i<<": "<<go2<<" "<<go3<<": "<<res<<"\n";
	}
	auto res=dp[0];
	if(SZ(res)==0){
		cout<<"Impossible\n";
		return 0;
	}
	if(SZ(res)>=2){
		cout<<"Ambiguous\n";
		return 0;
	}
	// ll p=0,dos=0,tres=0;
	// while(p<n){
	// 	auto &res=dp[p];
	// 	if(res==good(p,JOIN)*good(p+1,SEP)*dp[p+2])dos++,p+=2;
	// 	else tres++,p+=3;
	// }
	cout<<"Cars without trailers: "<<res[0].fst<<"\n";
	cout<<"Cars with trailers: "<<res[0].snd<<"\n";
	return 0;
}
