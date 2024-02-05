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
typedef pair<ll,ll> ii;
const ll MAXB=55;

/*ll n;
ll dp[MAXB][2];
ll f(ll i, ll b){
	if(i==-1)return 0;
	ll &res=dp[i][b];
	if(res!=-1)return res;
	ll d=(n>>i)&1;
	res=f(i-1,b&&!d);
	if(!b||(b&&d)res+=f(i,b)* (cantidad de numeros validos);
	return res;
	
}*/
ll f(ll n){
	if(n==0)return 0;
	ll s=63-__builtin_clzll(n);
	n^=1ll<<s;
	return (1ll<<s)*s/2+n+1+f(n);
}
int main(){FIN;
	ll n; cin>>n;
	//mset(dp,-1);
	//cout<<f(MAXB-1,1)<<"\n";
	cout<<f(n)<<"\n";
	return 0;
}
