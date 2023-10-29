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
typedef pair<ll,ll> ii;
const ll MAXN=2005,MAXF=MAXN;
ll MOD;

ll fpow(ll b, ll e){
	if(e<0)return fpow(fpow(b,-e),MOD-2);
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

ll dp[MAXN];

ll f(ll n){
	ll &res=dp[n];
	if(res!=-1)return res;
	if(n==0)return res=1;
	res=0;
	fore(m,1,n+1){
		//cout<<n<<" "<<m<<": "<<m-1<<" "<<fpow(2,MOD-2)<<" "<<fpow(m,m-3<<" "<<f(n-m)<<": "<<(m-1)*(m-1)*fpow(2,MOD-2)%MOD*fpow(m,m-3)*f(n-m)<<"\n";
		res=(res+m*(m-1)*fpow(2,MOD-2)%MOD*fpow(m,m-3)%MOD*f(n-m))%MOD;
	}
	return res;
}


int main(){FIN;
	ll n; cin>>n>>MOD;
	factorials();
	mset(dp,-1);
	ll res=f(n);
	cout<<res<<" "<<fc[n]<<" "<<fpow(2,n)<<": ";
	res=res*fc[n]%MOD*fpow(2,n)%MOD;
	cout<<res<<"\n";
	return 0;
}
