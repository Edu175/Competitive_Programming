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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MOD=998244353;

ll fpow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll inv(ll a){return fpow(a,MOD-2);}
ll f[70];
void factorial(){
	f[0]=1;
	fore(i,1,70)f[i]=f[i-1]*i%MOD;
}

ll nCr(ll n,ll k){
	return f[n]*inv(f[k])%MOD*inv(f[n-k])%MOD;
}

int main(){FIN;
	factorial();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a=0,b=0;
		a=nCr(n,n/2)-1;
		while(n>4){
			b+=2*nCr(n-2,n/2-2)%MOD-nCr(n-3,n/2-3);
			b+=MOD;
			b%=MOD;
			n-=4;
		}
		if(n==4)b+=2*nCr(n-2,n/2-2)%MOD;
		b%=MOD;
		a-=b;
		a+=MOD;a%=MOD;
		cout<<a<<" "<<b<<" "<<1<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
