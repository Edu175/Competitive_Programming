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
const ll MOD=1e9+7,MAXF=10005;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,c,m; cin>>n>>c>>m;
		vv a(m),oc(n),sp(n+1),loc(n,-1);
		vv pos;
		fore(i,0,m){
			cin>>a[i]; a[i]--;
			if(a[i]!=-1)oc[a[i]]++,loc[a[i]]=i;
			else pos.pb(i);
		}
		fore(i,1,n+1)sp[i]=sp[i-1]+oc[i-1];
		
		vector<vv>dp(n+3,vv(m+3));
		dp[n][m]=1;
		for(ll i=n-1;i>=0;i--)fore(h,0,m+1){
			auto &res=dp[i][h];
			ll us=h-sp[i],e=h+c;
			ll z=lower_bound(ALL(pos),e)-pos.begin();
			z-=us;
			if(loc[i]>=e||z<0||e>m)continue;
			fore(t,0,min(z,c-oc[i])+1){ // de mas
				ll resi=0;
				if(h+t+oc[i]<=m)resi=mul(nCr(z,t),dp[i+1][h+t+oc[i]]);
				// if(i==n-1&&t+oc[i])pinga
				res=add(res,resi);
			}
			// if(i==2&&h>2)res=0;
			// cout<<i<<" "<<h<<": "<<res<<"\n";
		}
		cout<<dp[0][0]<<"\n";
	}
	return 0;
}
