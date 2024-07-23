#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){
	return a*b%MOD;
}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b),e>>=1;
	}
	return res;
}
int main(){
	JET
	ll x,y; cin>>x>>y;
	if(y%x!=0) cout<<"0\n";
	else {
		ll n=y/x;
		vector<ll>ps;
		ll ni=n;
		for(ll i=2;i*i<=ni;i++){
			ll c=0;
			while(ni%i==0)c++,ni/=i;
			if(c)ps.pb(i);
		}
		if(ni>1)ps.pb(ni);
		ll res=fpow(2,MOD-2);
		for(auto p:ps)res=mul(res,sub(fpow(2,n),fpow(2,n/p)));
		cout<<res<<"\n";
	}
	return 0;
}