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
typedef pair<ll,ll> ii;
const ll MOD=998244353;

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii dp[65][4]; ll n;
ii f(ll p, ll b){
	if(p==-1){
		//cout<<"-1 "<<(b^1)<<"\n";
		if(b)return {0,0};
		else return {0,1};
	}
	ii &res=dp[p][b];
	if(res.fst!=-1)return res;
	ll d=(n&(1ll<<p))!=0;
	//if(b&&d)return res={0,0};
	res=f(p-1,d); // xor 0
	//cout<<p<<" "<<b<<": "<<(n&(1ll<<p))<<"\n";
	if(b^d){ // xor 1
		ll r=f(p-1,d^1).fst,q=f(p-1,d^1).snd;
		//cout<<p<<" "<<b<<": "<<q<<" "<<r<<": "<<res.fst<<" "<<res.snd<<"\n";
		res.fst=(res.fst+(1ll<<p)%MOD*q%MOD+r)%MOD;
		res.snd=(res.snd+q)%MOD;
	}
	//cout<<p<<" "<<b<<": "<<d<<": "<<res.fst<<" "<<res.snd<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		if(m>=3){
			__int128 ni=n;
			__int128 res=(ni+(ni&1))*(ni/2+1)/2;
			ll pr=res%MOD;
			cout<<pr<<"\n";
			continue;
		}
		if(m==1){
			cout<<n%MOD<<"\n";
			continue;
		}
		fore(i,0,65)fore(j,0,4)dp[i][j]={-1,-1};
		cout<<f(62,0).fst<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
