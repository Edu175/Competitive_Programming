#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define dfore(i,a,b) for(ll i=(b)-1;i>=a;--i)
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
ld dp[1ll<<MAXN];

int main(){FIN;
	ll n,d; cin>>n>>d;
	vector<ll>a(n);
	ld avg=0;
	fore(i,0,n)cin>>a[i],avg+=a[i];
	avg*=(1.0/ld(d));
	cout<<fixed<<setprecision(15);
	//cout<<avg<<"\n";
	fore(mk,0,1ll<<n){
		ld sum=0;
		//cout<<mk<<": ";
		fore(i,0,n)if((1ll<<i)&mk)sum+=a[i];//cout<<i<<" ";}
		cost[mk]=(sum-avg)*(sum-avg);
		//if(mk==16)cout<<"= "<<cost[mk]<<"\n";
	}
	fore(j,0,1ll<<MAXN)dp[j]=1e30;
	dp[0]=0;
	fore(i,0,d){dfore(mk,0,1ll<<n){
		dp[mk]+=cost[0];
		for(ll sb=mk;sb;sb=(sb-1)&mk)//cout<<mk<<"-->"<<(mk^sb)<<"\n",
			dp[mk]=min(dp[mk],dp[mk^sb]+cost[sb]);
	}
	//cout<<dp[(1ll<<n)-1]/ld(d)<<"\n";
	}
	cout<<dp[(1ll<<n)-1]/ld(d)<<"\n";
	return 0;
}
