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
const int MAXN=105,MAXS=1e4+5,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int dp[MAXN][MAXN][MAXS];
int a[MAXN];
int n,k;
int f(int i, int c, int s){
	int &res=dp[i][c][s];
	if(res>=0)return res;
	if(i==n){
		res=(c==0&&s<=k);
		//cout<<i<<" "<<c<<" "<<s<<": "<<res<<"\n";
		return res;
	}
	res=f(i+1,c,s);
	res=add(res,f(i+1,c+1,s+a[i]));
	res=add(res,mul(c,f(i+1,c,s)));
	if(c)res=add(res,mul(c,f(i+1,c-1,s-a[i])));
	//cout<<i<<" "<<c<<" "<<s<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n); reverse(a,a+n);
	//fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	mset(dp,-1);
	cout<<f(0,0,0)<<"\n";
	return 0;
}
