#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector <ii> vi;
const ll mod=1e9+7;
vi fact(ll n){
	vi res; ll sz=-1;
	for(int i=2; i*i<=n; i++){
		if(n%i==0) {res.pb({i,0}); sz++;}
		while(n%i==0){res[sz].snd++; n/=i;}		
	}
	if(n>1) res.pb({n,1});
	return res;
}
ll mul(ll n, ll m){
	return (n*m)%mod;
}
ll add(ll n, ll m){
	n+=m;
	if(n>=mod)n-=mod;
	return n;
}
// ll binpow(ll n, ll b){
// 	if(!b) return 1ll;
// 	ll res=binpow(n,b/2);
// 	if(b&1) return mul(res,mul(res,n));
// 	return mul(res,res);
	
// }
ll binpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b);
		e>>=1;
	}
	return r;
}
int main(){
	JET
	ll n; ll k; cin>>n>>k;
	vi v=fact(n);
	vv div; div.pb(1); ll sz=1;
	for(ii x: v){
			fore(i,0,sz){
				ll aux=x.fst;
				fore(j,0,x.snd){div.pb(div[i]*aux); sz++; aux*=x.fst;}
			}
	}
	ll cd[sz];
	mset(cd,-1);
	vector <vv> suma(sz);
	fore(i,0,sz)fore(j,0,i){
		if(div[i]%div[j]==0) {suma[j].pb(i); cd[i]--;}
	}
	fore(i,0,sz){
		cd[i]=-cd[i]; cd[i]=binpow(cd[i],mod-2); div[i]%=mod;
	}
	ll dp[sz];
	mset(dp,0);
	dp[sz-1]=1;
	fore(i,0,k){
		fore(j,0,sz) {
			ll aux=mul(dp[j],cd[j]);
			for(ll t:suma[j]) aux=add(aux,mul(cd[t],dp[t]));
			dp[j]=aux;
	}}
	ll A=0;
	fore(i,0,sz){
		A=add(A,mul(div[i],dp[i]));
	}
	cout<<A<<"\n";
	
}