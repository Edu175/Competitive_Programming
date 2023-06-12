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
const ll MAXN=5e6;
ll MOD;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
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
ll nPr(ll n, ll k){
	return nCr(n,k)*f[k]%MOD;
}
ll n;
ll cnt1(){
	return nPr(2*n,n)*f[2*n]%MOD;
}
ll cnt2(){
	ll res=0;
	fore(i,0,n+1)res=(res+fpow(f[n],2)*fpow(nCr(n,i),2)%MOD*nPr(2*n-i,n)%MOD)%MOD;
	return res;
}

int main(){FIN;
	cin>>n>>MOD;
	factorials();
	ll c[4];
	c[0]=1;
	c[1]=((f[2*n])*2-f[n]-1+MOD)%MOD;
	c[2]=((cnt1()*2-cnt2()-c[0]-c[1])%MOD+MOD)%MOD;
	c[3]=(f[3*n]-(c[0]+c[1]+c[2])%MOD+MOD)%MOD;
	ll res=0;
	fore(i,0,4)res=(res+c[i]*i)%MOD;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
