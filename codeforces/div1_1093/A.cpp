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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll p,q; cin>>p>>q;
		ll s=p+2*q;
		ii res={-1,-1};
		fore(n,1,sqrt(s)+5){
			ll nu=s-n;
			ll de=2*n+1;
			if(nu<=0||nu%de)continue;
			ll m=nu/de;
			assert(m>0);
			ll c=n*(m+1)+(n+1)*m;
			ll d=abs(n-m);
			if(c==s&&p>=d){res={n,m};break;}
		}
		cout<<res.fst;
		if(res.fst!=-1)cout<<" "<<res.snd;
		cout<<"\n";
	}
	return 0;
}
