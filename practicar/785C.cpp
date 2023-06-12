#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=4e4+5,MOD=1e9+7;

vector<ll>p;
ll dp[MAXN];
int main(){FIN;
	fore(i,1,MAXN){
		string s=to_string(i);
		string w=s; reverse(ALL(w));
		if(s==w)p.pb(i);
	}
	/*cout<<SZ(p)<<"\n";
	imp(p);*/
	dp[0]=1;
	fore(k,0,SZ(p))fore(i,0,MAXN){
		if(i+p[k]<MAXN)dp[i+p[k]]=(dp[i+p[k]]+dp[i])%MOD;
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

