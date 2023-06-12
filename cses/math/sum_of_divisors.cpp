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
const ll MOD=1e9+7;

ll fqrt(ll x){
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}
ll sum(ll n){return n*(n+1)/2%MOD;} //first n
int main(){FIN;
	ll n; cin>>n;
	ll r=fqrt(n);
	ll res=0;
	fore(d,1,r+1){
		ll pre=res;
		res=(res+d*(n/d%MOD))%MOD;
		//cout<<d<<": "<<d*(n/d);
		if(r+1<=n/d)res=(res+sum(n/d%MOD)-sum(r))%MOD;
		//,cout<<" + "<<sum(n/d)<<"-"<<sum(r);
		//cout<<": "<<res-pre<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}


/*int main(){FIN;
	ll n; cin>>n;
	ll res=n*n%MOD;
	vector<ll>divs;
	for(int d=1; d*d<=n; d++){
		if(n%d==0){
			divs.pb(d);
			if(d*d!=n)divs.pb(n/d);
		}
	}
	sort(ALL(divs));
	fore(i,1,SZ(divs)){
		ll x=divs[i]-divs[i-1];
		if(x<=0)continue;
		ll y=x-1;
		if(x&1)y/=2;
		else x/=2;
		res=((res-(x*y%MOD))+MOD)%MOD;
		cout<<divs[i]<<" "<<divs[i-1]<<" "<<x*y<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}*/
