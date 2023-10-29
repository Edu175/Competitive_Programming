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
const ll MOD=998244353,MAXF=3e5+5,MAXN=MAXF;

//==============PRECOMPUTO CUENTAS=================================================
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
ll nPr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[n-k]%MOD;
}
ll p26[MAXF];
void pot26(){
	p26[0]=1;
	fore(i,1,MAXF)p26[i]=p26[i-1]*26%MOD;
}
//=================================================================================

bool is(char c){return (c>='A'&&c<='Z');}
string s;
ll q[MAXN], c[MAXN], oc[MAXN][30];	// A 
ll dp[MAXN][5];

ll f(ll i, ll b){
	if(i<0)return 1;
	ll &res=dp[i][b];
	if(res!=-1)return res;
	if(b==2){
		if(c[i]==-1)return res=0;
		res=0;
		fore(j,0,min(q[i],26-c[i])+1){
			res+=nPr(26-c[i],j)*nCr(q[i],j)%MOD*p26[q[i]-j]%MOD;
			res%=MOD;
		}
		return res;
	}
	if(s[i]!='?')return res=f(i-1,b+(b^is(s[i])))%MOD;
	return res=(26*f(i-1,b)+26*f(i-1,b+1))%MOD;
}

int main(){FIN;
	cin>>s;
	ll n=SZ(s);
	factorials();
	pot26();
	q[0]=(s[0]=='?');
	if(is(s[0]))oc[0][s[0]-'A']++;
	c[0]=is(s[0]);
	fore(i,1,n){
		q[i]=q[i-1]+(s[i]=='?');
		fore(j,0,30)oc[i][j]=oc[i-1][j];
		c[i]=c[i-1];
		if(is(s[i])){
			oc[i][s[i]-'A']++;
			if(c[i]!=-1){
				if(oc[i][s[i]-'A']==1)c[i]++;
				else c[i]=-1;
			}
		}
	}
	/*fore(i,0,n){
		cout<<i<<": #? "<<q[i]<<", #oc=1 "<<c[i]<<", oc: "; imp(oc[i]);
	}*/
	mset(dp,-1);
	ll res=f(n-1,0);
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
