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
const ll MAXN=1e7+5,MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll frac(ll a, ll b){return a*fpow(b,MOD-2)%MOD;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll l=max((ll)1,m-n);	//l<=n always holds
		ll r=(m+1)/2;			//r-1<=n always holds
		// n=5 m=4 l=1
		ll s=fpow(frac(1,3),n-l+1)*fpow(2,m-2*l)%MOD;
		cout<<s<<"\n";
		s=s*fpow(frac(7,4),r-l-1)%MOD;
		cout<<s<<"\n";
		cout<<l<<" "<<r<<": "<<r-l-1<<"\n";
		cout<<s<<"\n";
		if(m<=n){
			s=(s+fpow(frac(2,3),m-1)*fpow(frac(1,3),n-m+1))%MOD;
			s=(s+fpow(frac(2,3),1)*fpow(frac(1,3),n-1))%MOD;
		}
		cout<<s<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
