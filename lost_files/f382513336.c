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
const ll MAXN=3e3+5,MAXF=MAXN,MOD=1e9+7;

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
ll add(ll a, ll b){
	return (a+=b>MOD?a-MOD:a);
}
ll dp[MAXN][MAXN];
int main(){FIN;
	ll n; cin>>n;
	string a; cin>>a;
	ll res=0;
	fore(k,1,n+1)fore(l,0,n-k+1){
		ll r=l+k;
		fore(i,l,r)if()res=add(res,)
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
