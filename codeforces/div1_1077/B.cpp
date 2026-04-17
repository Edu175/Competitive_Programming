#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=30;

vv get(ll x){
	vv ret;
	ll num=0;
	ret.pb(num);
	for(ll j=B;j>=0;j--){
		ll bo=x>>j&1;
		ll cur=num|(1ll<<j);
		cur-=bo;
		ret.pb(cur);
		num|=bo<<j;
	}
	ret.pb(num);
	sort(ALL(ret));
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		vv a=get(x);
		vv b=get(y);
		ll rp=0,rq=0;
		for(auto _p:a)for(auto q:b){
			// cout<<_p<<" "<<q<<": ";
			ll p=_p&(~q);
			// cout<<p</<" "<<q<<"\n";
			if(abs(p-x)+abs(q-y)<abs(rp-x)+abs(rq-y))rp=p,rq=q;
		}
		assert(!(rp&rq));
		cout<<rp<<" "<<rq<<"\n";
	}
	return 0;
}
