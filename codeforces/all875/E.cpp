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
const ll MOD=998244353,MAXN=3e5+5,MAXF=MAXN;

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

//ll dp[MAXN];
ll f(ll m){
	//ll &res=dp[m];
	//if(res!=-1)return res;
	ll res;
	if(m&1)return res=0;
	if(m==0)return res=1;
	return res=(nCr(m,m/2)-nCr(m,m/2-1)+MOD)%MOD;
}
int main(){FIN;
	//mset(dp,-1);
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a;
		fore(i,0,k){
			ll l,r; cin>>l>>r; l--;
			a.pb(l),a.pb(r);
		}
		a.pb(0),a.pb(n);
		sort(ALL(a));
		ll res=1;
		imp(a);
		fore(i,0,SZ(a)-1){
			res=(res*f(a[i+1]-a[i]))%MOD;
			cout<<a[i+1]-a[i]<<": "<<f(a[i+1]-a[i])<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
