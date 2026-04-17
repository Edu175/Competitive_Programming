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
const ll MOD=676767677,MAXF=2e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

ll bec(ll b, ll c){return nCr(b+c-1,b);}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m; m--;
		ll res=0;
		auto f=[&](ll l, ll r, ll d, auto &&f)->void {
			if(r-l-1<=0)return;
			ll h=(l+r)/2;
			ll tot=bec(m,n+1);
			ll nol=bec(m,n-(h-l)+1);
			ll nor=bec(m,n-(r-h)+1);
			ll both=bec(m,n-(r-l)+1);
			ll cur=tot;
			if(l!=-1)cur=sub(cur,nol);
			if(r!=n)cur=sub(cur,nor);
			if(l!=-1&&r!=n)cur=add(cur,both);
			cur=mul(cur,d+1);
			res=add(res,cur);
			f(l,h,d+1,f);
			f(h,r,d+1,f);
			// cerr<<l<<","<<r<<" "<<d<<": "<<m<<": "<<cur<<"\n";
		};
		f(-1,n,0,f);
		cout<<res<<"\n";
	}
	return 0;
}
