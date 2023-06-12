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
const ll MOD=1e9+7,MAXN=2e6+5;

ll f[MAXN];
void factorial(){
	f[0]=1,f[1]=1;
	fore(i,2,MAXN)f[i]=(f[i-1]*i)%MOD;
}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll inv(ll a){return fpow(a,MOD-2);}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return (f[n]*inv((f[k]*f[n-k])%MOD))%MOD;
}
ll bcj(ll n,ll k){
	return nCr(n+k-1,k-1);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	factorial();
	ll res=0;
	fore(g,0,k+1){
		//cout<<g<<"\n";
		//ll dif=res;
		//ll cfs=nCr(k-1,g-1),cfm=nCr(n-k,g),cfme=nCr(n-k,g-1);
		ll cfs=bcj(k-g,g), cfm=bcj(n-(k+g),g+1), cfme=bcj(n-(k+g-1),g);
		//cout<<g<<": cfs="<<cfs<<" cfm="<<cfm<<" cfme="<<cfme<<"\n";
		res+=fpow(3,n-2*g)*cfs%MOD*cfm%MOD;
		res%=MOD;
		//cout<<"normal="<<res-dif; dif=res;
		res+=fpow(3,n-(2*g-1))*cfs%MOD*cfme%MOD;
		res%=MOD;
		//cout<<" especial="<<res-dif<<"\n\n";
	}
	if(k==0)res=fpow(3,n);
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
