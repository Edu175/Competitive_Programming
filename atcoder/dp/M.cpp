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
const ll MAXK=1e5+5,MOD=1e9+7;

ll dp[105][MAXK];
ll n; ll a[105], sp[105];

ll f(ll i, ll k){
	ll &res=dp[i][k];
	if(res>=0)return res;
	if(k==0)return res=1;
	if(i==n)return res=0;
	res=0;
	fore(j,0,a[i]+1){
		if(k-j>=0&&k-j<=sp[i+1]){
			res+=f(i+1,k-j);
			if(res>=MOD)res-=MOD;
		}
	}
	//cout<<i<<" "<<k<<" = "<<res<<"\n";
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sp[n]=0;
	for(ll i=n-1; i>=0; i--){
		sp[i]=a[i]+sp[i+1];
	}
	cout<<f(0,k)<<"\n";
	return 0;
}
