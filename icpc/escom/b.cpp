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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	n%=MOD;
	ll inv=fpow(n,MOD-2);
	ll comp=sub(1,inv);
	
	ll coef=0;
	ll con=mul(fpow(inv,k),k);
	fore(i,0,k){
		ll term=mul(fpow(inv,i),comp);
		con=add(con,mul(term,i+1));
		coef=add(coef,term);
	}
	
	ll f=mul(con,fpow(sub(1,coef),MOD-2));
	
	cout<<f<<"\n";
	return 0;
}
