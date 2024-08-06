#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll C=18,MAXN=(1ll<<C)+5;

ll n,c,k;
ll go[MAXN][C];
map<ll,ll> dp[MAXN];
ll f(ll i, ll mk){
	if(i+k>=n)return __builtin_popcount(mk);
	if(dp[i].count(mk))return dp[i][mk];
	// cout<<"f "<<i<<" "<<mk<<"\n";
	ll &res=dp[i][mk];
	fore(j,0,c)if(mk>>j&1){
		ll p=go[i+k][j];
		if(p>i)return res=f(p,mk);
	}
	res=C;
	fore(j,0,c)if(!(mk>>j&1)){
		ll p=go[i+k][j];
		if(p>i)res=min(res,f(p,mk|(1<<j)));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>c>>k;
		string s; cin>>s;
		reverse(ALL(s));
		fore(i,0,c)go[0][i]=-1;
		fore(i,1,n){
			fore(j,0,c)go[i][j]=go[i-1][j];
			go[i][s[i]-'A']=i;
			// fore(j,0,c)cout<<go[i][j]<<" ";;cout<<"\n";
		}
		fore(i,0,n+5)dp[i].clear();
		ll res=f(0,1<<(s[0]-'A'));
		cout<<res<<"\n";
	}
	return 0;
}
