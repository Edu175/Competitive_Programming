#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll K=20,L=4e4,R=5e4,MAXN=105;
const ll VAL=1e9;
vv MODS;
mt19937 rng(175);

bool dp[K][MAXN][R];

void dodp(ll k, vv a){
	ll MOD=MODS[k],n=SZ(a);
	dp[k][n][VAL%MOD]=1;
	for(ll i=n-1;i>=0;i--)fore(v,0,MOD){
		dp[k][i][v]=dp[k][i+1][v]|dp[k][i+1][(v+a[i])%MOD];
	}
}

vv ind;
ll n;
vv a;
void f(ll i, vv &rem){
	// cout<<i<<": "; imp(ind)
	if(i==n){
		ll s=0;
		for(auto j:ind)s+=a[j];
		if(s==VAL){
			cout<<SZ(ind)<<" ";
			for(auto j:ind)cout<<j+1<<" ";
			cout<<"\n";
			exit(0);
		}
		return;
	}
	ll go0=1,go1=1;
	fore(k,0,K)go0&=dp[k][i+1][rem[k]];
	if(go0){
		f(i+1,rem);
	}
	// vv prox(K);
	// fore(k,0,K)prox[k]=(rem[k]+a[i])%MODS[k];
	fore(k,0,K)rem[k]=(rem[k]+a[i])%MODS[k];
	fore(k,0,K)go1&=dp[k][i+1][rem[k]];
	if(go1){
		ind.pb(i);
		f(i+1,rem);
		ind.pop_back();
	}
	fore(k,0,K)rem[k]=(rem[k]-a[i]%MODS[k]+MODS[k])%MODS[k];
}

int main(){FIN;
	fore(i,0,K)MODS.pb(rng()%(R-L)+L);
	cin>>n;
	a=vv(n);
	fore(i,0,n)cin>>a[i];
	assert(*min_element(ALL(a)) > 3);
	fore(k,0,K)dodp(k,a);
	cerr<<"done dp\n";
	auto v=vv(K,0);
	f(0,v);
	assert(0);
	return 0;
}