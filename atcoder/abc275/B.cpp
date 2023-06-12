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
int main(){FIN;
	ll a[6]; fore(i,0,6)cin>>a[i],a[i]%=MOD;
	ll n=1,d=1;
	fore(i,0,3)n=(n*a[i])%MOD;
	fore(i,3,6)d=(d*a[i])%MOD;
	//imp(a);
	cout<</*n<<" "<<d<<" "<<*/((n-d)+MOD)%MOD;
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
