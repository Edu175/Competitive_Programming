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
typedef pair<ll,ll> ii;
const ll MOD=1e9;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fs(ll k, ll n){
	ll res=0;
	if(k==0)res=n;
	if(k==1)res=n*(n+1)/2%MOD;
	else fore(i,1,n+1)res=(res+fpow(i,k))%MOD;
	//cout<<"fs "<<n<<": "<<res<<"\n";
	return res;
}

ll C=1e5;

int main(){FIN;
	ll n,k; cin>>n>>k;
	//cout<<fs(k,n)<<"\n";
	//return 0;
	ll res=0;
	fore(x,1,C){
		ll resi=(fs(k,n/x)-fs(k,n/(x+1))+MOD)*x%MOD;
		res=(res+resi)%MOD;
	}
	fore(d,1,n){
		if(n/d<C)break;
		res=(res+n/d*fpow(d,k))%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
