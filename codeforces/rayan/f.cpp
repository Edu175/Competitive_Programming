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
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5;
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
ll nCri(ll n, ll k){ // inv
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fci[n],fc[k]),fc[n-k]);
}
ll inv(ll x){return fpow(x,MOD-2);}
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll r,b,n; cin>>r>>b>>n;
		vector<ii>a;
		a.pb({0,0});
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			x=r-x;
			y=b-y;
			a.pb({x,y});
		}
		n=SZ(a);
		a.pb({r,b});
		sort(ALL(a));
		auto go=[&](ll i, ll j)->ll{
			ll rh=r-a[i].fst;
			ll bh=b-a[i].snd;
			ll rn=a[j].fst-a[i].fst;
			ll bn=a[j].snd-a[i].snd;
			if(rn<0||bn<0)return 0;
			ll c=rn+bn,tot=rh+bh;
			ll num=mul(nCr(c,rn),nCr(tot-c,rh-rn));
			ll res=mul(num,nCri(tot,rh));
			// cout<<"go "<<i<<","<<j<<": "<<res<<" ("<<inv(res)<<")"<<"\n";
			// cout<<"("<<double(num)/nCr(tot,rh)<<")\n";
			return res;
		};
		vector<vv>dp(n+3,vv(n+3));
		for(ll i=n;i>=0;i--)fore(j,i,n+1){
			auto &res=dp[i][j];
			res=go(i,j);
			fore(k,i+1,j)res=sub(res,mul(dp[i][k],go(k,j)));
			// cout<<"dp "<<i<<","<<j<<": "<<res<<"\n";
		}
		auto val=[&](ll i){
			return 2*a[i].fst+a[i].snd; // < MOD
		};
		vector<vv>prob(n+3,vv(n+3));
		prob[n][0]=1;
		ll ans=val(n);
		for(ll i=n-1;i>=0;i--)for(ll c=n;c>=1;c--){
			auto &res=prob[i][c];
			fore(j,i+1,n+1){
				res=add(res,mul(dp[i][j],prob[j][c-1]));
			}
			ll profit=mul(val(i),fpow(2,c-1));
			// cout<<i<<" "<<c<<": "<<a[i].fst<<","<<a[i].snd<<": "<<mul(res,15)<<"/15 "<<profit<<" = "<<mul(res,profit)<<"\n";
			// cout<<mul(res,5)<<"\n";
			ans=add(ans,mul(res,mul(go(0,i),profit)));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
