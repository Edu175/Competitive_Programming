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
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll N=20;

ii dp[1<<N];

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	dp[0]={1,0};
	fore(mk,1,1<<n){
		ii &res=dp[mk];
		res={n+5,0};
		fore(i,0,n)if((mk>>i)&1){
			ii p=dp[mk^(1<<i)];
			ii resi=p;
			if(p.snd+a[i]>x)resi.fst++,resi.snd=min(resi.snd,a[i]);
			else resi.snd+=a[i];
			res=min(res,resi);
		}
		//cout<<mk<<": "<<res.fst<<" "<<res.snd<<"\n";
	}
	cout<<dp[(1<<n)-1].fst<<"\n";
	return 0;
}
