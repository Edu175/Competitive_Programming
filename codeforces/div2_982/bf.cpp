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

ll ppc(ll n){return __builtin_popcountll(n);}

map<ii,ll>dp;
ll grundy(ll x, ll a){
	if(dp.count({x,a}))return dp[{x,a}];
	ll &res=dp[{x,a}];
	if(x==0)return 0;
	set<ll>st;
	fore(d,1,a+1)if((d&x)==d)st.insert(grundy(x-d,a));
	fore(i,0,SZ(st)+5)if(!st.count(i))return res=i;
	assert(0);
}
string bin(ll x, ll k=-1){
	string s;
	while(x)s.pb('0'+(x&1)),x/=2;
	if(k!=-1)s.resize(k,'0');
	reverse(ALL(s));
	return s;
}

int main(){FIN;
	ll a,x; cin>>a>>x;
	ll len=1,pot=1;
	while(pot<max(a,x))len++,pot=pot*2+1;
	cout<<bin(x,len)<<"\n";
	cout<<bin(a,len)<<"\n";
	cout<<grundy(x,a)<<"\n";
	
	return 0;
}
