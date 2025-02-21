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
const ll MOD=998244353,MAXN=3e5+5;

vector<ll> fse(vector<ll>&a){ //index of first smaller element to the left (-1 if none)
//for bigger change for condition, for right reverse a, then f, and indexes (n-1-x)
	reverse(ALL(a));
	ll n=SZ(a);
	vector<ll>f(n,-1);
	fore(i,0,n){
		ll x=i-1;
		for(;x!=-1&&!(a[x]<a[i]);x=f[x],f[i]=x);
		f[i]=x;
	}
	reverse(ALL(f));
	for(auto &i:f)i=n-1-i;
	return f;
}

ll dp[2][MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>to=fse(a);
		dp[0][n]=0;
		dp[1][n]=1;
		vector<ll>sp(n+2); // 1
		sp[n]=1;
		//imp(to);
		for(ll i=n-1;i>=0;i--){
			dp[1][i]=(sp[i+1]-sp[to[i]+1]+dp[0][to[i]]+MOD)%MOD;
			sp[i]=(sp[i+1]+dp[1][i])%MOD;
			if(to[i]!=n)dp[0][i]=(dp[0][to[i]]+dp[1][to[i]])%MOD;
			else dp[0][i]=0;
			//cout<<i<<": "<<dp[0][i]<<"+"<<dp[1][i]<<" = "<<dp[0][i]+dp[1][i]<<"\n";
		}
		cout<<(dp[0][0]+dp[1][0])%MOD<<"\n";
	}
	return 0;
}
