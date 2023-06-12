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
const ll MOD=998244353,MAXN=1e6+5;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll flog(ll b,ll x){
	ll res=0;
	while(x>1)x/=b,res++;
	return res;
}
ll f[MAXN],fi[MAXN];
void factorials(){
	f[0]=1;
	fore(i,1,MAXN)f[i]=f[i-1]*i%MOD;
	fi[MAXN-1]=fpow(f[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)fi[i]=fi[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return f[n]*fi[k]%MOD*fi[n-k]%MOD;
}

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll n=flog(2,r/l);
		ll res=0;
		fore(i,0,n+1){
			ll c=max(r/(fpow(2,n-i)*fpow(3,i))-l+1,(ll)0);
			//cout<<i<<": "<<c<<"\n";
			res=(res+nCr(n,i)*c)%MOD;
		}
		cout<<n+1<<" "<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
