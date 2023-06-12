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
const ll MOD=998244353,MAXN=2e3+5,MAXF=2*MAXN;

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
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}

ll n,m;
ll paths(ll i, ll j){return nCr(n+m-2-i-j,n-1-i);}
char a[MAXN][MAXN];
ll dp[MAXN][MAXN],s[MAXN][MAXN];

ll f(ll i, ll j){
	ll &res=dp[i][j];
	if(res!=-1)return res;
	res=0;
	if(i<n-1){
		ll k=paths(i+1,j);
		res=(res+f(i+1,j))%MOD;
		s[i][j]=(s[i][j]+s[i+1][j])%MOD;
		if(a[i][j]=='Y'&&a[i+1][j]=='Y'){
			res=(res+k+2*s[i+1][j])%MOD;
			s[i][j]=(s[i][j]+k)%MOD;
		}
	}
	if(j<m-1){
		ll k=paths(i,j+1);
		res=(res+f(i,j+1))%MOD;
		s[i][j]=(s[i][j]+s[i][j+1])%MOD;
		if(a[i][j]=='Y'&&a[i][j+1]=='Y'){
			res=(res+k+2*s[i][j+1])%MOD;
			s[i][j]=(s[i][j]+k)%MOD;
		}
	}
	return res;
}
int main(){FIN;
	cin>>n>>m;
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	factorials();
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
