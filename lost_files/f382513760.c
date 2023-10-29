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
const ll MAXN=3e5+5,INF=1e15;

ll y[MAXN],x[MAXN];
ll dp[MAXN][3];

ll ch(ll p, ll n){
	if(p&&n)return 2;
	return n;
}
ll n;
ll f(ll i, ll b){
	ll &res=dp[i][b];
	if(res!=-1)return res;
	if(b==2)return res=-INF;
	if(i==n)return res=0;
	return res=max(f(i+1,b),y[i]+f(i+1,ch(b,x[i])));
}

int main(){FIN;
	cin>>n;
	mset(dp,-1);
	fore(i,0,n)cin>>x[i]>>y[i];
	cout<<f(0,0)<<"\n";
	return 0;
}
