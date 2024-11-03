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
ll msb(ll x){return 63-__builtin_clzll(x);}
void tell(ll x, ll a){
	while(!(x%2))x/=2,a/=2;
	if(!a)return;
	while(x&&msb(x)>msb(a))x^=1ll<<msb(x);
	ll res=grundy(x,a);
	if(res&&res!=ppc(x)){
		ll len=max(SZ(bin(a)),SZ(bin(x)));
		cout<<bin(x,len)<<"\n";
		cout<<bin(a,len)<<"\n";
		cout<<res<<" "<<ppc(x)<<"\n\n";
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,1,n+1)fore(j,1,n+1)tell(i,j);
	return 0;
}
