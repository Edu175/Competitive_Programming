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
const ll MAXN=3004;

double a[MAXN];
ll n;
double dp[MAXN][MAXN];

double f(ll i, ll c){
	double &res=dp[i][c];
	if(res>=0)return res;
	if(i==n)return res=(2*c>n);
	return res=a[i]*f(i+1,c+1)+(1-a[i])*f(i+1,c);
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	cout<<fixed<<setprecision(15)<<f(0,0)<<"\n";
	return 0;
}
