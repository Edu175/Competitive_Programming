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
const ll MAXN=5005,INF=3*MAXN;

ll dp[MAXN][MAXN];
ll n,m;
string a,b;
ll f(ll i, ll j){
	ll &res=dp[i][j];
	if(res!=-1)return res;
	if(i==n&&j==m)return res=0;
	if(i==n)return res=1+f(i,j+1);
	if(j==m)return res=1+f(i+1,j);
	res=1+min({f(i+1,j),f(i,j+1),f(i+1,j+1)});
	if(a[i]==b[j])res=min(res,f(i+1,j+1));
	//cout<<i<<" "<<j<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>a>>b;
	n=SZ(a),m=SZ(b);
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
