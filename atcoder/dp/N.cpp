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
const ll MAXN=405;

ll a[MAXN],ps[MAXN];
ll dp[MAXN][MAXN];

ll f(ll l, ll r){
	ll &res=dp[l][r];
	if(res>=0)return res;
	if(l+1==r)return res=0;
	res=f(l,l+1)+f(l+1,r);
	fore(i,l+2,r){
		res=min(res,f(l,i)+f(i,r));
	}
	res+=ps[r]-ps[l];
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)ps[i]=ps[i-1]+a[i-1];
	mset(dp,-1);
	cout<<f(0,n)<<"\n";
	return 0;
}
