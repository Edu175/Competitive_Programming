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
const ll MOD=998244353,MAXV=1e6+5,MAXN=5e3+5;

int cr[MAXV]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
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
ll fc[MAXV],fci[MAXV];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXV)fc[i]=fc[i-1]*i%MOD;
	fci[MAXV-1]=fpow(fc[MAXV-1],MOD-2);
	for(ll i=MAXV-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
ll dp[MAXN][MAXN],l;
vector<ll>b;
ll f(ll i, ll k){
	ll &res=dp[i][k];
	if(res!=-1)return res;
	if(k>l)return res=0;
	if(i==SZ(b)){
		if(k==l)return res=1;
		return res=0;
	}
	res=(f(i+1,k)+f(i+1,k+1)*(l-k)%MOD*b[i])%MOD;
	return res;
}
int main(){FIN;
	factorials();
	init_sieve();
	ll n; cin>>n;
	ll a[2*n];
	vector<ll>e,p; set<ll>st;
	fore(i,0,2*n){
		cin>>a[i];
		if(a[i]==1||st.count(a[i])||cr[a[i]]!=-1)e.pb(a[i]);
		else st.insert(a[i]);
	}
	for(auto i:st)p.pb(i);
	vector<ll> r(MAXV);
	for(auto i:e)r[i]++;
	l=n-SZ(e);
	if(SZ(e)>n){
		cout<<"0\n";
		return 0;
	}
	ll res=fc[n];
	for(auto i:r)res=res*fpow(fc[i],MOD-2)%MOD;
	res=res*fpow(fc[l],MOD-2)%MOD;
	for(auto i:p)b.pb(fpow(r[i]+1,MOD-2));
	mset(dp,-1);
	res=res*f(0,0)%MOD;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
