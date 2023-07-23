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
typedef long double ld;
const ll MAXN=105,MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll p[MAXN][25];
//ld pd[MAXN][25];
ll n;
ll dp[MAXN][1ll<<11];
//ld db[MAXN][1ll<<11];

ll f(ll i, ll mk){
	ll &res=dp[i][mk];
	if(res!=-1)return res;
	//ld &r2=db[i][mk];
	if(mk&(1ll<<10)){
		//r2=0;
		return res=0;
	}
	if(i==n){
		//r2=1;
		return res=1;
	}
	res=0;
	fore(k,1,12){
		ll mki=mk;
		fore(j,0,12)if((mk&(1ll<<j))&&j+k<=10)mki|=1ll<<(j+k);
		res=(res+f(i+1,mki)*p[i][k])%MOD;
		//r2+=db[i+1][mki]*pd[i][k];
	}
	//cout<<i<<" "<<mk<<": "<<res<<" ("<<r2<<")\n";
	return res;
}

int main(){FIN;
	cin>>n;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
		fore(j,1,min(a[i]+1,(ll)12)){
			p[i][j]=fpow(a[i],MOD-2);
			if(j==11)p[i][j]=p[i][j]*(a[i]-10)%MOD;
			//pd[i][j]=1.0/a[i];
		}
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		fore(j,0,12)cout<<p[i][j]<<"("<<pd[i][j]<<") ";
		cout<<"\n";
	}*/
	mset(dp,-1);
	ll res=(1-f(0,1)+MOD)%MOD;
	cout<<res<<"\n";
	//cout<<"("<<1-db[0][1]<<")\n";
	return 0;
}
