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
const ll MOD=998244353,MAXN=1005;

ll n,k;
ll dp[MAXN][2*MAXN][5];
bool vis[MAXN][2*MAXN][5];

ll f(ll i, ll c, ll b){
	ll &res=dp[i][c][b];
	if(vis[i][c][b])return res;
	vis[i][c][b]=1;
	if(i==n)return res=(c==k);
	if(c>k)return res=0;
	fore(h,0,4){
		if(b==0||b==3){
			res+=f(i+1,c+(h!=b),h);
		}
		else{
			if((b==1&&h==2)||(b==2&&h==1))res+=f(i+1,c+2,h);
			else res+=f(i+1,c,h);
		}
		res%=MOD;
	}
	return res;
}

int main(){FIN;
	cin>>n>>k;
	ll res=f(1,1,0)+f(1,1,3)+f(1,2,1)+f(1,2,2);
	res%=MOD;
	pres;
	return 0;
}
