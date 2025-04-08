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

map<string,ll>dp;
ll f(string s){
	if(dp.count(s))return dp[s];
	ll &res=dp[s];
	if(!SZ(s))return res=0;
	res=SZ(s);
	fore(i,0,SZ(s)-1)if(((s[i]-'0')^(s[i+1]-'0'))!=1){
		auto t=s.substr(0,i)+s.substr(i+2);
		res=min(res,f(t));
	}
	// fore(i,0,SZ(s)){
	// 	auto t=s.substr(0,i)+s.substr(i+1);
	// 	res=min(res,1+f(t));
	// }
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		cout<<f(s)<<"\n";
	}
	return 0;
}
