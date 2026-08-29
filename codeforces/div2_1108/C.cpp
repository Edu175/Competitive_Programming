#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll cuan(ll c, ll od){
	if(!c)return !od;
	return fpow(2,c-1);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		map<ll,ll> mp;
		fore(i,0,n){
			ll x; cin>>x;
			mp[x]++;
		}
		ll ev=1;
		vv keys;
		for(auto [val,c]:mp)ev=mul(ev,cuan(c,0)),keys.pb(val);
		ll res=ev;
		for(auto val:keys)if(val>-1&&mp[val-1]&&mp[-1]){
			res=add(res,ev);
		}
		cout<<res<<"\n";
	}
	return 0;
}
