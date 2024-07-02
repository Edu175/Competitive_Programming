#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n),b(n);
	fore(i,0,n)cin>>a[i],a[i]%=MOD;
	fore(i,0,n)cin>>b[i],b[i]%=MOD;
	while(q--){
		ll ty,l,r; cin>>ty>>l>>r; l--;
		if(ty==1){
			ll x; cin>>x; x%=MOD;
			fore(i,l,r)a[i]=add(a[i],x);
		}
		else if(ty==2){
			ll x; cin>>x; x%=MOD;
			fore(i,l,r)b[i]=add(b[i],x);
		}
		else {
			ll res=0;
			fore(i,l,r)res=add(res,mul(a[i],b[i]));
			cout<<res<<"\n";
		}
		
	}
	return 0;
}
