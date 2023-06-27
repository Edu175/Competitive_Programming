#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define forr(i,a,b) for(ll i=b-1,ggdem=a;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e3+5,INF=5*MAXN;

ll n,m;
string a,b;
ll dp[2][MAXN][2];
ll f(ll i, ll j, ll d){return dp[i%2][j][d];}
int main(){FIN;
	cin>>n>>m;
	cin>>a>>b;
	forr(i,0,n+1)forr(j,0,m+1)fore(d,0,2){
		ll &res=dp[i%2][j][d];
		res=-INF;
		if(d==1)res=max(res,-i-j);
		if(i==n&&j==m&&!d){res=-INF;continue;}
		if(i<n)res=max(res,f(i+1,j,d));
		if(j<m)res=max(res,f(i,j+1,d));
		if(i<n&&j<m&&a[i]==b[j])res=max(res,(!d)*(i+j)+4+f(i+1,j+1,1));
	}
	cout<<max((ll)0,f(0,0,0))<<"\n";
	return 0;
}
