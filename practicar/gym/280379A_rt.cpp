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
// only for subtask 6, with m=1024 and MOD=998244353
ll MOD,m;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll n,r; cin>>n>>m>>r>>MOD;
	ll rt=258648936,pot=1; // rt is a 1024th root for 998244353
	ll res=0;
	fore(j,0,m){
		ll coef=fpow(rt,j*(m-r)%m);
		ll rhs=add(1,pot);
		rhs=fpow(rhs,n);
		ll term=mul(coef,rhs);
		res=add(res,term);
		pot=mul(pot,rt);
	}
	cout<<res<<"\n";
	// cout<<mul(res,m)<<"\n";
	return 0;
}