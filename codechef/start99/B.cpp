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
const ll MAXN=1e5+5;

ll dp[MAXN][3][3];
ll a[MAXN];
ll n;

ll f(ll i, ll s2, ll s1){
	ll &res=dp[i][s2][s1];
	if(res!=-1)return res;
	if(i==n)return res=0;
	if(i>=2){
		ll x=(s2+a[i-2]+s1+a[i-1]+a[i])%3;
		x=(3-x)%3;
		res=x+f(i+1,s1,x);
		//cout<<a[i-2]<<" "<<a[i-1]<<" "<<a[i]<<"\n";
		//cout<<i<<" "<<s2<<" "<<s1<<": "<<x<<" "<<res<<"\n"; 
		return res;
	}
 	res=min({f(i+1,s1,0),1+f(i+1,s1,1),2+f(i+1,s1,2)});
 //	cout<<i<<" "<<s2<<" "<<s1<<": "<<res<<"\n"; 
 	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n+3){
			fore(j,0,3)fore(k,0,3)dp[i][j][k]=-1;
		}
		fore(i,0,n)cin>>a[i];
		cout<<f(0,0,0)<<"\n";
	}
	return 0;
}
