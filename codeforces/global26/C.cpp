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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll mn=*min_element(ALL(sp));
		ll res=0;
		if(mn>=0){
			res=fpow(2,n);
		}
		else {
			ll c=0;
			fore(i,0,n){
				if(sp[i+1]==mn){
					ll cur=mul(fpow(2,c),fpow(2,n-1-i));
					res=add(res,cur);
				}
				c+=sp[i+1]>=0;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
