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
const ll MOD=1000000007;

ll fact[1005];

void f(ll n){
	fact[0]=1;
	fore(i,1,n)fact[i]=fact[i-1]*i%MOD;
}

ll bin_pow(ll a, ll e){
	if(e<=0)return 1;
	ll ret=1;
	if(e%2)ret=a;
	if(e>1){
		ll b=bin_pow(a,e/2);
		ret=ret*b%MOD*b%MOD;
	}
	ret%=MOD;
	return ret;
}

/*ll inv(ll a){
	return bin_pow(a,MOD-2);
}*/

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[m];
	ll w[m+1];
	fore(i,0,m)cin>>a[i],a[i]--;
	sort(a,a+m);
	w[0]=a[0];
	fore(i,1,m)w[i]=a[i]-a[i-1]-1;
	w[m]=n-a[m-1]-1;
	f(n);
	ll res=fact[n-m];
	//imp(w);
	//pres;
	fore(i,0,m+1){
		res/=fact[w[i]];
		//cout<<1000000008/inv(fact[w[i]])<<"\n";
		res%=MOD;
		//pres;
	}
	//pres;
	fore(i,1,m){
		res*=bin_pow(2,a[i]-a[i-1]-2);
		//cout<<bin_pow(2,a[i]-a[i-1]-2)<<"\n";
		res%=MOD;
	}
	pres;
	return 0;
}
