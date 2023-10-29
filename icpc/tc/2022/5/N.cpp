#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MOD=1000000007;

ll dp[101][101];
bool vis[101][101];
ll k,d;

ll f(ll n, ll di){
	if(vis[n][di])return dp[n][di];
	//cout<<n<<" "<<di<<"\n";
	if(n==0){
		if(di)return 1;
		else return 0;
	}
	vis[n][di]=1;
	ll &res=dp[n][di];
 	fore(i,1,k+1){
 		if(n-i>=0){
 			if(i>=d)res+=f(n-i,di+1);
 			else res+=f(n-i,di);
 		}
 		res%=MOD;
 	}
	//cout<<r<<"\n";
	return res;
}

int main(){
	ll n; cin>>n>>k>>d;
	cout<<f(n,0);
	return 0;
}
