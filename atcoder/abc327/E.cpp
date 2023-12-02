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
typedef long double ld;
typedef pair<ll,ll> ii;

const ll MAXN=5005,INF=MAXN*MAXN;
ld p[MAXN];
ld dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
ld pot[MAXN];
ll n;

ld f(ll i, ll k){
	ld &res=dp[i][k];
	if(vis[i][k])return res;
	vis[i][k]=1;
	if(i==n){
		if(k)return res=-INF;
		return res=0;
	}
	res=f(i+1,k);
	if(k)res=max(res,pot[k-1]*p[i]+f(i+1,k-1));
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>p[i];
	pot[0]=1;
	fore(i,1,n+3)pot[i]=pot[i-1]*0.9;
	ld res=-INF;
	fore(k,1,n+1){
		ld resi=f(0,k);
		ld den=0;
		fore(i,1,k+1)den+=pot[k-i];
		resi/=den;
		resi-=1200/sqrt(k);
		//cout<<k<<": "<<f(0,k)<<" "<<resi<<"\n";
		res=max(res,resi);
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
