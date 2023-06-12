#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MOD=1e9+7,MOD2=1e9+6;

ll fpow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll inv(ll a){return fpow(a,MOD-2);}

ll sd(ll p, ll k){return (fpow(p,k+1)-1)*inv(p-1)%MOD;}

int main(){FIN;
	ll n; cin>>n;
	ll p[n],k[n];
	ll num=1,sum=1,prod=1;
	ll x=1,sqr=1;
	ll num2=1;
	fore(i,0,n){
		cin>>p[i]>>k[i];
		sqr=sqr*fpow(p[i],k[i]/2)%MOD;
		num=num*(k[i]+1)%MOD;
		num2=num2*(k[i]+1)%MOD2;
		sum=sum*sd(p[i],k[i])%MOD;
		x=x*fpow(p[i],k[i])%MOD;
	}
	prod=fpow(x,num2/2);
	if(num2&1)prod=prod*sqr%MOD;
	cout<<num<<" "<<sum<<" "<<prod<<"\n";
	cout<<2<<" "<<4<<" "<<6<<"\n";
	return 0;
}
