#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=4e6+5;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b); e>>=1;
	}
	return r;
}
ll fc[MAXF],fci[MAXF],med=(MOD+1)/2;
ll nCr(ll n, ll k){
	if(n<0||k<0||n-k<0)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
}

ll get(ll n, ll k){
	if(n==0&&k==0)return 1;
	if(k<=0||n<=0)return 0;
	ll s=mul(nCr(n,2*k),fc[2*k]);
	if(!s)return 0;
	ll pinga=mul(fc[n-k-1],fci[k-1]);
	// cout<<s<<" "<<pinga<<" s ponga\n";
	ll res=mul(s,pinga);
	res=mul(res,fpow(med,k));
	res=mul(res,fci[k]);
	return res;
}

int main(){
	JET
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
	
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		if(m>n){cout<<"0\n";continue;}
		if(m==n){cout<<mul(fc[n-1],med)<<"\n";continue;}
		ll k=n-m;
		ll ans=0;
		fore(u,0,n+1){
			ll rq=get(n-u,k-u);
			ll res=mul(nCr(n,u),rq);
			// res=mul(res,fpow(med,));
			// cout<<u<<": "<<nCr(n,u)<<"*"<<rq<<" = "<<res<<"\n";
			ans=add(ans,res);
		}
		// ans=mul(ans,fci[k]);
		cout<<ans<<"\n";
	}
	return 0;
}
