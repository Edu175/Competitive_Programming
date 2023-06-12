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
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	queue<ll>q; q.push(1);
	ll n=1;
	ll t; cin>>t;
	while(t--){
		ll ty; cin>>ty; ty--;
		if(!ty){
			ll x; cin>>x;
			q.push(x);
			n=(n*10+x)%MOD;
		}
		else if(ty==1){
			ll x=q.front();
			n=(n-x*fpow(10,SZ(q)-1)%MOD+MOD)%MOD;
			q.pop();
		}
		else {
			cout<<n<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
