#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e6+3,MAXV=MOD+5;

ll val[MAXV];

void criba(){
	fore(i,1,MAXV)for(ll j=2*i;j<MAXV;j+=i)val[j]+=i*i;
}

int main(){FIN;
	criba();
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll dp[1<<n];
	fore(mk,0,1<<n){
		ll x=1;
		fore(i,0,n)if(mk&(1<<i))x=x*a[i]%MOD;
		dp[mk]=val[x];
	}
	//imp(dp);
	fore(d,0,n)for(ll mk=(1<<n)-1;mk>=0;mk--){
		if(!(mk&(1<<d)))dp[mk]+=dp[mk^(1<<d)];
	}
	//imp(dp);
	while(q--){
		ll m; cin>>m;
		ll b[m];
		fore(i,0,m)cin>>b[i];
		sort(b,b+m);
		ll p=0,mk=0;
		//imp(a); imp(b);
		fore(i,0,n){
			if(a[i]==b[p])mk|=1<<i,p++;
		}
		//cout<<mk<<"\n";
		cout<<dp[mk]<<" ";
		//cout<<dp[x]<<"\n";
		//cout<<val[a[0]]<<"\n";
	}
	cout<<"\n";
	return 0;
}
