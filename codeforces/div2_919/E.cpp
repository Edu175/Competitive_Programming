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
const ll MAXN=2505,MOD=998244353;

ll dp[MAXN][MAXN];
ll n,k;
inline ll cut(ll a){return a<MOD?a:a-MOD;}
ll f(ll s, ll u){
	ll &res=dp[s][u];
	if(res!=-1)return res;
	if(s==n)return res=1;
	res=0;
	fore(i,1,k-u+1){
		if(s+u*i>n)break;
		res=cut(res+f(s+u*i,i));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k; k++;
		fore(i,0,n+3)fore(j,0,k+3)dp[i][j]=-1;
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
