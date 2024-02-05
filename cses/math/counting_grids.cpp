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
const ll MOD=1e9+7;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	e%=MOD-1;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	ll b=(n/2)*((n+1)/2);
	ll c4=fpow(2,b+n%2);
	ll c2=(fpow(2,2*b+n%2)-c4+MOD)%MOD*fpow(2,MOD-2)%MOD;
	ll c1=(fpow(2,n*n)-c4-2*c2+3*MOD)%MOD*fpow(4,MOD-2)%MOD;
	//cout<<c1<<" "<<c2<<" "<<c4<<"\n";
	ll res=(c1+c2+c4)%MOD;
	cout<<res<<"\n";
	return 0;
}
