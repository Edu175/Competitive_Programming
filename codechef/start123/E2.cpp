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
const ll MAXN=18;
ll g[MAXN];
ll n;
ll dp[1ll<<MAXN];
ll f(ll mk){
	ll &res=dp[mk];
	if(res!=-1)return res;
	if(mk==(1ll<<n)-1)return res=0;
	res=n+5;
	fore(i,0,n)if((mk>>i)&1){
		ll mki=mk|g[i];
		if(mk!=mki)res=min(res,1+f(mki));
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i]=0;
		fore(i,0,n)fore(j,0,n){
			char c; cin>>c;
			if(c=='1')g[i]|=1ll<<j;
		}
		ll res=n+5;
		fore(mk,0,1ll<<n)dp[mk]=-1;
		fore(i,0,n){
			res=min(res,f(1ll<<i));
			cout<<i<<" "<<res-1<<"\n";
		}
		cout<<res-1<<"\n";
	}
	return 0;
}
