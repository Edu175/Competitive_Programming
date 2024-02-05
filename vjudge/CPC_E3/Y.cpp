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
typedef long double ld;
typedef pair<ll,ll> ii;
const ll MAXN=15;

ld cost[1ll<<MAXN];
ld dp[2][1ll<<MAXN];

int main(){FIN;
	ll n,d; cin>>n>>d;
	vector<ll>a(n);
	ld avg=0;
	fore(i,0,n)cin>>a[i],avg+=a[i];
	//cout<<avg<<"\n";
	avg*=(1.0/ld(d));
	//cout<<avg<<"\n";
	fore(mk,0,1ll<<n){
		ld sum=0;
		//cout<<mk<<": ";
		fore(i,0,n)if((1ll<<i)&mk)sum+=a[i];//cout<<i<<" ";}
		cost[mk]=(1.0/ld(d))*(sum-avg)*(sum-avg);
		//cout<<"= "<<cost[mk]<<"\n";
	}
	fore(i,0,2)fore(j,0,1ll<<MAXN)dp[i][j]=1e30;
	dp[0][0]=0;
	fore(i,1,d+1)fore(mk,0,1ll<<n){
		dp[i%2][mk]=1e30;
		for (ll sb=0;sb=(sb-mk)&mk;)
			dp[i%2][mk]=min(dp[i%2][mk],dp[(i+1)%2][mk^sb]+cost[sb]);
		//cout<<i<<" "<<mk<<": "<<dp[i%2][mk]<<"\n";
	}
	cout<<fixed<<setprecision(15);
	cout<<dp[d%2][(1ll<<n)-1]<<"\n";
	return 0;
}
