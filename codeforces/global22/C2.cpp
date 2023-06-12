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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

ll dp[105][105][4][4];
ll f(ll e, ll o, ll s, ll p){
	ll &res=dp[e][o][s][p];
	if(res>=0)return res;
	if(e+o==0)return res=(s==p);
	res=1;
	if(e)res=min(res,f(e-1,o,s,p^1));
	if(o)res=min(res,f(e,o-1,s^=(!p),p^1));
	res^=1;
	return res;
}


int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll c[2]={0,0};
		fore(i,0,n){
			ll x;cin>>x;
			c[x&1]++;
		}
		if(f(c[0],c[1],0,0))cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
