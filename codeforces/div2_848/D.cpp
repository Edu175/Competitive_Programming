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
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string c,d; cin>>c>>d;
		ll k=0;
		fore(i,0,n)k+=((c[i]-'0')^(d[i]-'0'));
		ll a[n+1],b[n+1];
		a[0]=0,b[0]=0;
		fore(i,1,n+1){
			ll r=n*fpow((n-b[i-1]*i%MOD+MOD)%MOD,MOD-2)%MOD;
			a[i]=(r+r*i%MOD*fpow(n,MOD-2)%MOD*a[i-1])%MOD;
			b[i]=r*(n-i)%MOD*fpow(n,MOD-2)%MOD;
		}
		ll f[n+1];
		f[n]=a[n];
		for(ll i=n-1;i>=0;i--)f[i]=(a[i]+b[i]*f[i+1])%MOD;
		cout<<f[k]<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
