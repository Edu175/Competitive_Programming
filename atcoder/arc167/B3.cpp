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
#define bint __int128
const ll MOD=998244353;

vector<ll> fact(ll x){
	vector<ll>v;
	for(ll i=2;i*i<=x;i++){
		ll c=0;
		while(x%i==0){
			c++;
			x/=i;
		}
		if(c)v.pb(c);
	}
	if(x>1)v.pb(1);
	return v;
}
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
	ll a,b; cin>>a>>b;
	ll is=(b%2==0);
	b%=MOD;
	ll q=1;
	for(auto e:fact(a)){
		if(e%2)is=1;
		q=(e*b+1)%MOD*q%MOD;
	}
	ll res=b*q%MOD;
	if(!is){
		res=(res-1+MOD)%MOD;
	}
	res=res*fpow(2,MOD-2)%MOD;
	cout<<res<<"\n";
	return 0;
}
