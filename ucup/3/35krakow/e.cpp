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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll pf(ll a){return __builtin_ctzll(a);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ll m=a+b;
		ll fm(pf(m));
		ll fa(pf(a));
		a=a>>fa;
		m=m>>fm;
		ll k=-1;
		if(a%m==0)k=max(0ll,fm-fa);
		ll res=0;
		if(k==-1)res=2;
		else {
			ll prob=1;
			ll d=k-1;
			fore(i,0,d+1){
				res=add(res,prob);
				prob=mul(prob,(MOD+1)/2);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
