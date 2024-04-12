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
const ll MAXV=2e7+5;
ll pf[MAXV];

void criba(){
	fore(i,2,MAXV)if(!pf[i])for(ll j=0;j<MAXV;j+=i)pf[j]++;
}

vector<ll> divs(ll x){
	vector<ll>ret;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0)ret.pb(i),ret.pb(x/i);
		if(i*i==x)ret.pop_back();
	}
	return ret;
}
int main(){FIN;
	criba();
	ll t; cin>>t;
	while(t--){
		ll c,d,x; cin>>c>>d>>x;
		ll res=0;
		for(auto g:divs(x)){
			if((x/g+d)%c)continue;
			ll m=(x/g+d)/c;
			//cout<<g<<": "<<m<<": "<<pf[m]<<": "<<(1ll<<pf[m])<<"\n";
			res+=1ll<<pf[m];
		}
		cout<<res<<"\n";
	}
	return 0;
}
