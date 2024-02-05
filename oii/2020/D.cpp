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
const ll MOD=1e9,MAXK=55;

ll MD=MOD;
ll dpC[MAXK][MAXK][MAXK];
ll nCr(ll n, ll k, ll d){
	if(n<0||k<0)return 0;
	ll &res=dpC[n][k][d];
	if(res!=-1)return res;
	if(n-k<0)return res=0;
	if(k==0||k==n)return res=1;
	return res=(nCr(n-1,k,d)+nCr(n-1,k+1,d))%(MOD*d);
}

ll fpo


ll dp[MAXK];
ll rec(ll k, ll n){
	ll &res=dp[k];
	if(res!=-1)return res;
	if(k==0)return res=n;
	
	
}
ll fs(ll k, ll n){
	mset(dp,-1);
	mset(dpC,-1);
	MD=MOD*(k+1);
	
}

int main(){FIN;
	mset(dpC,-1);
	ll n,k; cin>>n>>k;
	
	return 0;
}
