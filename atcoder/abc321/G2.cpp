#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
const ll MAXN=17,MOD=998244353,MAXF=2e5+5;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
ll inCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fci[n]*fc[k]%MOD*fc[n-k]%MOD;
}

ll r[1ll<<MAXN],b[1ll<<MAXN];
ll n;

ll dp[1ll<<MAXN];
ll pr[1ll<<MAXN];
inline ll ppc(ll x){return __builtin_popcountll(x);}
inline ll ctz(ll x){return x?__builtin_ctzll(x):64;}
int main(){FIN;
	factorials();
	cin>>n;
	ll m; cin>>m;
	fore(i,0,m){
		ll x; cin>>x; x--;
		r[1ll<<x]++;
	}
	fore(i,0,m){
		ll x; cin>>x; x--;
		b[1ll<<x]++;
	}
	fore(mk,0,1ll<<n){
		ll rs=0,bs=0;
		fore(i,0,n)if(mk&(1ll<<i)){
			rs+=r[1ll<<i];
			bs+=b[1ll<<i];
		}
		r[mk]=rs;
		b[mk]=bs;
	}
	fore(mk,1,1ll<<n){
		if(r[mk]!=b[mk])continue;
		ll& res=dp[mk];
		ll &p=pr[mk];
		p=1;
		vector<ll>is;
		fore(i,0,n)if(mk&(1ll<<i))is.pb(i);
		fore(mki,1,1ll<<(SZ(is)-1)){
			ll mk1=0,mk2=0;
			//cout<<mk<<" "<<mki<<":\n";
			//for(ll s=mki,i=ctz(s);s;s^=1ll<<i,i=ctz(s)){
			fore(i,0,SZ(is)){
				//cout<<s<<" "<<i<<" "<<j<<endl;
				if(mki&(1ll<<i))mk2|=1ll<<is[i];
				else mk1|=1ll<<is[i];
			}
			//ll mk1=mk^mk2;
			//cout<<mk1<<" "<<mk2<<"\n";
			ll r1=r[mk1],b1=b[mk1];
			ll r2=r[mk2],b2=b[mk2];
			if(r1!=b1||r2!=b2)continue;
			ll pi=pr[mk1]*inCr(b1+b2,r2)%MOD;
			p=(p-pi+MOD)%MOD;
			res=(res+pi*(1+dp[mk2]))%MOD;
		}
		res=(res+p)%MOD;
	}
	cout<<dp[(1ll<<n)-1]<<"\n";
	return 0;
}
